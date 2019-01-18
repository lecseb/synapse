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

#ifndef _AST_STRUCTURE_SYNAPSE_STRUCTURE_HH_
# define _AST_STRUCTURE_SYNAPSE_STRUCTURE_HH_

# include <map>
# include <string>
# include "ast/synapse-decl.hh"
# include "ast/structure/synapse-fields.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class structure : public ast::decl {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf structure descriptor
   */
  explicit structure(const google::protobuf::Descriptor *desc);

  /**
   * @brief destructor
   */
  virtual ~structure();

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(ast::visitor *visitor) const;

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(structs::visitor *visitor) const;

  /**
   * @brief Get all fields contained into the structure
   * @return a valid pointer
   */
  const structs::fields *get_fields() const {
    return _fields;
  }

  /**
   * @brief Get the name of the enumeration
   * @return a string
   */
  const std::string& get_name() const {
    return _desc->name();
  }

private:
  const google::protobuf::Descriptor *_desc;
  structs::fields *_fields;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_STRUCTURE_SYNAPSE_STRUCTURE_HH_ */
