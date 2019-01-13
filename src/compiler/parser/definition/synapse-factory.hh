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

#ifndef _PARSER_DEFINITION_SYNAPSE_FACTORY_HH_
# define _PARSER_DEFINITION_SYNAPSE_FACTORY_HH_

# include <string>
# include "ast/synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace definition {

/**
 * @brief Allow the generator to create callback and link depending on
 * the context (the current ast evaluation)
 */
class factory : public ast::visitor {
public:
  /**
   * @brief Constructor
   * @param [in] decls: root of the ast
   */
  explicit factory(ast::decls *decls)
    : _decls(decls) {}

  /**
   * @brief Visite an composite node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::composite *) {
    return std::string();
  }

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
  virtual std::string visite(const ast::enumerator *) {
    return std::string();
  }

  /**
   * @brief Visite an enumerators node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::enumerators *) {
    return std::string();
  }

  /**
   * @brief Visite an field node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::field *) {
    return std::string();
  }

  /**
   * @brief Visite an fields node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::fields *) {
    return std::string();
  }

  /**
   * @brief Visite an function node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::function *) {
    return std::string();
  }

  /**
   * @brief Visite an function output node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::function::out *) {
    return std::string();
  }

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::include *) {
    return std::string();
  }

  /**
   * @brief Visite an param node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::param *) {
    return std::string();
  }

  /**
   * @brief Visite an params node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::params *) {
    return std::string();
  }

  /**
   * @brief Visite an service node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::service *) {
    return std::string();
  }

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::structure *node);

private:
  ast::decls *_decls;
};

};  // namespace definition
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_DEFINITION_SYNAPSE_FACTORY_HH_ */
