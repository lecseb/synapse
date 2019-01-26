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

namespace synapse {
namespace compiler {

const std::string stream::endl = "\n";

stream::stream(const std::string& name,
  google::protobuf::compiler::OutputDirectory *out)
  : _stream(out->Open(name)),
    _printer(new google::protobuf::io::Printer(_stream, '$')),
    _name(name) {
}

stream::~stream() {
  delete _printer;
  delete _stream;
}

stream& stream::operator<<(const std::string& data) {
  _printer->Print(data.c_str());
  return *this;
}

};  // namespace compiler
};  // namespace synapse
