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

#include "synapse-list.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace types {

list::list(const std::string& name,
    const google::protobuf::FieldDescriptor::Type& target_type,
    const ast::structure *str)
  : types::structure(name, str),
    _target_type(target_type) {
}

type *list::create(const google::protobuf::FieldDescriptor *field,
  const std::map<std::string, decl *>& decls) {
  std::map<std::string, decl *>::const_iterator it = decls.end();

  it = decls.find("s_synapse_list");
  if (it != decls.end()) {
    const ast::decl *decl = it->second;
    if (typeid(*decl) == typeid(ast::structure)) {
      const ast::structure *s = dynamic_cast<const ast::structure *>(decl);
      return new types::structure(field->name(), s);
    }
  }
  return nullptr;
}

};  // namespace types
};  // namespace ast
};  // namespace compiler
};  // namespace synapse
