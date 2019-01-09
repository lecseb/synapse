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

#ifndef _SYNAPSE_FILE_HH_
# define _SYNAPSE_FILE_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include <google/protobuf/compiler/code_generator.h>
# include <google/protobuf/io/printer.h>
# include <google/protobuf/io/zero_copy_stream_impl.h>
# include "synapse-stream.hh"
# include "ast/synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {

class file : public ast::visitor {
public:
  /**
   * @brief Constructor
   * @param [in] out: protobuf out structure
   * @param [in] extension: extension of the file to write
   */
  file(const std::string& filename, OutputDirectory *out,
    const std::string& extension);

  /**
   * @brief Destructor
   */
  virtual ~file() {}

protected:
  stream _stream;
};

};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_SYNAPSE_FILE_HH_ */
