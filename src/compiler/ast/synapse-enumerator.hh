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

#ifndef _AST_SYNAPSE_ENUMERATOR_HH_
# define _AST_SYNAPSE_ENUMERATOR_HH_

# include <string>
# include "synapse-interface.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class enumerator : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf enumerator descriptor
   */
  explicit enumerator(const google::protobuf::EnumValueDescriptor *desc)
    : _name(desc->name()),
      _value(desc->number()) {}

  /**
   * @brief Constructor
   * @param [in] name: name of the enumerator
   * @param [in] value: value of the enumerator
   */
  enumerator(const std::string& name, uint32_t value)
    : _desc(NULL),
      _name(name),
      _value(value) {}

  /**
   * @brief destructor
   */
  virtual ~enumerator() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   */
  virtual std::string accept(visitor *visitor) const;

  /**
   * @brief Get the declaration name
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

  /**
   * @brief Get the declaration value
   * @return a string
   */
  uint32_t get_value() const {
    return _value;
  }

private:
  const google::protobuf::EnumValueDescriptor *_desc;
  std::string _name;
  uint32_t _value;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_ENUMERATOR_HH_ */
