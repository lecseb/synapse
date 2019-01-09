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

#ifndef _AST_SYNAPSE_VISITOR_HH_
# define _AST_SYNAPSE_VISITOR_HH_

# include <string>
# include "synapse-composite.hh"
# include "synapse-decl.hh"
# include "synapse-decls.hh"
# include "synapse-enumeration.hh"
# include "synapse-enumerator.hh"
# include "synapse-enumerators.hh"
# include "synapse-field.hh"
# include "synapse-fields.hh"
# include "synapse-function.hh"
# include "synapse-include.hh"
# include "synapse-param.hh"
# include "synapse-params.hh"
# include "synapse-service.hh"
# include "synapse-structure.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

class visitor {
public:
  /**
   * @brief Visite an composite node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const composite *node) = 0;

  /**
   * @brief Visite an decls node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const decls *node) = 0;

  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const enumeration *node) = 0;

  /**
   * @brief Visite an enumerator node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const enumerator *node) = 0;

  /**
   * @brief Visite an enumerators node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const enumerators *node) = 0;

  /**
   * @brief Visite an field node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const field *node) = 0;

  /**
   * @brief Visite an fields node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const fields *node) = 0;

  /**
   * @brief Visite an function node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const function *node) = 0;

  /**
   * @brief Visite an function output node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const function::out *node) = 0;

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const include *node) = 0;

  /**
   * @brief Visite an param node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const param *node) = 0;

  /**
   * @brief Visite an params node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const params *node) = 0;

  /**
   * @brief Visite an service node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const service *node) = 0;

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const structure *node) = 0;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* _AST_SYNAPSE_VISITOR_HH_ */
