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

#ifndef _PARSER_FILE_DECLARATION_SYNAPSE_INTERFACE_HH_
# define _PARSER_FILE_DECLARATION_SYNAPSE_INTERFACE_HH_

# include "synapse-error.hh"
# include "ast/structure/synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace declaration {

class interface : public ast::structs::visitor {
public:
  /**
   * @brief Destructor
   */
  virtual ~interface() {}

  /**
   * @brief Visite an error node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structs::error *node) {
    error::get_instance() << node->get();
    return false;
  }
};

};  // namespace declaration
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_FILE_DECLARATION_SYNAPSE_INTERFACE_HH_ */
