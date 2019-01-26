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

#include "ast/synapse-function.hh"
#include "ast/synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace ast {

function::function(const std::string& name, const arguments& args,
    ast::type *out)
  : _args(args.begin(), args.end()),
    _name(name),
    _out(out) {
}

function::~function() {
  arguments::iterator it = _args.begin();
  for (; it != _args.end(); it++)
    delete it->second;
  delete _out;
}

std::string function::get_prototype(bool const_return, bool const_param) const {
  std::string prototype = std::string();
  prototype += _out ? _out->get_return_form(const_return) : "void ";
  prototype += _name + std::string("(\n");
  arguments::const_iterator it = _args.begin();
  if (it != _args.end()) {
    prototype += std::string("  ") + it->second->get_field_form(const_param);
    for (it++; it != _args.end(); it++) {
      prototype += std::string(",\n");
      prototype += std::string("  ") + it->second->get_field_form(const_param);
    }
  } else {
    prototype += "void";
  }
  prototype += std::string(")");
  return prototype;
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
