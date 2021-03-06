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

#ifndef _AST_SYNAPSE_DECL_HH_
# define _AST_SYNAPSE_DECL_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-stream.hh"

namespace synapse {
namespace compiler {
namespace ast {

class visitor;

/**
 * @brief declaration
 */
class decl {
public:
  /**
   * @brief destructor
   */
  virtual ~decl() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] stream: file stream
   * @param [in] visitor: visitor to browse
   * @return true or false depending on the visite algorithm
   */
  virtual void accept(stream& stream, visitor *visitor) const = 0;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_DECL_HH_ */
