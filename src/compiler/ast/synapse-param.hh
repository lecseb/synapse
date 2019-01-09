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

#ifndef _AST_SYNAPSE_PARAM_HH_
# define _AST_SYNAPSE_PARAM_HH_

# include <string>
# include "synapse-composite.hh"
# include "synapse-node.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class param : public node {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf structure representation
   */
  explicit param(const Descriptor *desc);

  /**
   * @brief Constructor
   */
  param(const std::string& name, composite *type);

  /**
   * @brief destructor
   */
  virtual ~param();

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   */
  virtual std::string accept(visitor *visitor) const;

  /**
   * @brief Get the parameter name
   * @return a string
   */
  const std::string get_name() const {
    return _name;
  }

  /**
   * @brief Get the parameter type
   * @return the param composite
   */
  const composite *get_composite() const {
    return _type;
  }

  /**
   * @brief Generate a new name
   * @return a string
   */
  std::string generate_name() const {
    static uint32_t index = 0;
    return std::string(_name + std::to_string(index));
  }

protected:
  const Descriptor *_desc;
  std::string _name;
  composite *_type;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* _AST_SYNAPSE_PARAMS_HH_ */