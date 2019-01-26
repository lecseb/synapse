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

#include "ast/synapse-type.hh"
#include "ast/types/synapse-enumeration.hh"
#include "ast/types/synapse-list.hh"
#include "ast/types/synapse-simple.hh"
#include "ast/types/synapse-structure.hh"

namespace synapse {
namespace compiler {
namespace ast {

type::type(const std::string& name, const std::string& val, bool pointer)
  : _is_pointer(pointer),
    _name(name),
    _value(val) {
}

type *type::create(const google::protobuf::FieldDescriptor *field,
  const ast::decls& decls) {
  const ast::enumeration *enum_instance = nullptr;
  const ast::structure *struct_instance = nullptr;

  if (field->is_repeated()) {
    struct_instance = decls.get_structure("s_synapse_list");
    if (!struct_instance)
      goto error;
    return new types::list(field->name(), field->type(), struct_instance);
  } else {
    std::string name = field->name(), value = std::string();
    bool pointer = field->is_optional();

    switch (field->type()) {
    case google::protobuf::FieldDescriptor::TYPE_ENUM:
      enum_instance = decls.get_enumeration(field->enum_type()->name());
      if (!enum_instance)
	goto error;
      value = types::enumeration::get_value(field);
      return new types::enumeration(name, value, pointer, enum_instance);
    case google::protobuf::FieldDescriptor::TYPE_MESSAGE:
      struct_instance = decls.get_structure(field->message_type()->name());
      if (!struct_instance)
	goto error;
      return new types::structure(name, struct_instance);
    case google::protobuf::FieldDescriptor::TYPE_BYTES:
      struct_instance = decls.get_structure("s_synapse_bytes");
      if (!struct_instance)
	goto error;
      return new types::structure(field->name(), struct_instance);
    default:
      value = types::simple::get_value(field);
      return new types::simple(name, value, pointer, field->type());
    }
  }
error:
  return nullptr;
}

std::string type::get_return_form(bool constify) const {
  if (_is_pointer)
    return std::string(constify ? "const " : "") + get_type_form() +
      std::string(" *");
  return get_type_form() + std::string(" ");
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
