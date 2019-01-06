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

#include "synapse-header.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace visitor {
namespace header {

Header::Header(const std::string& filename, OutputDirectory *out,
    const std::string& extension)
  : File(filename, out, extension) {
  std::string temp = std::string("_GENERATE_" + _stream.get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');
  _stream << "#ifndef " << temp << Stream::endl;
  _stream << "# define " << temp << Stream::endl;
  _stream << Stream::endl;
}

Header::~Header() {
  std::string temp = std::string("_GENERATE_" + _stream.get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');
  _stream << "#endif /* !" << temp << " */" << Stream::endl;
}

};  // namespace header
};  // namespace visitor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
