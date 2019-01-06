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

#include <string>
#include "synapse-field.hh"
#include "synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

static std::string _get_default_value(const FieldDescriptor *desc) {
  switch (desc->type()) {
  case FieldDescriptor::TYPE_DOUBLE:
    return std::to_string(desc->default_value_double());
  case FieldDescriptor::TYPE_FLOAT:
    return std::to_string(desc->default_value_float());
  case FieldDescriptor::TYPE_INT64:
    return std::to_string(desc->default_value_int64());
  case FieldDescriptor::TYPE_UINT64:
    return std::to_string(desc->default_value_uint64());
  case FieldDescriptor::TYPE_INT32:
    return std::to_string(desc->default_value_int32());
  case FieldDescriptor::TYPE_UINT32:
    return std::to_string(desc->default_value_uint32());
  case FieldDescriptor::TYPE_BOOL:
    return std::to_string(desc->default_value_bool());
  case FieldDescriptor::TYPE_STRING:
    return desc->default_value_string();
  case FieldDescriptor::TYPE_BYTES:
  case FieldDescriptor::TYPE_MESSAGE:
    return std::string("NULL");
  case FieldDescriptor::TYPE_GROUP:
  case FieldDescriptor::TYPE_ENUM:
  case FieldDescriptor::TYPE_SFIXED32:
  case FieldDescriptor::TYPE_SFIXED64:
  case FieldDescriptor::TYPE_SINT32:
  case FieldDescriptor::TYPE_SINT64:
  case FieldDescriptor::TYPE_FIXED64:
  case FieldDescriptor::TYPE_FIXED32:
    break;
  }
  return std::string();
}

Field::Field(const FieldDescriptor *desc)
  : _def_value(_get_default_value(desc)),
    _is_repeated(desc->is_repeated()),
    _name(desc->name()),
    _type(desc->type()) {
}

std::string Field::accept(Visitor *visitor) {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
