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

#include "synapse-composite.hh"
#include "synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

std::string composite::to_string(const FieldDescriptor::Type& type) {
  switch (type) {
  case FieldDescriptor::TYPE_DOUBLE:
    return "double";
  case FieldDescriptor::TYPE_FLOAT:
    return "float";
  case FieldDescriptor::TYPE_SINT64:
  case FieldDescriptor::TYPE_SFIXED64:
  case FieldDescriptor::TYPE_INT64:
    return "int64_t";
  case FieldDescriptor::TYPE_FIXED64:
  case FieldDescriptor::TYPE_UINT64:
    return "uint64_t";
  case FieldDescriptor::TYPE_SFIXED32:
  case FieldDescriptor::TYPE_SINT32:
  case FieldDescriptor::TYPE_INT32:
    return "int32_t";
  case FieldDescriptor::TYPE_FIXED32:
  case FieldDescriptor::TYPE_UINT32:
    return "uint32_t";
  case FieldDescriptor::TYPE_BOOL:
    return "uint8_t";
  case FieldDescriptor::TYPE_STRING:
    return "char";
  case FieldDescriptor::TYPE_MESSAGE:
  case FieldDescriptor::TYPE_BYTES:
    return "struct";
  case FieldDescriptor::TYPE_ENUM:
    return "enum";
  default:
    break;
  }
  return "unknown";
}

composite::composite(const FieldDescriptor *desc)
  : _desc(desc),
    _is_pointer(desc->is_repeated()),
    _name(std::string()),
    _type(composite::to_string(desc->type())) {
  switch (desc->type()) {
  case FieldDescriptor::TYPE_BYTES:
    /* TODO: should we support the repeated bytes field ? */
    _name = "s_synapse_bytes";
    _is_pointer = true;
    break;
  case FieldDescriptor::TYPE_ENUM:
    _name = desc->enum_type()->name();
    break;
  case FieldDescriptor::TYPE_MESSAGE:
    _name = desc->message_type()->name();
    _is_pointer = true;
    break;
  default:
    /* the other type doesn't have composite name */
    break;
  }
}

std::string composite::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google