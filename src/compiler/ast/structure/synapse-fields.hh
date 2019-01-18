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

#ifndef _AST_STRUCTURE_SYNAPSE_FIELDS_HH_
# define _AST_STRUCTURE_SYNAPSE_FIELDS_HH_

# include <map>
# include <string>
# include "synapse-decls.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace structs {

class visitor;

/**
 * @brief field list
 */
class fields : public decls {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf descriptor structure
   */
  explicit fields(const google::protobuf::Descriptor *desc);

  /**
   * @brief destructor
   */
  virtual ~fields() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const;
};

};  // namespace structs
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_STRUCTURE_SYNAPSE_FIELDS_HH_ */
