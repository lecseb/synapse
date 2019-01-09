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

#include "synapse-function.hh"
#include "synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

function::function(const MethodDescriptor *desc)
  : decl(desc->name()),
    _params(new params(desc->output_type())),
    _return(new out(desc->input_type())) {
}

function::function(const std::string& name, out *return_type,
    params *args)
  : decl(name),
    _params(args),
    _return(return_type) {
}

function::~function() {
  delete _params;
  delete _return;
}

std::string function::accept(visitor *visitor) const {
  return visitor->visite(this);
}

std::string function::out::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
