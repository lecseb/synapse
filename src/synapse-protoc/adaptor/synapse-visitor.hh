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

#ifndef _ADAPTOR_SYNAPSE_VISITOR_HH_
# define _ADAPTOR_SYNAPSE_VISITOR_HH_

# include <map>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-ast.hh"
# include "synapse-enum.hh"
# include "synapse-field.hh"
# include "synapse-function.hh"
# include "synapse-label.hh"
# include "synapse-struct.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace adaptor {

class Visitor {
public:
  /**
   * @brief Visite an Ast node
   * @param [in] ast: ast node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const Ast *ast) = 0;

  /**
   * @brief Visite an Enumeration node
   * @param [in] enumeration: enumeration node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const Enum *enumeration) = 0;

  /**
   * @brief Visite a field node
   * @param [in] field: field node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const Field *field) = 0;

  /**
   * @brief Visite a function node
   * @param [in] field: field node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const Function *function) = 0;

  /**
   * @brief Visite a label node
   * @param [in] label: label node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const Label *label) = 0;

  /**
   * @brief Visite a structure node
   * @param [in] structure: structure node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const Struct *structure) = 0;
};

};  // namespace adaptor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_ADAPTOR_SYNAPSE_VISITOR_HH_ */
