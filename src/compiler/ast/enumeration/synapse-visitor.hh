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

#ifndef _AST_ENUMERATION_SYNAPSE_VISITOR_HH_
# define _AST_ENUMERATION_SYNAPSE_VISITOR_HH_

# include "synapse-enumeration.hh"
# include "synapse-enumerators.hh"
# include "synapse-error.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace enums {

class visitor {
public:
  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const enumeration *node) = 0;

  /**
   * @brief Visite an enumeration list of enumerator node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const enumerators *node) = 0;

  /**
   * @brief Visite an error node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const error *node) = 0;
};

};  // namespace enums
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* !_AST_ENUMERATION_SYNAPSE_VISITOR_HH_ */
