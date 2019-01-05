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

#include "synapse-service.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {
namespace adaptor {

std::string ServiceAdaptor::adapt(IFile& file, const ServiceDescriptor *desc) {
  for (int32_t i = 0; i < desc->method_count(); i++) {
    ServiceAdaptor::adapt(file, desc->method(i));
    file << IFile::endl;
  }
  return std::string("");
}

std::string ServiceAdaptor::adapt(IFile& file, const MethodDescriptor *desc) {
  file << "struct " << desc->output_type()->name() << " *"
    << desc->name() << "(struct " << desc->input_type()->name()
    << " *msg);" << IFile::endl;
  return std::string("");
}

};  // namespace adaptor
};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
