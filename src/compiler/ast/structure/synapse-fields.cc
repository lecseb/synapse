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
#include "ast/synapse-adaptor.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace structs {

fields::fields(const google::protobuf::Descriptor *desc) {
  for (int32_t i = 0; i < desc->field_count(); i++) {
    const google::protobuf::FieldDescriptor *field = desc->field(i);
    (*this)[field->index()] = field;
  }
}

bool fields::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace structs
};  // namespace ast
};  // namespace compiler
};  // namespace synapse
