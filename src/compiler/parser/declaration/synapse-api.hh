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

#ifndef _PARSER_DECLARATION_SYNAPSE_API_HH_
# define _PARSER_DECLARATION_SYNAPSE_API_HH_

# include <map>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-declaration.hh"
# include "ast/synapse-decls.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace declaration {

class api : public declaration {
public:
  /**
   * @brief Constructor
   * @param [in] options: options given by the user
   * @param [in] name: name of the file to file to generate
   * @param [in] out: output file structure
   */
  api(const std::map<std::string, std::string>& params,
      const std::string& name,
      google::protobuf::compiler::OutputDirectory *out);

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
   * @brief Order the parsing and start the ast construction
   * @param [in] desc: protobuf file structure
   * @return true on success, false otherwise
   */
  virtual bool parse(const google::protobuf::FileDescriptor *desc);

  /**
   * @brief Visite an composite node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::composite *node);

  /**
   * @brief Visite an decls node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::decls *node);

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
  virtual bool visite(const ast::enumerator *) {
    return true;
  }

  /**
   * @brief Visite an enumerators node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::enumerators *) {
    return true;
  }

  /**
   * @brief Visite an field node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::field *node);

  /**
   * @brief Visite an fields node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::fields *node);

  /**
   * @brief Visite an function node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::function *) {
    return true;
  }

  /**
   * @brief Visite an function output node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::function::out *) {
    return true;
  }

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::include *) {
    return true;
  }

  /**
   * @brief Visite an param node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::param *) {
    return true;
  }

  /**
   * @brief Visite an params node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::params *) {
    return true;
  }

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::service *) {
    return true;
  }

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual bool visite(const ast::structure *node);

private:
  ast::decls *_decls;
  std::string _include_path;
};

};  // namespace declaration
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_DECLARATION_SYNAPSE_API_HH_ */
