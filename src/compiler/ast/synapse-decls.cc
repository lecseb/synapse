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

#include "synapse-decls.hh"
#include "synapse-enumeration.hh"
#include "synapse-include.hh"
#include "synapse-structure.hh"
#include "synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace ast {

decls::decls(const google::protobuf::FileDescriptor *desc)
  : _decls(std::list<decl *>()) {
  for (int32_t i = 0; i < desc->dependency_count(); i++) {
    const google::protobuf::FileDescriptor *dependency = desc->dependency(i);
    _decls.push_back(new include(dependency));
  }

  for (int32_t i = 0; i < desc->enum_type_count(); i++)
    _decls.push_back(new enumeration(desc->enum_type(i)));

  for (int32_t i = 0; i < desc->message_type_count(); i++)
    _decls.push_back(new structure(desc->message_type(i)));

  for (int32_t i = 0; i < desc->service_count(); i++)
    _decls.push_back(new service(desc->service(i)));
}

std::string decls::accept(visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
