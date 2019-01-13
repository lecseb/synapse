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
# include "synapse-enumerators.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class enumeration : public decl {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf enumeration descriptor
   */
  explicit enumeration(const google::protobuf::EnumDescriptor *desc)
    : enumeration(std::string(desc->name()), new enumerators(desc)) {
    _desc = desc;
  }

  /**
   * @brief Constructor
   * @param [in] name: name of the enumeration
   * @param [in] enumerators: list of enumerator
   */
  enumeration(const std::string& name, enumerators *enumerators)
    : decl(name),
      _desc(NULL),
      _enumerators(enumerators) {
  }

  /**
   * @brief destructor
   */
  virtual ~enumeration() {
    delete _enumerators;
  }

  /**
   * @brief Accept function of the visitor design* pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const;

  /**
   * @brief Get the enumerator list
   * @return a valid pointer
   */
  const enumerators *get_enumerators() const {
    return _enumerators;
  }

private:
  const google::protobuf::EnumDescriptor *_desc;
  enumerators *_enumerators;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_ENUMERATION_HH_ */
