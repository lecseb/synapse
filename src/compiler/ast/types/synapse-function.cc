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

#include "ast/types/synapse-function.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace types {

function::function(const std::string& name, const ast::function *func)
  : type(name, "NULL", false),
    _function(func) {
}

const ast::function *function::get_function() const {
  return _function;
}

std::string function::get_type_form() const {
  return _function->get_name();
}

type *function::duplicate() const {
  return new function(_name, _function);
}

};  // namespace types
};  // namespace ast
};  // namespace compiler
};  // namespace synapse
