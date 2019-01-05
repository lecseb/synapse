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

#ifndef _SYNAPSE_IFILE_HH_
# define _SYNAPSE_IFILE_HH_

# include <algorithm>
# include <iostream>
# include <string>
# include <google/protobuf/descriptor.h>
# include <google/protobuf/compiler/code_generator.h>
# include <google/protobuf/io/printer.h>
# include <google/protobuf/io/zero_copy_stream_impl.h>

namespace google {
namespace protobuf {
namespace compiler {

/**
 * @brief Remove the suffix part of the variable
 * @param [in] var: variable to strip off a suffix
 * @param [in] suffix: suffix to remove
 * @return the result string
 */
std::string strip_suffix(const std::string& var, const std::string& suffix);

class IFile {
public:
  static const std::string endl;

  /**
   * @brief Generate a generic file
   * @param [in] desc: proto description class
   * @param [in] out: proto output description class
   */
  IFile(const FileDescriptor *desc, OutputDirectory *out,
    const std::string& extension);

  /**
   * @brief Destructor
   */
  virtual ~IFile();

  /**
   * @brief Generates code for the given proto file, generating one or more
   * files in the given output directory. A parameter to be passed to the
   * generator can be specified on the command line. This is intended to be used
   * to pass generator specific parameters. It is empty if no parameter was
   * given. ParseGeneratorParameter (below), can be used to accept multiple
   * parameters within the single parameter command line flag.
   * @return true if successful. Otherwise, sets *error to a description of the
   * problem (e.g. "invalid parameter") and returns false.
   */
  virtual bool generate(const std::string& param, std::string *error) = 0;

  /**
   * @brief Write the data into the file
   * @param [in] data: data to write
   * @return the ostream instance to chain the call
   */
  virtual IFile& operator<<(const std::string& data);

  virtual inline void indent() { _io_printer->Indent(); }
  virtual inline void outdent() { _io_printer->Outdent(); }

protected:
  const FileDescriptor *_desc;
  std::string _extension;
  std::string _name;
  std::string _full_name;
  io::ZeroCopyOutputStream *_stream;
  io::Printer *_io_printer;
};

};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_SYNAPSE_IFILE_HH_ */
