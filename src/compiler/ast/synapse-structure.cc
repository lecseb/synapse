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

#include "synapse-string.hh"
#include "ast/synapse-structure.hh"
#include "ast/synapse-visitor.hh"
#include "ast/types/synapse-enumeration.hh"
#include "ast/types/synapse-simple.hh"
#include "ast/types/synapse-structure.hh"

namespace synapse {
namespace compiler {
namespace ast {

structure::structure(const std::string& name, const fields& fields)
  : std::map<uint32_t, type *>(fields.begin(), fields.end()),
    _name(name) {
}

structure::~structure() {
  iterator it = begin();
  for (; it != end(); it++)
    delete it->second;
}

void structure::add_function(ast::function *func) {
  _funcs[func->get_name()] = func;
}

void structure::accept(stream& stream, visitor *visitor) const {
  visitor->visite(stream, this);
}

void structure::factory::create_new(ast::structure *str) {
  std::string name = str->get_name() + "_new";
  ast::type *return_type = new types::structure("", str);

  str->add_function(new ast::function(name, *str, return_type));
}

void structure::factory::create_free(ast::structure *str) {
  std::string param = std::string("msg");
  ast::function::arguments args = {
    { 0,  new types::structure(param, str) }
  };

  std::string name = str->get_name() + "_free";
  str->add_function(new ast::function(name, args, nullptr));
}

void structure::factory::create_dup(ast::structure *str) {
  std::string param = std::string("msg");
  ast::function::arguments args = {
    { 0,  new types::structure(param, str) }
  };

  std::string name = str->get_name() + "_dup";
  ast::type *return_type = new types::structure("", str);

  str->add_function(new ast::function(name, args, return_type));
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
