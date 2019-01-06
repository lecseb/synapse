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

#include "synapse-field.hh"
#include "adaptor/synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace adaptor {

Field::Field(const FieldDescriptor *desc)
    : _label(desc->label()),
      _name(desc->name()),
      _type_name(desc->type_name()) {
}

std::string Field::accept(Visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace adaptor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
