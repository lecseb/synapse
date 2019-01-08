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

#include "synapse-struct.hh"
#include "synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

Struct::Struct(const std::string& package, const Descriptor *desc)
    : _fields(std::map<uint32_t, Field *>()),
      _name(std::string("s_" + package + "_" + desc->name())) {
  for (int32_t i = 0; i < desc->field_count(); i++) {
    const FieldDescriptor *field = desc->field(i);
    _fields[field->index()] = new Field(field);
  }
}

Struct::~Struct() {
  std::map<uint32_t, Field *>::iterator it = _fields.begin();
  for (; it != _fields.end(); it++)
    delete it->second;
}

std::string Struct::accept(Visitor *visitor) {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
