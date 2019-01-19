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

#ifndef _PARSER_FILE_DEFINITION_SYNAPSE_HH_
# define _PARSER_FILE_DEFINITION_SYNAPSE_HH_

# include <map>
# include "synapse-interface.hh"
# include "parser/synapse-params.hh"
# include "parser/synapse-stream.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace definition {

class synapse : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] stream: file stream to write the result
   */
  synapse(parser::stream& stream, const params& params);

  /**
   * @brief Destructor
   */
  virtual ~synapse() {}

  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumeration *node);

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structure *node);

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
  const params& _params;
  parser::stream& _stream;
};

};  // namespace definition
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_FILE_DEFINITION_SYNAPSE_HH_ */
