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

#include "synapse-ast.hh"
#include "synapse-data_factory.hh"
#include "synapse-function.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

void DataFactory::add_context_data(ast::Ast *ast) {
  /* add some include in the ast */
  DataFactory::_add_context_includes(ast);
  /* add allocation function */
  DataFactory::_add_context_functions(ast);
}

void DataFactory::_add_context_includes(ast::Ast *ast) {
  std::list<Struct *>::const_iterator structs =
    ast->get_structs_begin();
  for (; structs != ast->get_structs_end(); structs++) {
    std::map<std::string, Field *>::const_iterator field =
      (*structs)->get_fields_begin();
    for (; field != (*structs)->get_fields_end(); field++) {
      if (field->second->get_type() == FieldDescriptor::TYPE_BYTES)
	ast->add_include(new Include("synapse/synapse-type.hh"));
    }
  }
}

void DataFactory::_add_context_functions(ast::Ast *ast) {
  std::list<ast::Struct *>::const_iterator structs =
    ast->get_structs_begin();
  for (; structs != ast->get_structs_end(); structs++) {
    ast->add_function(new Function(
      std::string((*structs)->get_name() + "_new"),
      std::list<Field *>(), NULL));
    ast->add_function(new Function(
      std::string((*structs)->get_name() + "_free"),
      std::list<Field *>(), NULL));
  }
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
