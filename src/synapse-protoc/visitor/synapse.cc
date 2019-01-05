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
#include "adaptor/synapse-ast.hh"
#include "adaptor/synapse-enum.hh"
#include "adaptor/synapse-field.hh"
#include "adaptor/synapse-label.hh"
#include "adaptor/synapse-struct.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace visitor {
namespace header {

Synapse::Synapse(const std::string& filename,
    OutputDirectory *out, const std::string& extension)
  : Header(filename, out, extension) {
}

std::string Synapse::visite(const adaptor::Ast *ast) {
  std::string error = std::string();

  /* include usefull header */
  _stream << "# include <synapse/synapse-type.h" << Stream::endl;
  _stream << Stream::endl;

  std::list<adaptor::Enum *>::const_iterator enums =
    ast->get_enum_begin();
  for (; enums != ast->get_enum_end(); enums++)
    error += (*enums)->accept(this);

  std::list<adaptor::Struct *>::const_iterator structs =
    ast->get_struct_begin();
  for (; structs != ast->get_struct_end(); structs++)
    error += (*structs)->accept(this);

  return error;
}

std::string Synapse::visite(const adaptor::Enum *enumeration) {
  std::string error = std::string();
  _stream << "enum " << enumeration->get_name() << " {" << Stream::endl;
  _stream.indent();
  std::map<uint32_t, adaptor::Label *>::const_iterator label =
    enumeration->get_label_begin();
  if (label != enumeration->get_label_end()) {
    error += label->second->accept(this);
    for (label++; label != enumeration->get_label_end(); label++) {
      _stream << "," << Stream::endl;
      error += label->second->accept(this);
    }
  }
  _stream.outdent();
  _stream << Stream::endl << "};" << Stream::endl;
  _stream << Stream::endl;
  return error;
}

std::string Synapse::visite(const adaptor::Field *field) {
  std::string error = std::string();

  (void)field;

  return error;
}

std::string Synapse::visite(const adaptor::Label *label) {
  std::string error = std::string();

  _stream << label->get_name() << " = " << label->get_value();

  return error;
}

std::string Synapse::visite(const adaptor::Struct *structure) {
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
