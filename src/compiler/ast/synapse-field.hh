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
# include "synapse-composite.hh"
# include "synapse-interface.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class field : public interface {
public:
  /**
   * @brief Constructor
   */
  explicit field(const google::protobuf::FieldDescriptor *desc)
    : field(desc->name(), new composite(desc)) {
    _desc = desc;
  }

  /**
   * @brief Constructor
   */
  field(const std::string& name, composite *type)
    : _desc(NULL),
      _name(name),
      _type(type) {}

  /**
   * @brief destructor
   */
  virtual ~field() {}

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
   * @return a type
   */
  composite *get_type() const {
    return _type;
  }

private:
  const google::protobuf::FieldDescriptor *_desc;
  std::string _name;
  composite *_type;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_FIELD_HH_ */
