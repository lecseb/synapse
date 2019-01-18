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
#include "ast/synapse-adaptor.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace definition {

synapse::synapse(stream& stream, const params& params)
  : _params(params),
    _stream(stream) {
}

bool synapse::visite(const ast::enumeration *node) {
  _stream << "enum " << node->get_name() << " {" << stream::endl;
  _stream.indent();
  ast::enumeration::const_iterator it = node->begin();
  if (it != node->end()) {
    _stream << ast::adaptor::enumerator_tostring(it->second);
    for (it++; it != node->end(); it++) {
      _stream << "," << stream::endl;
      _stream << ast::adaptor::enumerator_tostring(it->second);
    }
    _stream << stream::endl;
  }
  _stream.outdent();
  _stream << "}";

  return true;
}

bool synapse::visite(const ast::structure *node) {
  _stream << "struct " << node->get_name();
  return true;
}

bool synapse::visite(const ast::svcs::alloc::function_dup *node) {
  const google::protobuf::Descriptor *ins = node->get_input();
  const google::protobuf::Descriptor *out = node->get_output();

  _stream << "/**" << stream::endl;
  _stream << " * @brief duplicate a specific structure of type ";
  _stream << ins->name() << stream::endl;
  _stream << " * @return a valid pointer on success, NULL on error";
  _stream << stream::endl << " */" << stream::endl;
  _stream << ast::adaptor::return_tostring(out) << node->get_name()  << "(";
  _stream << "struct " << ins->name() << " *msg";
  _stream << ")";

  return true;
}

bool synapse::visite(const ast::svcs::alloc::function_free *node) {
  const google::protobuf::Descriptor *ins = node->get_input();
  const google::protobuf::Descriptor *out = node->get_output();

  _stream << "/**" << stream::endl;
  _stream << " * @brief deallocate a specific structure of type ";
  _stream << ins->name() << stream::endl;
  _stream << " */" << stream::endl;
  _stream << ast::adaptor::return_tostring(out) << node->get_name()  << "(";
  _stream << "struct " << ins->name() << " *msg";
  _stream << ")";

  return true;
}

bool synapse::visite(const ast::svcs::alloc::function_new *node) {
  const google::protobuf::Descriptor *ins = node->get_input();
  const google::protobuf::Descriptor *out = node->get_output();

  _stream << "/**" << stream::endl;
  _stream << " * @brief allocate a new structure of type " << ins->name();
  _stream << stream::endl;
  _stream << " * @return a valid pointer on success, NULL on error";
  _stream << stream::endl;
  _stream << " */" << stream::endl;

  _stream << ast::adaptor::return_tostring(out) << node->get_name() << "(";
  if (ins) {
    _stream.indent();
    _stream << ast::adaptor::field_tostring(ins->field(0));
    for (int i = 1; i < ins->field_count(); i++) {
      _stream << "," << stream::endl;
      _stream << ast::adaptor::field_tostring(ins->field(i));
    }
    _stream.outdent();
  }
  _stream << ")";

  return true;
}

};  // namespace definition
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
