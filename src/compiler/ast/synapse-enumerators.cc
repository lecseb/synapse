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

#include "synapse-enumerators.hh"
#include "synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

enumerators::enumerators(const EnumDescriptor *desc)
  : _enumerators(std::map<uint32_t, enumerator *>()) {
  for (int32_t i = 0; i < desc->value_count(); i++) {
    const EnumValueDescriptor *enum_desc = desc->value(i);
    _enumerators[enum_desc->number()] = new enumerator(enum_desc);
  }
}

enumerators::enumerators(const std::initializer_list<enumerator *>& list)
  : _enumerators(std::map<uint32_t, enumerator *>()) {
  std::initializer_list<enumerator *>::iterator it = list.begin();
  for (; it != list.end(); it++)
    _enumerators[(*it)->get_value()] = *it;
}

enumerators::~enumerators() {
  std::map<uint32_t, enumerator *>::iterator it = _enumerators.begin();
  for (; it != _enumerators.end(); it++)
    delete it->second;
}

std::string enumerators::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
