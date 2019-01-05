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
#include "adaptor/synapse-adaptor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {

Synapse::Synapse(const FileDescriptor *desc, OutputDirectory *out)
  : IHeader(desc, out, ".synapse.h") {
}

Synapse::~Synapse() {
}

bool Synapse::generate(const std::string&, std::string *error) {
  *error = adaptor::PreprocAdaptor::begin(*this, _full_name);
  *error += adaptor::DescAdaptor::adapt(*this, _desc);
  *error += adaptor::PreprocAdaptor::end(*this, _full_name);
  return true;
}

};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
