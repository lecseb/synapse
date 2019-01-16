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

#ifndef _AST_SYNAPSE_ELEMENTS_HXX_
# define _AST_SYNAPSE_ELEMENTS_HXX_

# include <map>
# include <string>

namespace synapse {
namespace compiler {
namespace ast {

template<class type>
elements<type>::elements()
  : _elements(std::map<uint32_t, type *>()) {
}

template<class type>
elements<type>::elements(const std::initializer_list<type *>& list)
  : _elements(std::map<uint32_t, type *>()) {
  uint32_t index = 0;
  typename std::initializer_list<type *>::iterator it = list.begin();
  for (index = 0; it != list.end(); it++, index++)
    _elements[index] = (*it);
}

template<class type>
elements<type>::~elements() {
  typename std::map<uint32_t, type *>::iterator it = _elements.begin();
  for (; it != _elements.end(); it++)
    delete it->second;
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_ELEMENTS_HXX_ */
