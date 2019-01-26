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

#include "synapse-error.hh"
#include "synapse-header.hh"
#include "synapse-string.hh"

namespace synapse {
namespace compiler {
namespace api {

void header::visite(stream& stream, const ast::enumeration *node) {
  stream << "enum " << node->get_name() << " {" << stream::endl;
  stream.indent();
  ast::enumeration::const_iterator it = node->begin();
  if (it != node->end()) {
    stream << it->second->get_field_form(false);
    for (it++; it != node->end(); it++) {
      stream << "," << stream::endl << it->second->get_field_form(false);
    }
    stream << stream::endl;
  }
  stream.outdent();
  stream << "};" << stream::endl;
  stream << stream::endl;
}

void header::visite(stream& stream, const ast::structure *node) {
  stream << "struct " << node->get_name() << ";" << stream::endl;
  stream << stream::endl;

  const ast::structure::functions& funcs = node->get_functions();
  ast::structure::functions::const_iterator it = funcs.begin();
  for (; it != funcs.end(); it++) {
    ast::function *func = it->second;
    std::string name = strip_prefix(func->get_name(), node->get_name());
    if (name == "_dup") {
    } else if (name == "_free") {
    } else if (name == "_dup") {
    }
  }
}

// void header::visite(stream& stream, const ast::services::function_free *) {
//   stream << "/**" << stream::endl;
//   stream << " * @brief free an instance structure";
//   stream << stream::endl;
//   stream << " * @return a valid pointer on success, NULL on error";
//   stream << stream::endl;
//   stream << " */" << stream::endl;
//   stream << node->get_prototype(false, false) << ";" << stream::endl;
//   stream << stream::endl;
// }

// void header::visite(stream& stream, const ast::services::function_new *) {
//   stream << "/**" << stream::endl;
//   stream << " * @brief allocate a new structure instance";
//   stream << stream::endl;
//   stream << " * @return a valid pointer on success, NULL on error";
//   stream << stream::endl;
//   stream << " */" << stream::endl;
//   stream << node->get_prototype(false, true) << ";" << stream::endl;
//   stream << stream::endl;
// }

};  // namespace api
};  // namespace compiler
};  // namespace synapse
