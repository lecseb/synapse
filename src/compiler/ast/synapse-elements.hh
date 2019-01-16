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

#ifndef _AST_SYNAPSE_ELEMENTS_HH_
# define _AST_SYNAPSE_ELEMENTS_HH_

# include <map>
# include <string>

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
template<class type>
class elements {
public:
  /**
   * @brief Constructor
   */
  elements();

  /**
   * @brief Constructor
   */
  explicit elements(const std::initializer_list<type *>& list);

  /**
   * @brief destructor
   */
  virtual ~elements();

  /**
   * @brief Get the field list
   * @return a valid pointer
   */
  const std::map<uint32_t, type *>& get_elements() const {
    return _elements;
  }

protected:
  std::map<uint32_t, type *> _elements;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

# include "synapse-elements.hxx"

#endif /* _AST_SYNAPSE_ELEMENTS_HH_ */
