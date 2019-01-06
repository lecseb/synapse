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
#include "synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

Ast::Ast(const FileDescriptor *desc)
    : _enums(std::list<Enum *>()),
      _structs(std::list<Struct *>()) {
  /* add all structure definition */
  for (int32_t i = 0; i < desc->message_type_count(); i++)
    _structs.push_back(new Struct(desc->message_type(i)));

  for (int32_t i = 0; i < desc->enum_type_count(); i++)
    _enums.push_back(new Enum(desc->enum_type(i)));

  /* add some context data to the ast */
  DataFactory::add_context_data(this);

  for (int32_t i = 0; i < desc->dependency_count(); i++)
    _includes.push_back(new Include(desc->dependency(i)));
}

Ast::~Ast() {
  std::list<Include *>::iterator it_include = _includes.begin();
  for (; it_include != _includes.end(); it_include++)
    delete *it_include;
  std::list<Enum *>::iterator it_enum = _enums.begin();
  for (; it_enum != _enums.end(); it_enum++)
    delete *it_enum;
  std::list<Struct *>::iterator it_struct = _structs.begin();
  for (; it_struct != _structs.end(); it_struct++)
    delete *it_struct;
  std::list<Function *>::iterator it_func = _functions.begin();
  for (; it_func != _functions.end(); it_func++)
    delete *it_func;
}

std::string Ast::accept(Visitor *visitor) {
  return visitor->visite(this);
}

bool Ast::add_include(Include *include) {
  std::list<Include *>::iterator it = _includes.begin();
  for (; it != _includes.end(); it++)
    if ((*it)->get_name() == include->get_name())
      return false;
  _includes.push_back(include);
  return true;
}

bool Ast::add_function(Function *function) {
  std::list<Function *>::iterator it = _functions.begin();
  for (; it != _functions.end(); it++)
    if ((*it)->get_name() == function->get_name())
      return false;
  _functions.push_back(function);
  return true;
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
