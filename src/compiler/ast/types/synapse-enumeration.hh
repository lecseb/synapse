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

#ifndef _AST_TYPES_SYNAPSE_ENUMERATION_HH_
# define _AST_TYPES_SYNAPSE_ENUMERATION_HH_

# include <map>
# include <string>
# include "ast/synapse-enumeration.hh"
# include "ast/synapse-type.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace types {

/**
 * @brief enumeration description
 */
class enumeration : public ast::type {
public:
  /**
   * @brief Constructor
   * @param [in] name: name of the type
   * @param [in] value: default value of the type
   * @param [in] enumeration: enumeration linked to the type
   */
  enumeration(const std::string& name, const std::string& value, bool pointer,
    const ast::enumeration *enumeration);

  /**
   * @brief destructor
   */
  virtual ~enumeration() {}

  /**
   * @brief Create a new enumeration type
   * @param [in] field: field descriptor
   * @param [in] decls: declaration container
   * @return a valid pointer on success, nullptr on error
   */
  ast::type *create(const google::protobuf::FieldDescriptor *field,
    const ast::decls& decls);

  /**
   * @brief Get the structure contained into the type
   * @retun a valid pointer
   */
  virtual const ast::enumeration *get_enumeration() const {
    return _enumeration;
  }

  /**
   * @brief Get the return form of the descriptor
   * @retun a string
   */
  virtual std::string get_type_form() const {
    return std::string("enum ") + _enumeration->get_name();
  }

  /**
   * @brief Get the value from the field descriptor
   * @return a string
   */
  static std::string get_value(const google::protobuf::FieldDescriptor *field);

private:
  std::string _name;
  const ast::enumeration *_enumeration;
};

};  // namespace types
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_TYPES_SYNAPSE_ENUMERATION_HH_ */
