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
#include "adaptor/synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace adaptor {

Struct::Struct(const Descriptor *desc)
    : _fields(std::map<std::string, Field *>()),
      _name(desc->name()) {
  for (int32_t i = 0; i < desc->field_count(); i++) {
    const FieldDescriptor *field = desc->field(i);
    _fields[field->name()] = new Field(field);
  }
}

Struct::~Struct() {
  std::map<std::string, Field *>::iterator it = _fields.begin();
  for (; it != _fields.end(); it++)
    delete it->second;
}

std::string Struct::accept(Visitor *visitor) const {
  return visitor->visite(this);
}

const std::string& Struct::get_name() const {
  return _name;
}

std::map<std::string, Field *>::const_iterator Struct::get_field_begin() const {
  return _fields.begin();
}

std::map<std::string, Field *>::const_iterator Struct::get_field_end() const {
  return _fields.end();
}

};  // namespace adaptor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
