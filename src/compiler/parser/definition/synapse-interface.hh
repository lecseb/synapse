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

#ifndef _PARSER_FILE_DEFINITION_SYNAPSE_INTERFACE_HH_
# define _PARSER_FILE_DEFINITION_SYNAPSE_INTERFACE_HH_

# include "synapse-error.hh"
# include "ast/synapse-visitor.hh"
# include "ast/service/allocator/synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace definition {

class interface : public ast::visitor, public ast::svcs::alloc::visitor {
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
  virtual bool visite(const ast::error *node) {
    error::get_instance() << node->get();
    return false;
  }

  /**
   * @brief Visite an error node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::svcs::alloc::error *node) {
    error::get_instance() << node->get();
    return false;
  }

  /**
   * @brief Visite an include node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::include *) {
    /* nothing to do here */
    return true;
  }

  /**
   * @brief Visite an include node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::svcs::alloc::allocator *) {
    /* nothing to do here */
    return true;
  }
};

};  // namespace definition
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_FILE_DEFINITION_SYNAPSE_INTERFACE_HH_ */
