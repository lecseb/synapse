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

#include "synapse-fields.hh"
#include "synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

fields::fields(const Descriptor *desc)
  : _fields(std::map<uint32_t, field *>()) {
  for (int32_t i = 0; i < desc->field_count(); i++) {
    const FieldDescriptor *field_desc = desc->field(i);
    _fields[field_desc->index()] = new field(field_desc);
  }
}

fields::fields(const std::initializer_list<field *>& list) {
  uint32_t index = 0;
  std::initializer_list<field *>::iterator it = list.begin();
  for (index = 0; it != list.end(); it++, index++)
    _fields[index] = (*it);
}

fields::~fields() {
  std::map<uint32_t, field *>::iterator it = _fields.begin();
  for (; it != _fields.end(); it++)
    delete it->second;
}

std::string fields::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
