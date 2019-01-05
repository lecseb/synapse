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

#include "synapse-desc.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {
namespace adaptor {

std::string DescAdaptor::adapt(IFile& file, const FileDescriptor *desc) {
  std::string error = std::string();

  /* write list of enum */
  for (int32_t i = 0; i < desc->enum_type_count(); i++) {
    error += EnumAdaptor::adapt(file, desc->enum_type(i));
    file << IFile::endl;
  }

  /* write list of message */
  for (int32_t i = 0; i < desc->message_type_count(); i++) {
    error += StructAdaptor::adapt(file, desc->message_type(i));
    file << IFile::endl;
  }

  /* write the list of services */
  for (int32_t i = 0; i < desc->service_count(); i++) {
    error += ServiceAdaptor::adapt(file, desc->service(i));
    file << IFile::endl;
  }

  return error;
}

};  // namespace adaptor
};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
