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

#ifndef _PARSER_FILE_SYNAPSE_HEADER_HH_
# define _PARSER_FILE_SYNAPSE_HEADER_HH_

# include <map>
# include <string>
# include "synapse-interface.hh"
# include "parser/definition/synapse-interface.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace file {

class header : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] params: user params
   * @param [in] stream: file stream to generate the file
   * @param [in] definition: definition generator
   * @note header instance take the ownership of the stream and definition
   */
  header(const params& params, stream *stream,
    definition::interface *defition);

  /**
   * @brief Destructor
   */
  virtual ~header();

  /**
   * @brief Parse the entire tree
   * @param [in] node: node to parse
   * @return true on success, false otherwise
   */
  virtual bool parse(const ast::decls *node);

  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumeration *node);

  /**
   * @brief Visite an error node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::error *node);

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

  /**
   * @brief Visite an service node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::svcs::alloc::allocator *node);

private:
  definition::interface *_definition;
  std::map<std::string, bool> _services;
};

};  // namespace file
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_FILE_SYNAPSE_HEADER_HH_ */
