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

#ifndef _PARSER_FILE_DECLARATION_SYNAPSE_HH_
# define _PARSER_FILE_DECLARATION_SYNAPSE_HH_

# include "synapse-interface.hh"
# include "parser/synapse-stream.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace declaration {

class synapse : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] stream: file stream to write the result
   */
  explicit synapse(parser::stream& stream);

  /**
   * @brief Destructor
   */
  virtual ~synapse() {}

  /**
   * @brief Visite a duplicate allocation function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::svcs::alloc::function_dup *node);

  /**
   * @brief Visite a free allocation function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::svcs::alloc::function_free *node);

  /**
   * @brief Visite a new allocation function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::svcs::alloc::function_new *node);

private:
  parser::stream& _stream;
};

};  // namespace declaration
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_FILE_DECLARATION_SYNAPSE_HH_ */
