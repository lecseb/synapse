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

namespace google {
namespace protobuf {
namespace compiler {
namespace visitor {

const std::string Stream::endl = "\n";

/**
 * @brief Strip a suffix from a string given in parameter
 * @param [in] var: var to strip
 * @param [in] suffix: suffix to find and remove
 * @return a string
 */
static std::string strip_suffix(const std::string& var,
    const std::string& suffix) {
  if (suffix.size() > var.size())
    return var;
  if (var.compare(var.size() - suffix.size(), suffix.size(), suffix) == 0)
    return var.substr(0, var.size() - suffix.size());
  return std::string("");
}

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

};  // namespace visitor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
