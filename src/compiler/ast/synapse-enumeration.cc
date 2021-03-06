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

#include "ast/synapse-enumeration.hh"
#include "ast/synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace ast {

enumeration::enumeration(const std::string& name, const enumerators& enums)
  : _name(name) {
  enumerators::const_iterator it = enums.begin();
  for (; it != enums.end(); it++) {
    const types::enumerator *enumerator = it->second;
    (*this)[it->first] = new types::enumerator(enumerator->get_name(),
      enumerator->get_default_value());
  }
}

enumeration::~enumeration() {
  enumerators::iterator it = begin();
  for (; it != end(); it++)
    delete it->second;
}

void enumeration::accept(stream& stream, visitor *visitor) const {
  visitor->visite(stream, this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
