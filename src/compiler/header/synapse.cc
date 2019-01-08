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
#include "synapse-ctx_factory.hh"
#include "ast/synapse-ast.hh"
#include "ast/synapse-enum.hh"
#include "ast/synapse-field.hh"
#include "ast/synapse-function.hh"
#include "ast/synapse-label.hh"
#include "ast/synapse-struct.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {

Synapse::Synapse(const std::string& filename,
    OutputDirectory *out, const std::string& extension)
  : Header(filename, out, extension) {
}

std::string Synapse::visite(ast::Ast *ast) {
  std::string error = std::string();

  /* add all the include data into the generated header file */
  std::list<ast::Include *>::const_iterator incs = ast->get_includes_begin();
  for (; incs != ast->get_includes_end(); incs++)
    error += (*incs)->accept(this);

  std::list<ast::Enum *>::const_iterator enums = ast->get_enums_begin();
  for (; enums != ast->get_enums_end(); enums++) {
    error += (*enums)->accept(this);
    CtxFactory::generate_callback_from_enum(ast, (*enums));
  }

  std::list<ast::Struct *>::const_iterator structs = ast->get_structs_begin();
  for (; structs != ast->get_structs_end(); structs++) {
    error += (*structs)->accept(this);
    CtxFactory::generate_callback_from_structure(ast, (*structs));
  }

  std::list<ast::Function *>::const_iterator funcs =
    ast->get_functions_begin();
  for (; funcs != ast->get_functions_end(); funcs++)
    error += (*funcs)->accept(this);

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

std::string Synapse::visite(ast::Field *field) {
  /* Those field concern the input parameter list of a function */
  const std::string& type = ast::type_tostring(field->get_type());
  _stream << type << (field->get_name().size() ? " " + field->get_name() : "")
    << (field->is_repeated() ? " *" : "");
  return std::string();
}

std::string Synapse::visite(ast::Function *function) {
  std::string error = std::string();

  if (function->get_comment().size())
    _stream << function->get_comment() << Stream::endl;
  if (function->get_output()) {
    error += function->get_output()->accept(this);
    _stream << function->get_name() << "(";
  } else {
    _stream << "void " << function->get_name() << "(";
  }
  _stream.indent();
  std::list<ast::Field *>::const_iterator field = function->get_fields_begin();
  if (field != function->get_fields_end()) {
    _stream << Stream::endl;
    error += (*field)->accept(this);
    for (field++; field != function->get_fields_end(); field++) {
      _stream << "," << Stream::endl;
      error += (*field)->accept(this);
    }
  }
  _stream.outdent();
  _stream << ");" << Stream::endl;
  _stream << Stream::endl;
  return error;
}

std::string Synapse::visite(ast::Include *include) {
  _stream << "# include <" << include->get_name() << ">" << Stream::endl;
  _stream << Stream::endl;
  return std::string();
}

std::string Synapse::visite(ast::Label *label) {
  std::string error = std::string();

  _stream << label->get_name() << " = " << label->get_value();
  return error;
}

std::string Synapse::visite(ast::Struct *structure) {
  std::string error = std::string();

  _stream << "/**" << Stream::endl;
  _stream << " * opaque structure" << Stream::endl;
  _stream << " */" << Stream::endl;
  _stream << "struct " << structure->get_name() << ";" << Stream::endl;
  _stream << Stream::endl;
  return error;
}

};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
