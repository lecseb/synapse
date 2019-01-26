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

#ifndef _SYNAPSE_STREAM_HH_
# define _SYNAPSE_STREAM_HH_

# include <string>
# include <google/protobuf/compiler/code_generator.h>
# include <google/protobuf/io/printer.h>
# include <google/protobuf/io/zero_copy_stream_impl.h>

namespace synapse {
namespace compiler {

class stream {
public:
  /**
   * @brief \n static variable
   */
  static const std::string endl;

  /**
   * @brief Constructor
   * @param [in] name: file name
   * @param [in] out: protobuf out structure
   */
  stream(const std::string& name,
    google::protobuf::compiler::OutputDirectory *out);

  /**
   * @brief Destructor
   */
  ~stream();

  /**
   * @brief Push a data into the stream
   * @param [in] data: data to push
   * @return a reference to the stream itself
   */
  stream& operator<<(const std::string& data);

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
   * @brief Get the name associated to the stream
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

private:
  google::protobuf::io::ZeroCopyOutputStream *_stream;
  google::protobuf::io::Printer *_printer;
  std::string _name;
};

};  // namespace compiler
};  // namespace synapse

#endif /* !_SYNAPSE_STREAM_HH_ */
