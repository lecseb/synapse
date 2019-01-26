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

#ifndef _AST_FUNCTIONS_SYNAPSE_ALLOCATOR_HH_
# define _AST_FUNCTIONS_SYNAPSE_ALLOCATOR_HH_

# include <string>
# include "synapse-stream.hh"
# include "ast/functions/synapse-dup.hh"
# include "ast/functions/synapse-free.hh"
# include "ast/functions/synapse-new.hh"

namespace synapse {
namespace compiler {
namespace ast {

class visitor {
public:
  /**
   * @brief Visite a dup function node
   * @param [in] stream: file stream
   * @param [in] node: node to visite
   */
  virtual void visite(stream& stream, const function_dup *node) = 0;

  /**
   * @brief Visite a free function node
   * @param [in] stream: file stream
   * @param [in] node: node to visite
   */
  virtual void visite(stream& stream, const function_free *node) = 0;

  /**
   * @brief Visite a new function node
   * @param [in] stream: file stream
   * @param [in] node: node to visite
   */
  virtual void visite(stream& stream, const function_new *node) = 0;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_FUNCTIONS_SYNAPSE_ALLOCATOR_HH_ */
