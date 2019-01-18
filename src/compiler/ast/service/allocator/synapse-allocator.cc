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

#include "synapse-allocator.hh"
#include "synapse-dup.hh"
#include "synapse-error.hh"
#include "synapse-free.hh"
#include "synapse-new.hh"
#include "ast/synapse-visitor.hh"
#include "ast/service/allocator/synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace svcs {
namespace alloc {

std::string allocator::name = "allocator";

allocator::allocator(const google::protobuf::ServiceDescriptor *desc) {
  for (int32_t i = 0; i < desc->method_count(); i++) {
    const google::protobuf::MethodDescriptor *method = desc->method(i);
    if (alloc::function::is_new(method)) {
      push_back(new alloc::function_new(method));
    } else if (alloc::function::is_free(method)) {
      push_back(new alloc::function_free(method));
    } else if (alloc::function::is_dup(method)) {
      push_back(new alloc::function_dup(method));
    } else {
      std::string err = std::string("no matching method for " + method->name());
      push_back(new alloc::error(method, err));
    }
  }
}

bool allocator::accept(ast::visitor *visitor) const {
  return visitor->visite(this);
}

};  // namespace alloc
};  // namespace svcs
};  // namespace ast
};  // namespace compiler
};  // namespace synapse
