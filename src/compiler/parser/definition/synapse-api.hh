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

#ifndef _PARSER_DEFINITION_SYNAPSE_API_HEADER_HH_
# define _PARSER_DEFINITION_SYNAPSE_API_HEADER_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-definition.hh"
# include "ast/synapse-decls.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace definition {

class api : public definition {
public:
  /**
   * @brief Constructor
   * @param [in] options: options given by the user
   * @param [in] name: name of the file to file to generate
   * @param [in] out: output file structure
   */
  api(const std::string& name,
    google::protobuf::compiler::OutputDirectory *out)
    : definition(name, ".synapse.h", out) {
  }

  /**
   * @brief Destructor
   */
  virtual ~api() {}

  /**
   * @brief Get the parser option
   * @return an option
   */
  static const interface::option& get_option();

  /**
   * @brief Visite an composite node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::composite *node);

  /**
   * @brief Visite an decls node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::decls *node);

  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::enumeration *node);

  /**
   * @brief Visite an enumerator node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::enumerator *node);

  /**
   * @brief Visite an enumerators node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::enumerators *node);

  /**
   * @brief Visite an field node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::field *node);

  /**
   * @brief Visite an fields node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::fields *node);

  /**
   * @brief Visite an function node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::function *node);

  /**
   * @brief Visite an function output node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::function::out *node);

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::include *node);

  /**
   * @brief Visite an param node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::param *node);

  /**
   * @brief Visite an params node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::params *node);

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::service *node);

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::structure *node);
};

};  // namespace definition
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_DEFINITION_SYNAPSE_API_HEADER_HH_ */
