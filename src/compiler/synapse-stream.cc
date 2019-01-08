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

#include "synapse-stream.hh"
#include "synapse-string.hh"

namespace google {
namespace protobuf {
namespace compiler {

const std::string Stream::endl = "\n";

Stream::Stream(const std::string& name, OutputDirectory *out,
    const std::string& extension)
  : _name(std::string(strip_suffix(name, ".proto") + extension)),
    _stream(out->Open(_name)),
    _printer(new io::Printer(_stream, '$')) {
}

Stream::~Stream() {
  delete _printer;
  delete _stream;
}

};  // namespace compiler
};  // namespace protobuf
};  // namespace google
