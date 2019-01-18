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

#ifndef _AST_SERVICE_ALLOCATOR_SYNAPSE_VISITOR_HH_
# define _AST_SERVICE_ALLOCATOR_SYNAPSE_VISITOR_HH_

# include "synapse-dup.hh"
# include "synapse-error.hh"
# include "synapse-free.hh"
# include "synapse-new.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace svcs {
namespace alloc {

class visitor {
public:
  /**
   * @brief Visite an error node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const error *node) = 0;

  /**
   * @brief Visite a duplicate allocation function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const function_dup *node) = 0;

  /**
   * @brief Visite a free allocation function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const function_free *node) = 0;

  /**
   * @brief Visite a new allocation function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const function_new *node) = 0;
};

};  // namespace alloc
};  // namespace svcs
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* !_AST_SERVICE_ALLOCATOR_SYNAPSE_VISITOR_HH_ */
