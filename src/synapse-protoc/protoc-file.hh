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

#ifndef _PROTOC_FILE_H_
# define _PROTOC_FILE_H_

# include <algorithm>
# include <google/protobuf/descriptor.h>
# include <google/protobuf/compiler/code_generator.h>
# include <google/protobuf/io/printer.h>
# include <google/protobuf/io/zero_copy_stream_impl.h>

namespace google {
namespace protobuf {
namespace compiler {

static inline std::string strip_suffix(const std::string& var,
  const std::string& suffix) {
  if (suffix.size() > var.size())
    return var;
  if (var.compare(var.size() - suffix.size(), suffix.size(), suffix) == 0)
    return var.substr(0, var.size() - suffix.size());
  return std::string("");
};

class File {
public:
  /**
   * @brief Generate a generic file
   * @param [in] desc: proto description class
   * @param [in] out: proto output description class
   */
  explicit File(const FileDescriptor *desc, OutputDirectory *out,
      const std::string& extension)
    : _desc(desc),
      _extension(extension),
      _name(strip_suffix(desc->name(), ".proto")),
      _full_name(std::string(_name + extension)),
      _stream(out->Open(_full_name)),
      _io_printer(new io::Printer(_stream, '$')) {

    std::cout << "File written there : " << _full_name << std::endl;

    _io_printer->Print("/**\n" \
      " * synapse is free software: you can redistribute it and/or modify\n" \
      " * it under the terms of the GNU General Public License as published\n" \
      " * by the Free Software Foundation, either version 3 of the License,\n" \
      " * or (at your option) any later version.\n" \
      " *\n" \
      " * synapse is distributed in the hope that it will be useful,\n"	\
      " * but WITHOUT ANY WARRANTY; without even the implied warranty of\n" \
      " * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" \
      " * GNU General Public License for more details.\n" \
      " *\n" \
      " * You should have received a copy of the GNU General Public License\n" \
      " * along with synapse.  If not, see <https://www.gnu.org/licenses/>.\n" \
      " */\n\n"
    );
  };

  /**
   * @brief Destructor
   */
  virtual ~File() {
    //_stream->flush();
    delete _io_printer;
    delete _stream;
  };

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

#endif /* !_PROTOC_FILE_H_ */
