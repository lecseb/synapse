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

#include "synapse-structure.hh"
#include "synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace ast {

structure::structure(const google::protobuf::Descriptor *desc)
  : decl(desc->name()),
    _desc(desc),
    _fields(new fields(desc)) {
}

structure::~structure() {
  delete _fields;
}

bool structure::accept(visitor *visitor) const {
  return visitor->visite(this);
}

structure::field::field(const google::protobuf::FieldDescriptor *desc)
  : _desc(desc),
    _composite(new composite(desc)) {
}

structure::field::~field() {
  delete _composite;
}

bool structure::field::accept(visitor *visitor) const {
  return visitor->visite(this);
}

structure::fields::fields(const google::protobuf::Descriptor *desc)
  : elements<field>() {
  for (int32_t i = 0; i < desc->field_count(); i++) {
    const google::protobuf::FieldDescriptor *field_desc = desc->field(i);
    _elements[field_desc->index()] = new field(field_desc);
  }
}

bool structure::fields::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
