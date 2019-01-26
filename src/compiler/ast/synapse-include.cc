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

#include "synapse-include.hh"
#include "synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace ast {

include::include(const std::string& name)
  : _name(name) {
}

void include::accept(stream& stream, visitor *visitor) const {
  visitor->visite(stream, this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
