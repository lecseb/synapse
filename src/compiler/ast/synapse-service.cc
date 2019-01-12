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

#include "synapse-service.hh"
#include "synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace ast {

service::service(const google::protobuf::ServiceDescriptor *desc)
  : decl(desc->name()),
    _functions(std::list<function *>()) {
  for (int32_t i = 0; i < desc->method_count(); i++) {
    const google::protobuf::MethodDescriptor *method = desc->method(i);
    _functions.push_back(new function(method));
  }
}

service::service(const std::string& name,
    const std::initializer_list<function *>& list)
  : decl(name),
    _functions(list) {
}

service::~service() {
  std::list<function *>::iterator it = _functions.begin();
  for (; it != _functions.end(); it++)
    delete (*it);
}

std::string service::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
