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

#ifndef _AST_SYNAPSE_INCLUDE_HH_
# define _AST_SYNAPSE_INCLUDE_HH_

# include <string>
# include "synapse-decl.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief declaration
 */
class include : public decl {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf file descriptor
   */
  explicit include(const google::protobuf::FileDescriptor *desc);

  /**
   * @brief Constructor
   * @param [in] name: name of the include
   */
  explicit include(const std::string& name);

  /**
   * @brief destructor
   */
  virtual ~include() {}

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
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_INCLUDE_HH_ */
