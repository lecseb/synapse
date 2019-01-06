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

#include "synapse.hh"
#include "ast/synapse-ast.hh"
#include "ast/synapse-enum.hh"
#include "ast/synapse-field.hh"
#include "ast/synapse-function.hh"
#include "ast/synapse-label.hh"
#include "ast/synapse-struct.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace visitor {
namespace header {

Synapse::Synapse(const std::string& filename,
    OutputDirectory *out, const std::string& extension)
  : Header(filename, out, extension) {
}

std::string Synapse::visite(ast::Ast *ast) {
  std::string error = std::string();
  /* add all the include data into the generated header file */
  std::list<ast::Include *>::const_iterator includes =
    ast->get_includes_begin();
  for (; includes != ast->get_includes_end(); includes++)
    error += (*includes)->accept(this);
  _stream << Stream::endl;

  std::list<ast::Enum *>::const_iterator enums =
    ast->get_enums_begin();
  for (; enums != ast->get_enums_end(); enums++)
    error += (*enums)->accept(this);

  std::list<ast::Struct *>::const_iterator structs =
    ast->get_structs_begin();
  for (; structs != ast->get_structs_end(); structs++)
    error += (*structs)->accept(this);

  return error;
}

std::string Synapse::visite(ast::Enum *enumeration) {
  std::string error = std::string();
  _stream << "enum " << enumeration->get_name() << " {" << Stream::endl;
  _stream.indent();
  std::map<uint32_t, ast::Label *>::const_iterator label =
    enumeration->get_labels_begin();
  if (label != enumeration->get_labels_end()) {
    error += label->second->accept(this);
    for (label++; label != enumeration->get_labels_end(); label++) {
      _stream << "," << Stream::endl;
      error += label->second->accept(this);
    }
  }
  _stream.outdent();
  _stream << Stream::endl << "};" << Stream::endl;
  _stream << Stream::endl;
  return error;
}

std::string Synapse::visite(ast::Field *) {
  /* nothing to do here. all structure are opaque in synapse implementation */
  return std::string();
}

std::string Synapse::visite(ast::Function *) {
  return std::string();
}

std::string Synapse::visite(ast::Include *include) {
  std::string error = std::string();

  _stream << "# include ";
  if (include->is_synapse_header())
    _stream << "<" << include->get_name() << ">";
  else
    _stream << "\"" << include->get_name() << "\"";
  _stream << Stream::endl;
  return error;
}

std::string Synapse::visite(ast::Label *label) {
  std::string error = std::string();

  _stream << label->get_name() << " = " << label->get_value();
  return error;
}

std::string Synapse::visite(ast::Struct *structure) {
  std::string error = std::string();

  _stream << "struct " << structure->get_name() << ";" << Stream::endl;
  _stream << Stream::endl;
  return error;
}

};  // namespace header
};  // namespace visitor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
