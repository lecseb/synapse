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

#ifndef _AST_SYNAPSE_COMPOSITE_HH_
# define _AST_SYNAPSE_COMPOSITE_HH_

# include <string>
# include "synapse-interface.hh"

namespace synapse {
namespace compiler {
namespace ast {

class composite : public interface {
public:
  /**
   * @brief Constructor
   */
  explicit composite(const google::protobuf::FieldDescriptor *desc);

  /**
   * @brief Constructor
   */
  composite(const google::protobuf::FieldDescriptor::Type& type,
      const std::string& name, bool pointer = false)
    : _desc(NULL),
      _is_pointer(pointer),
      _name(name),
      _type(composite::to_string(type)) {}

  /**
   * @brief Destructor
   */
  virtual ~composite() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   */
  virtual std::string accept(visitor *visitor) const;

  /**
   * @brief Get the declared name
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

  /**
   * @brief Get the declared type
   */
  const std::string& get_type() const {
    return _type;
  }

  bool is_pointer() const {
    return _is_pointer;
  }

  /**
   * @brief Convert a type from protobuf to a string
   * @param [in] type: type to convert
   * @return a string
   */
  static std::string to_string(
    const google::protobuf::FieldDescriptor::Type& type);

private:
  const google::protobuf::FieldDescriptor *_desc;
  bool _is_pointer;
  std::string _name;
  std::string _type;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* !_AST_SYNAPSE_COMPOSITE_HH_ */
