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

#ifndef _AST_STRUCTURE_SYNAPSE_DECLS_HH_
# define _AST_STRUCTURE_SYNAPSE_DECLS_HH_

# include <map>
# include "synapse-decl.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace structs {

/**
 * @brief Root element of the AST
 */
class decls :
  public std::map<uint32_t, const google::protobuf::FieldDescriptor *>,
  public decl {
public:
  /**
   * @brief destructor
   */
  virtual ~decls() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const = 0;
};

};  // namespace structs
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_STRUCTURE_SYNAPSE_DECLS_HH_ */
