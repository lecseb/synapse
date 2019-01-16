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

namespace synapse {
namespace compiler {
namespace ast {

function::function(const google::protobuf::MethodDescriptor *desc)
  : decl(desc->name()),
    _param(new param("msg", desc->input_type())),
    _return(new output(desc->output_type())) {
}

function::~function() {
  delete _param;
  delete _return;
}

bool function::accept(visitor *visitor) const {
  return visitor->visite(this);
}

function::output::output(const google::protobuf::Descriptor *desc)
  : _type(std::string()) {
  if (desc->name() == "void")
    _type = std::string("void ");
  else
    _type = std::string("struct " + desc->name() + " *");
}

bool function::output::accept(visitor *visitor) const {
  return visitor->visite(this);
}

function::param::param(const std::string& name,
  const google::protobuf::Descriptor *desc)
  : output(desc),
    _name(name) {
}

bool function::param::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
