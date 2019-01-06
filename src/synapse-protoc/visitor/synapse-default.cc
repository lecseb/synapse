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

#include "synapse-default.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace visitor {

Default::Default(const std::string& filename, OutputDirectory *out,
    const std::string& extension)
  : _stream(Stream(filename, out, extension)) {
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
}

std::string Default::parse(const FileDescriptor *descriptor) {
  adaptor::Ast ast(descriptor);
  return ast.accept(this);
}

};  // namespace visitor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
