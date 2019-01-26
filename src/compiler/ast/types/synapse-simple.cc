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

#include "synapse-simple.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace types {

simple::simple(const std::string& name, const std::string& value, bool pointer,
  const google::protobuf::FieldDescriptor::Type& field_type)
  : type(name, value, pointer),
    _type(field_type) {
}

std::string simple::get_value(
    const google::protobuf::FieldDescriptor *field) {
  switch (field->type()) {
  case google::protobuf::FieldDescriptor::TYPE_DOUBLE:
    return field->has_default_value() ?
      std::to_string(field->default_value_double()) :
      std::string("0");
  case google::protobuf::FieldDescriptor::TYPE_FLOAT:
    return field->has_default_value() ?
      std::to_string(field->default_value_float()) :
      std::string("0");
  case google::protobuf::FieldDescriptor::TYPE_SINT64:
  case google::protobuf::FieldDescriptor::TYPE_SFIXED64:
  case google::protobuf::FieldDescriptor::TYPE_INT64:
    return field->has_default_value() ?
      std::to_string(field->default_value_int64()) :
      std::string("0");
  case google::protobuf::FieldDescriptor::TYPE_FIXED64:
  case google::protobuf::FieldDescriptor::TYPE_UINT64:
    return field->has_default_value() ?
      std::to_string(field->default_value_uint64()) :
      std::string("0");
  case google::protobuf::FieldDescriptor::TYPE_SFIXED32:
  case google::protobuf::FieldDescriptor::TYPE_SINT32:
  case google::protobuf::FieldDescriptor::TYPE_INT32:
    return field->has_default_value() ?
      std::to_string(field->default_value_int32()) :
      std::string("0");
  case google::protobuf::FieldDescriptor::TYPE_FIXED32:
  case google::protobuf::FieldDescriptor::TYPE_UINT32:
    return field->has_default_value() ?
      std::to_string(field->default_value_uint32()) :
      std::string("0");
  case google::protobuf::FieldDescriptor::TYPE_BOOL:
    return field->has_default_value() ?
      std::to_string(field->default_value_bool()) :
      std::string("false");
  case google::protobuf::FieldDescriptor::TYPE_STRING:
    return field->has_default_value() ?
      field->default_value_string() :
      std::string("nullptr");
  default:
    return std::string("unknown");
  }
}

const google::protobuf::FieldDescriptor::Type& simple::get_type() const {
  return _type;
}

std::string simple::get_type_form() const {
  switch (_type) {
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
  case google::protobuf::FieldDescriptor::TYPE_STRING:
    return "char *";
  default:
    return std::string();
  }
}

};  // namespace types
};  // namespace ast
};  // namespace compiler
};  // namespace synapse
