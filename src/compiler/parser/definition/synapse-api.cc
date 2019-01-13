/** This file is part of synapse.
 *
 * synapse is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * synapse is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with synapse.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "synapse-api.hh"
#include "synapse-factory.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace definition {

static const std::string& _g_name = "synapse_out";
static const std::string& _g_opt = "--synapse_out";
static const std::string& _g_brief = "generate synapse.h/synapse.c";

const interface::option& api::get_option() {
  static interface::option g_option = interface::option(
    "synapse_out",
    "--synapse_out",
    "generate synapse.h/synapse.c");
  return g_option;
}

bool api::parse(const google::protobuf::FileDescriptor *desc) {
  ast::decls *decls = new ast::decls(desc);
  if (_export)
    decls->add_decl(new ast::include("synapse/export.h"));
  factory factory(decls);
  bool error = decls->accept(&factory);
  error &= decls->accept(this);
  delete decls;
  return error;
}

bool api::visite(const ast::composite *node) {
  _stream << node->get_type();
  if (node->get_name().size())
    _stream << " " << node->get_name();
  _stream << (node->is_pointer() ? " *" : " ");
  return true;
}

bool api::visite(const ast::decls *node) {
  bool error = true;
  const std::list<ast::decl *>& decls = node->get_declarations();

  std::list<ast::decl *>::const_iterator decl = decls.begin();
  for (; decl != decls.end(); decl++) {
    error &= (*decl)->accept(this);
    _stream << stream::endl;
  }
  _stream << stream::endl;
  return error;
}

bool api::visite(const ast::enumeration *node) {
  bool error = true;

  _stream << stream::endl;
  _stream << (_export ? "synapse_export enum " : "enum ");
  _stream << node->get_name() << " {" << stream::endl;
  _stream.indent();
  error &= node->get_enumerators()->accept(this);
  _stream.outdent();
  _stream << "};";
  return error;
}

bool api::visite(const ast::enumerator *node) {
  _stream << node->get_name() << " = " << std::to_string(node->get_value());
  return true;
}

bool api::visite(const ast::enumerators *node) {
  bool error = true;
  const std::map<uint32_t, ast::enumerator *>& enums = node->get_enumerators();
  std::map<uint32_t, ast::enumerator *>::const_iterator enum_it = enums.begin();

  if (enum_it != enums.end()) {
    error &= enum_it->second->accept(this);
    for (enum_it++; enum_it != enums.end(); enum_it++) {
      _stream << "," << stream::endl;
      error &= enum_it->second->accept(this);
    }
    _stream << stream::endl;
  }
  return error;
}

bool api::visite(const ast::field *node) {
  bool error = true;
  ast::composite *type = node->get_type();

  error &= type->accept(this);
  _stream << node->get_name();
  return error;
}

bool api::visite(const ast::fields *node) {
  bool error = true;
  const std::map<uint32_t, ast::field *>& fields = node->get_fields();

  std::map<uint32_t, ast::field *>::const_iterator field = fields.begin();
  for (; field != fields.end(); field++) {
    error &= field->second->accept(this);
    _stream << ";" << stream::endl;
  }
  return error;
}

bool api::visite(const ast::function *node) {
  bool error = true;

  _stream << stream::endl;
  _stream << (_export ? "synapse_export " : "");
  if (node->get_return_type())
    error &= node->get_return_type()->accept(this);
  else
    _stream << "void ";
  _stream << node->get_name() << "(";
  if (node->get_params()) {
    _stream << stream::endl;
    _stream.indent();
    error &= node->get_params()->accept(this);
    _stream.outdent();
  } else {
    _stream << "void";
  }
  _stream << ");";
  return error;
}

bool api::visite(const ast::function::out *node) {
  bool error = true;

  const ast::composite *cmp = node->get_composite();
  error &= cmp->accept(this);
  return error;
}

bool api::visite(const ast::include *node) {
  _stream << "# include <" << node->get_name() << ">";
  return true;
}

bool api::visite(const ast::param *node) {
  bool error = true;

  const ast::composite *cmp = node->get_composite();
  error &= cmp->accept(this);
  _stream << "msg";
  return error;
}

bool api::visite(const ast::params *node) {
  bool error = true;
  const std::list<ast::param *>& params = node->get_params();
  std::list<ast::param *>::const_iterator param = params.begin();

  if (param != params.end()) {
    error &= (*param)->accept(this);
    for (param++; param != params.end(); param++) {
      _stream << "," << stream::endl;
      error &= (*param)->accept(this);
    }
  }
  return error;
}

bool api::visite(const ast::service *service) {
  bool error = true;
  const std::list<ast::function *>& functions = service->get_functions();

  std::list<ast::function *>::const_iterator function = functions.begin();
  for (; function != functions.end(); function++)
    error &= (*function)->accept(this);
  return error;
}

bool api::visite(const ast::structure *node) {
  bool error = true;

  _stream << stream::endl;
  _stream << (_export ? "synapse_export struct " : "struct ");
  _stream << node->get_name() << " {" << stream::endl;
  _stream.indent();
  error &= node->get_fields()->accept(this);
  _stream.outdent();
  _stream << "};";
  return error;
}

};  // namespace definition
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
