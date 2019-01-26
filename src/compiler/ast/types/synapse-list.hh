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

#ifndef _AST_TYPES_SYNAPSE_LIST_HH_
# define _AST_TYPES_SYNAPSE_LIST_HH_

# include <map>
# include <string>
# include "ast/synapse-structure.hh"
# include "ast/synapse-type.hh"
# include "ast/types/synapse-structure.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace types {

/**
 * @brief enumeration description
 */
class list : public types::structure {
public:
  /**
   * @brief Constructor
   */
  list(const std::string& name,
    const google::protobuf::FieldDescriptor::Type& type,
    const ast::structure *structure);

  /**
   * @brief Create an enumeration type from the protobuf descriptor
   * @param [in] desc: protobuf enumeration instance
   * @param [in] decls: declaration list
   * @return a type
   */
  static type *create(const google::protobuf::FieldDescriptor *desc,
    const std::map<std::string, decl *>& decls);

  /**
   * @brief Is the contained type is a pointer ?
   * @return true or false
   */
  google::protobuf::FieldDescriptor::Type target_type() const {
    return _target_type;
  }

private:
  google::protobuf::FieldDescriptor::Type _target_type;
};

};  // namespace types
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_TYPES_SYNAPSE_LIST_HH_ */
