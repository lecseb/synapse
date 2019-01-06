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

#include "synapse-ast.hh"
#include "adaptor/synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace adaptor {

Ast::Ast(const FileDescriptor *desc)
    : _enums(std::list<Enum *>()),
      _structs(std::list<Struct *>()) {
  for (int32_t i = 0; i < desc->enum_type_count(); i++)
    _enums.push_back(new Enum(desc->enum_type(i)));
  for (int32_t i = 0; i < desc->message_type_count(); i++)
    _structs.push_back(new Struct(desc->message_type(i)));
}

Ast::~Ast() {
  std::list<Enum *>::iterator it_enum = _enums.begin();
  for (; it_enum != _enums.end(); it_enum++)
    delete *it_enum;
  std::list<Struct *>::iterator it_struct = _structs.begin();
  for (; it_struct != _structs.end(); it_struct++)
    delete *it_struct;
}

std::string Ast::accept(Visitor *visitor) const {
  return visitor->visite(this);
}

std::list<Enum *>::const_iterator Ast::get_enum_begin() const {
  return _enums.begin();
}

std::list<Enum *>::const_iterator Ast::get_enum_end() const {
  return _enums.end();
}

std::list<Struct *>::const_iterator Ast::get_struct_begin() const {
  return _structs.begin();
}

std::list<Struct *>::const_iterator Ast::get_struct_end() const {
  return _structs.end();
}

};  // namespace adaptor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
