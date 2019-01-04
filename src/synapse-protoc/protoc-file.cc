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

#include "protoc-file.hh"

namespace google {
namespace protobuf {
namespace compiler {

std::string strip_suffix(const std::string& var, const std::string& suffix) {
  if (suffix.size() > var.size())
    return var;
  if (var.compare(var.size() - suffix.size(), suffix.size(), suffix) == 0)
    return var.substr(0, var.size() - suffix.size());
  return std::string("");
}

File::File(const FileDescriptor *desc, OutputDirectory *out,
    const std::string& extension)
  : _desc(desc),
    _extension(extension),
    _name(strip_suffix(desc->name(), ".proto")),
    _full_name(std::string(_name + extension)),
    _stream(out->Open(_full_name)),
    _io_printer(new io::Printer(_stream, '$')) {
  _io_printer->Print("/**\n" \
    " * synapse is free software: you can redistribute it and/or modify\n" \
    " * it under the terms of the GNU General Public License as published\n" \
    " * by the Free Software Foundation, either version 3 of the License,\n" \
    " * or (at your option) any later version.\n" \
    " *\n" \
    " * synapse is distributed in the hope that it will be useful,\n"	\
    " * but WITHOUT ANY WARRANTY; without even the implied warranty of\n" \
    " * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" \
    " * GNU General Public License for more details.\n" \
    " *\n" \
    " * You should have received a copy of the GNU General Public License\n" \
    " * along with synapse.  If not, see <https://www.gnu.org/licenses/>.\n" \
    " */\n\n");
}

File::~File() {
  delete _io_printer;
  delete _stream;
}

};  // namespace compiler
};  // namespace protobuf
};  // namespace google
