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
class function : public ast::type {
public:
  /**
   * @brief Constructor
   * @param [in] name: name of the type
   * @param [in] function: function linked to the type
   */
  function(const std::string& name, const ast::function *function);

  /**
   * @brief destructor
   */
  virtual ~function() {}

  /**
   * @brief Get the function contained into the type
   * @retun a valid pointer
   */
  virtual const ast::function *get_function() const;

  /**
   * @brief Get the return form of the descriptor
   * @retun a string
   */
  virtual std::string get_type_form() const;

  /**
   * @brief Duplicate the given type
   * @return a valid pointer on success, nullptr on error
   */
  virtual type *duplicate() const;

private:
  const ast::function *_function;
};

};  // namespace types
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_TYPES_SYNAPSE_FUNCTION_HH_ */
