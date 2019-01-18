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

#ifndef _AST_ENUMERATION_SYNAPSE_DECL_HH_
# define _AST_ENUMERATION_SYNAPSE_DECL_HH_

# include <google/protobuf/descriptor.h>

namespace synapse {
namespace compiler {
namespace ast {
namespace enums {

class visitor;

/**
 * @brief enumeration declaration
 */
class decl {
public:
  /**
   * @brief Destructor
   */
  virtual ~decl() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const = 0;
};

};  // namespace enums
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* !_AST_ENUMERATION_SYNAPSE_DECL_HH_ */
