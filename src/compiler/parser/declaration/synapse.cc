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

#include "synapse.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace declaration {

synapse::synapse(parser::stream& stream)
  : _stream(stream) {
}

bool synapse::visite(const ast::structure *) {
  return true;
}

bool synapse::visite(const ast::structs::fields *) {
  return true;
}

};  // namespace declaration
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
