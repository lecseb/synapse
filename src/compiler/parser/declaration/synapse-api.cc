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

namespace synapse {
namespace compiler {
namespace parser {
namespace declaration {

static const std::string& _g_name = "synapse_out";
static const std::string& _g_opt = "--synapse_out";
static const std::string& _g_brief = "generate synapse.c";

const interface::option& api::get_option() {
  static interface::option g_option = interface::option(
    "synapse_out",
    "--synapse_out",
    "--synapse_opt",
    "generate synapse.c");
  return g_option;
}

api::api(const std::map<std::string, std::string>& params,
    const std::string& name, google::protobuf::compiler::OutputDirectory *out)
  : declaration(name, ".synapse.c", out) {
  std::map<std::string, std::string>::const_iterator it;

  it = params.find("synapse_out");
  _include_path = (it != params.end()) ?
    it->second : ".";
}

bool api::parse(const google::protobuf::FileDescriptor *desc) {
  std::string temp = std::string(strip_suffix(_stream.get_name(),
    ".synapse.c") + ".synapse.h");
  _stream << "#include \"";
  if (_include_path != ".")
    _stream << _include_path << "/";
  _stream << temp << "\"" << stream::endl;

  _decls = new ast::decls(desc);
  bool error = _decls->accept(this);
  delete _decls;
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

bool api::visite(const ast::enumeration *) {
  return true;
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

bool api::visite(const ast::structure *node) {
  bool error = true;

  _stream << stream::endl;
  _stream << "struct " << node->get_name() << " {" << stream::endl;
  _stream.indent();
  error &= node->get_fields()->accept(this);
  _stream.outdent();
  _stream << "};";

  return error;
}

};  // namespace declaration
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
