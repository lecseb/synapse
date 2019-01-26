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

#ifndef _AST_SYNAPSE_TYPE_HH_
# define _AST_SYNAPSE_TYPE_HH_

# include <map>
# include <string>
# include <google/protobuf/descriptor.h>
# include "ast/synapse-decl.hh"
# include "ast/synapse-decls.hh"

namespace synapse {
namespace compiler {
namespace ast {

class type {
public:
  /**
   * @brief Constructor
   * @param [in] name: name of the field
   * @param [in] val: default value of the type (if define)
   * @param [in] is_pointer: is the type a pointer ?
   */
  type(const std::string& name, const std::string& val, bool pointer);

  /**
   * @brief Destructor
   */
  virtual ~type() {}

  /**
   * @brief Create any type from the protobuf descriptor
   * @param [in] desc: protobuf enumeration instance
   * @param [in] decls: declaration list
   * @return a type
   */
  static type *create(const google::protobuf::FieldDescriptor *desc,
    const ast::decls& decls);

  /**
   * @brief Get the default value
   * @return a string
   */
  virtual const std::string& get_default_value() const {
    return _value;
  }

  /**
   * @brief Get the field form of the descriptor
   * @retun a string
   */
  virtual std::string get_field_form(bool constify) const {
    return get_return_form(constify) + _name;
  }

  /**
   * @brief Get the type name
   * @return a string
   */
  virtual const std::string& get_name() const {
    return _name;
  }

  /**
   * @brief Get the return form of the descriptor
   * @retun a string
   */
  virtual std::string get_return_form(bool constify) const;

  /**
   * @brief Get the return form of the descriptor
   * @retun a string
   */
  virtual std::string get_type_form() const = 0;

  /**
   * @brief Is this type a pointer ?
   * @return true or false
   */
  bool is_pointer() const {
    return _is_pointer;
  }

protected:
  bool _is_pointer;
  std::string _name;
  std::string _value;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* !_AST_SYNAPSE_TYPE_HH_ */
