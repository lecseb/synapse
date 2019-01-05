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

#include "synapse-struct.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {
namespace adaptor {

std::string StructAdaptor::adapt(IFile& file, const Descriptor *desc) {
  file << "struct " << desc->name() << ";" << IFile::endl;
  return std::string("");
}

};  // namespace adaptor
};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
