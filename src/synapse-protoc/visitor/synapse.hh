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

#ifndef _VISITOR_SYNAPSE_HH_
# define _VISITOR_SYNAPSE_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-header.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace visitor {
namespace header {

class Synapse : public Header {
public:
  /**
   * @brief Constructor
   * @param [in] name: file name
   * @param [in] out: protobuf out structure
   * @param [in] extension: extension of the file to write
   */
  Synapse(const std::string& name, OutputDirectory *out,
    const std::string& extension);

  /**
   * @brief Destructor
   */
  virtual ~Synapse() {}

  /**
   * @brief Visite an Ast node
   * @param [in] ast: ast node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Ast *ast);

  /**
   * @brief Visite an Enumeration node
   * @param [in] enumeration: enumeration node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Enum *enumeration);

  /**
   * @brief Visite a field node
   * @param [in] field: field node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Field *field);

  /**
   * @brief Visite a function node
   * @param [in] field: field node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Function *function);

  /**
   * @brief Visite a label node
   * @param [in] label: label node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Label *label);

  /**
   * @brief Visite a structure node
   * @param [in] structure: structure node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Struct *structure);
};

};  // namespace header
};  // namespace visitor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_VISITOR_SYNAPSE_HH_ */
