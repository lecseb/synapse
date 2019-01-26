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

#ifndef _AST_FUNCTIONS_SYNAPSE_NEW_HH_
# define _AST_FUNCTIONS_SYNAPSE_NEW_HH_

# include <string>
# include "ast/synapse-function.hh"

namespace synapse {
namespace compiler {
namespace ast {

class visitor;

/**
 * @brief function description
 */
class function_new : public ast::function {
public:
  /**
   * @brief Constructor
   * @param [in] name: name of the structure
   * @param [in] args: argument of the function
   * @param [in] out: return of the function
   */
  function_new(const std::string& name, const arguments& args, type *out)
    : ast::function(name, args, out) {}

  /**
   * @brief destructor
   */
  virtual ~function_new() {}
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_FUNCTIONS_SYNAPSE_NEW_HH_ */
