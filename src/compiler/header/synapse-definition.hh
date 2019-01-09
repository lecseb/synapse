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

#ifndef _HEADER_SYNAPSE_DEFINITION_HH_
# define _HEADER_SYNAPSE_DEFINITION_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include <google/protobuf/compiler/code_generator.h>
# include <google/protobuf/io/printer.h>
# include <google/protobuf/io/zero_copy_stream_impl.h>
# include "synapse-file.hh"
# include "synapse-stream.hh"
# include "ast/synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {

class definition : public file {
public:
  /**
   * @brief Constructor
   * @param [in] out: protobuf out structure
   * @param [in] extension: extension of the file to write
   */
  definition(const std::string& filename, const std::string& extension,
    const std::string& params, OutputDirectory *out);

  /**
   * @brief Destructor
   */
  virtual ~definition();

  /**
   * @brief Order the parsing and start the ast construction
   * @param [in] desc: protobuf file structure
   * @return a string
   */
  virtual std::string parse(const FileDescriptor *desc);

protected:
  std::string _include_path;
};

};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_HEADER_SYNAPSE_DEFITION_HH_ */
