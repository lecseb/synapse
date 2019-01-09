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

#include "synapse-definition.hh"
#include "synapse-factory.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {

definition::definition(const std::string& filename,
    const std::string& extension, const std::string&,
    OutputDirectory *out)
  : file(filename, out, extension),
    _include_path(std::string()) {
  std::string temp = std::string("_SYNAPSE_" + _stream.get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');
  _stream << "#ifndef " << temp << stream::endl;
  _stream << "# define " << temp << stream::endl;
  _stream << stream::endl;
}

definition::~definition() {
  std::string temp = std::string("_SYNAPSE_" + _stream.get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');
  _stream << "#endif /* !" << temp << " */" << stream::endl;
}

std::string definition::parse(const FileDescriptor *desc) {
  ast::decls *_decls = new ast::decls(desc);
  std::string error = _decls->accept(this);
  delete _decls;
  return error;
}

};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
