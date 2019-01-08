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

#ifndef _AST_SYNAPSE_STRUCT_HH_
# define _AST_SYNAPSE_STRUCT_HH_

# include <map>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"
# include "synapse-field.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

class Visitor;

class Struct : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] package: package name of the structure
   * @param [in] desc: protobuf structure representation
   */
  Struct(const std::string& package, const Descriptor *desc);

  /**
   * @brief Destructor
   */
  virtual ~Struct();

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor);

  /**
   * @brief Get an iterator over the first field contained in the enum
   * @return a valid iterator
   */
  std::map<uint32_t, Field *>::const_iterator get_fields_begin() const {
    return _fields.begin();
  }

  /**
   * @brief Get an iterator over the last field contained in the enum
   * @return a valid iterator
   */
  std::map<uint32_t, Field *>::const_iterator get_fields_end() const {
    return _fields.end();
  }

  /**
   * @brief Get the structure name
   * @return return a string
   */
  const std::string& get_name() const {
    return _name;
  }

private:
  std::map<uint32_t, Field *> _fields;
  std::string _package;
  std::string _name;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_AST_SYNAPSE_STRUCT_HH_ */
