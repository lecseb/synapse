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

#ifndef _AST_SYNAPSE_VISITOR_HH_
# define _AST_SYNAPSE_VISITOR_HH_

# include <string>
# include "synapse-stream.hh"
# include "ast/synapse-enumeration.hh"
# include "ast/synapse-error.hh"
# include "ast/synapse-include.hh"
# include "ast/synapse-structure.hh"

namespace synapse {
namespace compiler {
namespace ast {

class visitor {
public:
  /**
   * @brief Visite an enumeration node
   * @param [in] stream: file stream
   * @param [in] node: node to visite
   */
  virtual void visite(stream& stream, const enumeration *node) = 0;

  /**
   * @brief Visite an error node
   * @param [in] stream: file stream
   * @param [in] node: node to visite
   */
  virtual void visite(stream& stream, const error *node) = 0;

  /**
   * @brief Visite an include node
   * @param [in] stream: file stream
   * @param [in] node: node to visite
   */
  virtual void visite(stream& stream, const include *node) = 0;

  /**
   * @brief Visite an structure node
   * @param [in] stream: file stream
   * @param [in] node: node to visite
   */
  virtual void visite(stream& stream, const structure *node) = 0;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_VISITOR_HH_ */
