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

#ifndef _VISITOR_SYNAPSE_DEFAULT_HH_
# define _VISITOR_SYNAPSE_DEFAULT_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include <google/protobuf/compiler/code_generator.h>
# include <google/protobuf/io/printer.h>
# include <google/protobuf/io/zero_copy_stream_impl.h>
# include "synapse-stream.hh"
# include "adaptor/synapse-ast.hh"
# include "adaptor/synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace visitor {

class Default : public adaptor::Visitor {
public:
  /**
   * @brief Constructor
   * @param [in] out: protobuf out structure
   * @param [in] extension: extension of the file to write
   */
  Default(const std::string& filename, OutputDirectory *out,
    const std::string& extension)
    : _stream(Stream(filename, out, extension)) {
    _stream << "/**\n"
      << " * synapse is free software: you can redistribute it and/or modify\n"
      << " * it under the terms of the GNU General Public License as "
      << "published\n"
      << " * by the Free Software Foundation, either version 3 of the License,"
      << "\n"
      << " * or (at your option) any later version.\n"
      << " *\n"
      << " * synapse is distributed in the hope that it will be useful,\n"
      << " * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
      << " * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
      << " * GNU General Public License for more details.\n"
      << " *\n"
      << " * You should have received a copy of the GNU General Public License"
      << "\n"
      << " * along with synapse.  If not, see <https://www.gnu.org/licenses/>."
      << "\n"
      << " */\n\n";
  }

  /**
   * @brief Destructor
   */
  virtual ~Default() {}

  /**
   * @brief Visite an Ast node
   * @param [in] ast: ast node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Ast *ast) = 0;

  /**
   * @brief Visite an Enumeration node
   * @param [in] enumeration: enumeration node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Enum *enumeration) = 0;

  /**
   * @brief Visite a field node
   * @param [in] field: field node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Field *field) = 0;

  /**
   * @brief Visite a label node
   * @param [in] label: label node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Label *label) = 0;

  /**
   * @brief Visite a structure node
   * @param [in] structure: structure node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const adaptor::Struct *structure) = 0;

  /**
   * @brief Parse the file descriptor, build the ast and call the visitor
   * @param [in] descriptor: descriptor to parse
   * @return an error string representation
   */
  virtual std::string parse(const FileDescriptor *descriptor) {
    adaptor::Ast ast(descriptor);
    return ast.accept(this);
  }

protected:
  Stream _stream;
};

};  // namespace visitor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_VISITOR_SYNAPSE_DEFAULT_HH_ */
