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
# include "ast/synapse-decl.hh"
# include "ast/types/synapse-enumerator.hh"

namespace synapse {
namespace compiler {
namespace ast {

class visitor;

/**
 * @brief enumeration description
 */
class enumeration :
  public std::map<uint32_t, types::enumerator *>,
  public ast::decl {
public:
  /**
   * @brief typedef to simplify the naming
   */
  typedef std::map<uint32_t, types::enumerator *> enumerators;

  /**
   * @brief Constructor
   * @param [in] name: name of the enumeration
   * @param [in] enumerators: list of enumerators
   */
  enumeration(const std::string& name, const enumerators& enums);

  /**
   * @brief destructor
   */
  virtual ~enumeration();

  /**
   * @brief Accept function of the visitor design* pattern
   * @param [in] stream: file stream
   * @param [in] visitor: visitor to browse
   */
  virtual void accept(stream& stream, visitor *visitor) const;

  /**
   * @brief Get the name of the enumeration
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

private:
  std::string _name;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_ENUMERATION_HH_ */
