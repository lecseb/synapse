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

#include "synapse-interface.hh"
#include "synapse-composite.hh"
#include "synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace ast {

std::string tostring(const google::protobuf::FieldDescriptor::Type& type) {
  switch (type) {
  case google::protobuf::FieldDescriptor::TYPE_DOUBLE:
    return "double";
  case google::protobuf::FieldDescriptor::TYPE_FLOAT:
    return "float";
  case google::protobuf::FieldDescriptor::TYPE_SINT64:
  case google::protobuf::FieldDescriptor::TYPE_SFIXED64:
  case google::protobuf::FieldDescriptor::TYPE_INT64:
    return "int64_t";
  case google::protobuf::FieldDescriptor::TYPE_FIXED64:
  case google::protobuf::FieldDescriptor::TYPE_UINT64:
    return "uint64_t";
  case google::protobuf::FieldDescriptor::TYPE_SFIXED32:
  case google::protobuf::FieldDescriptor::TYPE_SINT32:
  case google::protobuf::FieldDescriptor::TYPE_INT32:
    return "int32_t";
  case google::protobuf::FieldDescriptor::TYPE_FIXED32:
  case google::protobuf::FieldDescriptor::TYPE_UINT32:
    return "uint32_t";
  case google::protobuf::FieldDescriptor::TYPE_BOOL:
    return "uint8_t";
  default:
    break;
  }
  return "unknown";
}

composite::composite(const google::protobuf::FieldDescriptor *desc)
  : _desc(desc),
    _name(desc->name()),
    _type(std::string()) {
  switch (desc->type()) {
  case google::protobuf::FieldDescriptor::TYPE_BYTES:
    /* TODO: should we support the repeated bytes field ? */
    _type = std::string("struct s_synapse_bytes *");
    break;
  case google::protobuf::FieldDescriptor::TYPE_ENUM:
    _type = std::string("enum " + desc->enum_type()->name());
    break;
  case google::protobuf::FieldDescriptor::TYPE_MESSAGE:
    if (desc->message_type()->name() == "void")
      _type = "void";
    else
      _type = std::string("struct " + desc->message_type()->name());
    break;
  case google::protobuf::FieldDescriptor::TYPE_STRING:
    _type = std::string("char *");
    break;
  default:
    if (desc->is_repeated())
      _type = std::string(tostring(desc->type()) + " *");
    else
      _type = std::string(tostring(desc->type()) + " ");
    break;
  }
}

bool composite::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
