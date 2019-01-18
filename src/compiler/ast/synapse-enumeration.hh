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

#ifndef _AST_SYNAPSE_ENUMERATION_HH_
# define _AST_SYNAPSE_ENUMERATION_HH_

# include <map>
# include <string>
# include "synapse-decl.hh"

namespace synapse {
namespace compiler {
namespace ast {

class visitor;

/**
 * @brief enumeration element
 */
class enumeration :
  public std::map<uint32_t, const google::protobuf::EnumValueDescriptor *>,
  public ast::decl {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf enumeration descriptor
   */
  explicit enumeration(const google::protobuf::EnumDescriptor *desc);

  /**
   * @brief destructor
   */
  virtual ~enumeration() {}

  /**
   * @brief Accept function of the visitor design* pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const;

  /**
   * @brief Get the name of the enumeration
   * @return a string
   */
  const std::string& get_name() const {
    return _desc->name();
  }

private:
  const google::protobuf::EnumDescriptor *_desc;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_ENUMERATION_HH_ */
