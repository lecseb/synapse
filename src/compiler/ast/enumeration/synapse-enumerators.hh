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

#ifndef _AST_ENUMERATION_SYNAPSE_ENUMERATORS_HH_
# define _AST_ENUMERATION_SYNAPSE_ENUMERATORS_HH_

# include <map>
# include <string>
# include "synapse-decls.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace enums {

/**
 * @brief enumerator list
 */
class enumerators : public decls {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf enumeration descriptor structure
   */
  explicit enumerators(const google::protobuf::EnumDescriptor *desc);

  /**
   * @brief destructor
   */
  virtual ~enumerators() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const;
};

};  // namespace enums
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* !_AST_ENUMERATION_SYNAPSE_ENUMERATORS_HH_ */
