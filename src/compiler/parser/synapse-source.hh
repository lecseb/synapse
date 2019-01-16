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

#ifndef _PARSER_SYNAPSE_SOURCE_HH_
# define _PARSER_SYNAPSE_SOURCE_HH_

# include <map>
# include <string>
# include "synapse-file.hh"
# include "synapse-params.hh"
# include "synapse-stream.hh"
# include "declaration/synapse-interface.hh"
# include "definition/synapse-interface.hh"

namespace synapse {
namespace compiler {
namespace parser {

class source : public file {
public:
  /**
   * @brief Constructor
   * @brief Constructor
   * @param [in] params: user params
   * @param [in] stream: file stream to generate the file
   * @param [in] definition: definition generator
   * @param [in] declaration: declaration generator
   * @note header instance take the ownership of the stream and definition
   */
  source(const params& params, stream *stream,
    definition::interface *definition, declaration::interface *declaration);

  /**
   * @brief Destructor
   */
  virtual ~source();

  /**
   * @brief Parse a decls node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool parse(const ast::decls *node);

  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumeration *) {
    return true;
  }

  /**
   * @brief Visite an function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::function *node);

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::include *node);

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structure *node);

private:
  declaration::interface *_declaration;
  definition::interface *_definition;
};

};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_SYNAPSE_SOURCE_HH_ */
