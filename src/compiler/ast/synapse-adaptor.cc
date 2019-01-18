
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

#include "synapse-adaptor.hh"

namespace synapse {
namespace compiler {
namespace ast {

const std::string adaptor::unknown = std::string("unknown");

std::string adaptor::enumerator_tostring(
    const google::protobuf::EnumValueDescriptor *desc) {
  return std::string(desc->name() + " = " + std::to_string(desc->number()));
}

std::string adaptor::field_tostring(
    const google::protobuf::FieldDescriptor *field) {
  std::string name = field->name();

  if (field->is_repeated())
    return std::string("struct s_synapse_list *" + field->name());

  switch (field->type()) {
  case google::protobuf::FieldDescriptor::TYPE_BYTES:
    return std::string("struct s_synapse_bytes *" + field->name());
  case google::protobuf::FieldDescriptor::TYPE_ENUM: {
    const google::protobuf::EnumDescriptor *sub = field->enum_type();
    return std::string("enum " + sub->name() +
      (field->is_optional() ? " *" : " ") + name);
  }
  case google::protobuf::FieldDescriptor::TYPE_MESSAGE: {
    const google::protobuf::Descriptor *sub = field->message_type();
    return std::string("struct " + sub->name() + " *" + name);
  }
  case google::protobuf::FieldDescriptor::TYPE_STRING:
    return std::string("char *" + field->name());
  default:
    if (field->is_optional())
      return std::string(_convert_type(field->type()) + " *" + field->name());
    else
      return std::string(_convert_type(field->type()) + " " + field->name());
  }
}

std::string adaptor::param_tostring(const google::protobuf::Descriptor *desc) {
  std::string param = std::string();

  if (desc->field_count() > 0) {
    const google::protobuf::FieldDescriptor *field = desc->field(0);
    param += field_tostring(field);
    for (int i = 1; i < desc->field_count(); i++) {
      param += ", ";
      param += field_tostring(field);
    }
    return param;
  }
  return adaptor::unknown;
}

std::string adaptor::return_tostring(const google::protobuf::Descriptor *desc) {
  if (desc->name() == "void")
    return "void ";
  return std::string("struct " + desc->name() + " *");
}

std::string adaptor::_convert_type(
    const google::protobuf::FieldDescriptor::Type& type) {
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
    return adaptor::unknown;
  }
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
