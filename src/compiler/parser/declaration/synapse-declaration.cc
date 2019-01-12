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

#include "synapse-declaration.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace common {

declaration::declaration(const std::string& name, const std::string& extension,
  google::protobuf::compiler::OutputDirectory *out)
  : _stream(stream(name, extension, out)) {
  std::string temp = std::string("_SYNAPSE_" + _stream.get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');

  _stream << "/**\n"
    << " * synapse is free software: you can redistribute it and/or modify\n"
    << " * it under the terms of the GNU General Public License as "
    << "published\n"
    << " * by the Free Software Foundation, either version 3 of the License,"
    << "\n"
    << " * or (at your option) any later version.\n"
    << " *\n"
    << " * synapse is distributed in the hope that it will be useful,\n"
    << " * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
    << " * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
    << " * GNU General Public License for more details.\n"
    << " *\n"
    << " * You should have received a copy of the GNU General Public License"
    << "\n"
    << " * along with synapse.  If not, see <https://www.gnu.org/licenses/>."
    << "\n"
    << " */\n\n";
  _stream << "#ifndef " << temp << stream::endl;
  _stream << "# define " << temp << stream::endl;
  _stream << stream::endl;
}

declaration::~declaration() {
  std::string temp = std::string("_SYNAPSE_" + _stream.get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');
  _stream << "#endif /* !" << temp << " */" << stream::endl;
}

// std::string definition::parse(const FileDescriptor *desc) {
//   ast::decls *_decls = new ast::decls(desc);
//   std::string error = _decls->accept(this);
//   delete _decls;
//   return error;
// }

};  // namespace common
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
