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

#ifndef _VISITOR_SYNAPSE_STREAM_HH_
# define _VISITOR_SYNAPSE_STREAM_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include <google/protobuf/compiler/code_generator.h>
# include <google/protobuf/io/printer.h>
# include <google/protobuf/io/zero_copy_stream_impl.h>

namespace google {
namespace protobuf {
namespace compiler {
namespace visitor {

class Stream {
public:
  /**
   * @brief \n static variable
   */
  static const std::string endl;

  /**
   * @brief Constructor
   * @param [in] name: file name
   * @param [in] out: protobuf out structure
   * @param [in] extension: extension of the file to write
   */
  Stream(const std::string& name, OutputDirectory *out,
    const std::string& extension);

  /**
   * @brief Destructor
   */
  ~Stream();

  /**
   * @brief Push a data into the stream
   * @param [in] data: data to push
   * @return a reference to the stream itself
   */
  Stream& operator<<(const std::string& data) {
    _printer->Print(data.c_str());
    return *this;
  }

  /**
   * @brief Add two spaces automatically into the stream
   */
  void indent() {
    _printer->Indent();
  }

  /**
   * @brief Remove an indent made previously
   */
  void outdent() {
    _printer->Outdent();
  }

  /**
   * @brief Get the name of the file associated to the stream
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

private:
  std::string _name;
  io::ZeroCopyOutputStream *_stream;
  io::Printer *_printer;
};

};  // namespace visitor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_VISITOR_SYNAPSE_STREAM_HH_ */
