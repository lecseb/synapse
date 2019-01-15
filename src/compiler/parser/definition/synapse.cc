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

#include "synapse.hh"
#include "synapse-error.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace definition {

synapse::synapse(stream& stream, const params& params)
  : _params(params),
    _stream(stream) {
}

bool synapse::visite(const ast::composite *node) {
  _stream << ast::composite::to_string(node);
  if (node->get_name().size())
    _stream << " " << node->get_name() << " *";
  return true;
}

bool synapse::visite(const ast::enumeration *node) {
  _stream << "enum " << node->get_name();
  _stream << node->get_name() << " {" << stream::endl;
  _stream.indent();
  bool error = node->get_enumerators()->accept(this);
  _stream.outdent();
  _stream << "}";

  return error;
}

bool synapse::visite(const ast::enumerator *node) {
  _stream << node->get_name() << " = " << std::to_string(node->get_value());
  return true;
}

bool synapse::visite(const ast::enumerators *node) {
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

bool synapse::visite(const ast::function *node) {
  bool error = true;

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
  _stream << ")";
  return error;
}

bool synapse::visite(const ast::include *node) {
  std::string name = std::string();

  switch (node->get_type()) {
  case ast::include::e_type_libc:
    name = node->get_name();
    break;
  case ast::include::e_type_protobuf:
    name += std::string(strip_suffix(node->get_name(), ".proto") +
      ".synapse.h");
    break;
  case ast::include::e_type_synapse:
    name = std::string("synapse/" + node->get_name());
    break;
  }

  _stream << "# include <" << name << ">";
  return true;
}

bool synapse::visite(const ast::param *node) {
  const ast::composite *cmp = node->get_composite();
  bool error = cmp->accept(this);
  _stream << node->get_name();
  return error;
}

bool synapse::visite(const ast::params *node) {
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

bool synapse::visite(const ast::structure *node) {
  _stream << "struct " << node->get_name();
  return true;
}

};  // namespace definition
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
