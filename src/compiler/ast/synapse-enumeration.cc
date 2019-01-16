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

#include "synapse-enumeration.hh"
#include "synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace ast {

enumeration::enumeration(const google::protobuf::EnumDescriptor *desc)
  : decl(desc->name()),
    _desc(desc),
    _enumerators(new enumerators(desc)) {
}

enumeration::~enumeration() {
  delete _enumerators;
}

bool enumeration::accept(visitor *visitor) const {
  return visitor->visite(this);
}

enumeration::enumerator::enumerator(
  const google::protobuf::EnumValueDescriptor *desc)
  : _desc(desc) {
}

bool enumeration::enumerator::accept(visitor *visitor) const {
  return visitor->visite(this);
}

enumeration::enumerators::enumerators(
  const google::protobuf::EnumDescriptor *desc)
  : elements<enumerator>() {
  for (int32_t i = 0; i < desc->value_count(); i++) {
    const google::protobuf::EnumValueDescriptor *enum_desc = desc->value(i);
    _elements[enum_desc->number()] = new enumerator(desc->value(i));
  }
}

bool enumeration::enumerators::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
