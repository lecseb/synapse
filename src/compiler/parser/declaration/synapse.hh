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

#ifndef _PARSER_DECLARATION_SYNAPSE_HH_
# define _PARSER_DECLARATION_SYNAPSE_HH_

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
   * @brief Visite an composite node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::composite *node);

  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumeration *node);

  /**
   * @brief Visite an enumerator node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumeration::enumerator *node);

  /**
   * @brief Visite an enumerators node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumeration::enumerators *node);

  /**
   * @brief Visite an function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::function *node);

  /**
   * @brief Visite an function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::function::output *node);

  /**
   * @brief Visite an param node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::function::param *node);

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::include *node);

  /**
   * @brief Visite an service node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::service *node);

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structure *node);

  /**
   * @brief Visite an field node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structure::field *node);

  /**
   * @brief Visite an fields node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structure::fields *node);

private:
  parser::stream& _stream;
};

};  // namespace declaration
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_DECLARATION_SYNAPSE_HH_ */
