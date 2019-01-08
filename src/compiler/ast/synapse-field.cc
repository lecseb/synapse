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

std::string type_tostring(enum FieldDescriptor::Type type) {
  switch (type) {
  case FieldDescriptor::TYPE_DOUBLE:
    return "double";
  case FieldDescriptor::TYPE_FLOAT:
    return "float";
  case FieldDescriptor::TYPE_INT64:
    return "int64_t";
  case FieldDescriptor::TYPE_UINT64:
    return "uint64_t";
  case FieldDescriptor::TYPE_INT32:
    return "int32_t";
  case FieldDescriptor::TYPE_BOOL:
    return "uint8_t";
  case FieldDescriptor::TYPE_STRING:
    return "char";
  case FieldDescriptor::TYPE_MESSAGE:
    return "struct";
  case FieldDescriptor::TYPE_BYTES:
    return "struct s_sypase_bytes";
  case FieldDescriptor::TYPE_UINT32:
    return "uint32_t";
  case FieldDescriptor::TYPE_ENUM:
    return "enum";
  default:
    break;
  }
  return "unknown";
}

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
  default:
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

Field::Field(const Field *field)
  : _def_value(field->_def_value),
    _is_repeated(field->_is_repeated),
    _name(field->_name),
    _type(field->_type) {
}

Field::Field(const std::string& name, enum FieldDescriptor::Type type,
    bool isrepeat, const std::string& value)
  : _def_value(value),
    _is_repeated(isrepeat),
    _name(name),
    _type(type) {
}

std::string Field::accept(Visitor *visitor) {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
