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

#ifndef _AST_SYNAPSE_FIELD_HH_
# define _AST_SYNAPSE_FIELD_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

class Visitor;

class Field : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf structure field representation
   */
  explicit Field(const FieldDescriptor *desc);

  /**
   * @brief Destructor
   */
  virtual ~Field() {}

  /**
   * @brief Get the default value
   * @return a string
   */
  const std::string& get_def_value() const {
    return _def_value;
  }

  /**
   * @brief Field is repeated or not
   * @return 0 if not, 1 if it's repeated
   */
  uint8_t is_repeated() const {
    return _is_repeated;
  }

  /**
   * @brief Get the name of the field
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

  /**
   * @brief Get the type
   * @return a type
   */
  enum FieldDescriptor::Type get_type() const {
    return _type;
  }

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor);

private:
  std::string _def_value;
  uint8_t _is_repeated;
  std::string _name;
  enum FieldDescriptor::Type _type;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_AST_SYNAPSE_FIELD_HH_ */
