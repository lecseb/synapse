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

#ifndef _AST_TYPES_SYNAPSE_FUNCTION_HH_
# define _AST_TYPES_SYNAPSE_FUNCTION_HH_

# include <string>
# include "ast/synapse-function.hh"
# include "ast/synapse-type.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace types {

/**
 * @brief structure description
 */
class simple : public ast::type {
public:
  /**
   * @brief Constructor
   * @param [in] name: name of the type
   * @param [in] value: value of the type
   * @param [in] pointer: is this type a pointer ?
   * @param [in] type: field type description
   */
  simple(const std::string& name, const std::string& value, bool pointer,
    const google::protobuf::FieldDescriptor::Type& type);

  /**
   * @brief destructor
   */
  virtual ~simple() {}

  /**
   * @brief Get the type contained into the type
   * @retun a valid pointer
   */
  virtual const google::protobuf::FieldDescriptor::Type& get_type() const;

  /**
   * @brief Get the return form of the descriptor
   * @retun a string
   */
  virtual std::string get_type_form() const;

  /**
   * @brief Get the value from the field descriptor
   * @return a string
   */
  static std::string get_value(const google::protobuf::FieldDescriptor *field);

private:
  google::protobuf::FieldDescriptor::Type _type;
};

};  // namespace types
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_TYPES_SYNAPSE_SIMPLE_HH_ */
