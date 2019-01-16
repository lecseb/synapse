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
  if (node->get_type() == "void")
    _stream << "void";
  else
    _stream << node->get_type() << node->get_name();
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

bool synapse::visite(const ast::enumeration::enumerator *node) {
  _stream << node->get_name() << " = " << std::to_string(node->get_value());
  return true;
}

bool synapse::visite(const ast::enumeration::enumerators *node) {
  bool error = true;

  const std::map<uint32_t, ast::enumeration::enumerator *>& enums =
    node->get_elements();
  std::map<uint32_t, ast::enumeration::enumerator *>::const_iterator it;
  if (it != enums.end()) {
    error &= it->second->accept(this);
    for (it++; it != enums.end(); it++) {
      _stream << "," << stream::endl;
      error &= it->second->accept(this);
    }
    _stream << stream::endl;
  }
  return error;
}

bool synapse::visite(const ast::function *node) {
  bool error = true;

  error &= node->get_return_type()->accept(this);
  _stream << node->get_name() << "(";
  error &= node->get_param()->accept(this);
  _stream << ")";
  return error;
}

bool synapse::visite(const ast::function::output *node) {
  _stream << node->get_type();
  return true;
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

bool synapse::visite(const ast::function::param *node) {
  if (node->get_type() == "void ")
    _stream << "void";
  else
    _stream << node->get_type() << node->get_name();
  return true;
}

bool synapse::visite(const ast::structure *node) {
  _stream << "struct " << node->get_name();
  return true;
}

};  // namespace definition
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
