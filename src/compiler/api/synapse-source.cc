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
#include "synapse-source.hh"

namespace synapse {
namespace compiler {
namespace api {

// static void _source_create_condition(stream& stream,
//   const ast::function::arguments& args)
// {
//   ast::function::arguments::const_iterator it = args.end();
//   for (it = args.begin(); it != args.end(); it++) {
//     if (it->second->is_pointer()) {
//       stream << "synapse_return_val_if_fail(";
//       stream << it->second->get_name();
//       stream << ", NULL);" << stream::endl;
//     }
//   }
// }

void source::visite(stream& stream, const ast::structure *node) {
  stream << "struct " << node->get_name() << " {" << stream::endl;
  stream.indent();

  ast::structure::const_iterator it = node->begin();
  for (; it != node->end(); it++) {
    ast::type *type = it->second;
    stream << type->get_field_form(false) << ";" << stream::endl;
  }

  stream.outdent();
  stream << "};" << stream::endl;
  stream << stream::endl;
}

};  // namespace api
};  // namespace compiler
};  // namespace synapse
