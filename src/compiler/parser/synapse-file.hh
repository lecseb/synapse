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

#ifndef _PARSER_SYNAPSE_FILE_HH_
# define _PARSER_SYNAPSE_FILE_HH_

# include <map>
# include <string>
# include "synapse-params.hh"
# include "synapse-stream.hh"
# include "ast/synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace parser {

class file : public ast::visitor {
public:
  /**
   * @brief Constructor
   * @param [in] stream: file stream to generate the file
   */
  file(const params& params, stream& stream)
    : _params(params),
      _stream(stream) {}

  /**
   * @brief Destructor
   */
  virtual ~file() {}

  /**
   * @brief Visite an composite node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::composite *) {
    return true;
  }

  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumeration *node) = 0;

  /**
   * @brief Visite an enumerator node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumeration::enumerator *) {
    return true;
  }

  /**
   * @brief Visite an enumerators node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumeration::enumerators *) {
    return true;
  }

  /**
   * @brief Visite an function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::function *node) = 0;

  /**
   * @brief Visite an function ouput node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::function::output *) {
    return true;
  }

  /**
   * @brief Visite an params node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::function::param *) {
    return true;
  }

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::include *node) = 0;

  /**
   * @brief Visite an service node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::service *node) {
    bool error = true;

    const ast::service::map& functions = node->get_elements();
    ast::service::const_iterator it = functions.begin();
    for (; it != functions.end(); it++) {
      const ast::function *function = it->second;
      error &= function->accept(this);
      _stream << stream::endl;
    }
    return error;
  }

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structure *node) = 0;

  /**
   * @brief Visite an field node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structure::field *) {
    return true;
  }

  /**
   * @brief Visite an fields node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structure::fields *) {
    return true;
  }

protected:
  const std::map<std::string, std::string>& _params;
  stream& _stream;
};

};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_SYNAPSE_FILE_HH_ */
