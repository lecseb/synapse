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

#ifndef _PARSER_COMMON_SYNAPSE_DECLARATION_HH_
# define _PARSER_COMMON_SYNAPSE_DECLARATION_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include <google/protobuf/compiler/code_generator.h>
# include <google/protobuf/io/printer.h>
# include <google/protobuf/io/zero_copy_stream_impl.h>
# include "parser/synapse-interface.hh"
# include "parser/synapse-stream.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace common {

class declaration : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] name: name of the file to generate
   * @param [in] extension: generate file extension
   * @param [in] out: protobuf out structure
   */
  declaration(const std::string& name, const std::string& extension,
    google::protobuf::compiler::OutputDirectory *out);

  /**
   * @brief Destructor
   */
  virtual ~declaration();

protected:
  stream _stream;
};

};  // namespace common
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_COMMON_SYNAPSE_DECLARATION_HH_ */
