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
# include "synapse-decl.hh"
# include "synapse-enumeration.hh"
# include "synapse-error.hh"
# include "synapse-include.hh"
# include "synapse-structure.hh"
# include "service/allocator/synapse-allocator.hh"

namespace synapse {
namespace compiler {
namespace ast {

class visitor {
public:
  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const enumeration *node) = 0;

  /**
   * @brief Visite an error node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const error *node) = 0;

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const include *node) = 0;

  /**
   * @brief Visite an service node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const svcs::alloc::allocator *node) = 0;

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const structure *node) = 0;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_VISITOR_HH_ */
