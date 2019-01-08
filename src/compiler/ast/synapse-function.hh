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

#ifndef _AST_SYNAPSE_FUNCTION_HH_
# define _AST_SYNAPSE_FUNCTION_HH_

# include <list>
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

/**
 * @brief C enumeration representation
 */
class Function : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf enumeration representation
   */
  explicit Function(const ServiceDescriptor *desc);

  /**
   * @brief Constructor
   * @param [in] name: name of the function
   * @param [in] inputs: list of argument
   * @param [in] out: output type
   * @param [in] comment: commentary of the function
   */
  Function(const std::string& name, const std::list<Field *>& inputs,
    Field *out, const std::string& comment = std::string());

  /**
   * @brief Destructor
   */
  virtual ~Function() {}

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor);

  /**
   * @brief Get an iterator over the first element contained in the argument
   * list
   * @return a valid iterator
   */
  std::list<Field *>::const_iterator get_fields_begin() const {
    return _inputs.begin();
  }

  /**
   * @brief Get an iterator over the last element contained in the argument
   * list
   * @return a valid iterator
   */
  std::list<Field *>::const_iterator get_fields_end() const {
    return _inputs.end();
  }

  /**
   * @brief Get the comment of the function
   */
  const std::string& get_comment() const {
    return _comment;
  }

  /**
   * @brief Get the function name
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

  /**
   * @brief Get the output field of the function
   * @return a string
   */
  Field *get_output() const {
    return _output;
  }

private:
  std::string _comment;
  std::list<Field *> _inputs;
  std::string _name;
  Field *_output;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_AST_SYNAPSE_FUNCTION_HH_ */
