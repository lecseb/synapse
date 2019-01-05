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

#ifndef _HEADER_ADAPTOR_SYNAPSE_DESC_HH_
# define _HEADER_ADAPTOR_SYNAPSE_DESC_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-enum.hh"
# include "synapse-ifile.hh"
# include "synapse-preproc.hh"
# include "synapse-service.hh"
# include "synapse-struct.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {
namespace adaptor {

class DescAdaptor {
public:
  /**
   * @brief Adapt an enum descriptor and print it into the file
   * @param [in] file: file to write the converted data
   * @param [in] desc: descriptor to convert
   * @return an empty string on success, an explanation on error
   */
  static std::string adapt(IFile& file, const FileDescriptor *desc);
};

};  // namespace adaptor
};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_HEADER_ADAPTOR_SYNAPSE_DESC_HH_ */
