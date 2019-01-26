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

# include "ast/types/synapse-enumeration.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace types {

enumeration::enumeration(const std::string& name, const std::string& value,
    bool pointer, const ast::enumeration *enume)
  : ast::type(name, value, pointer),
    _enumeration(enume) {
}

type *enumeration::create(const google::protobuf::FieldDescriptor *field,
    const ast::decls& decls) {
  const google::protobuf::EnumDescriptor *desc = field->enum_type();
  const ast::enumeration *instance = nullptr;
  ast::decls::const_iterator it = decls.find(desc->name());
  std::string name = field->name();
  bool pointer = field->is_optional();
  std::string value = enumeration::get_value(field);

  if (it != decls.end()) {
    if (typeid(*it->second) == typeid(ast::enumeration)) {
      instance = dynamic_cast<const ast::enumeration *>(it->second);
      return new types::enumeration(name, value, pointer, instance);
    }
  }
  return nullptr;
}

std::string enumeration::get_value(
    const google::protobuf::FieldDescriptor *field) {
  std::string value = std::string();

  if (field->has_default_value()) {
    value = field->default_value_enum()->name();
  } else {
    value = field->enum_type()->name() + "_last";
  }
  return value;
}

};  // namespace types
};  // namespace ast
};  // namespace compiler
};  // namespace synapse
