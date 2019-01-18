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

#ifndef _PARSER_FILE_SYNAPSE_INTERFACE_HH_
# define _PARSER_FILE_SYNAPSE_INTERFACE_HH_

# include <map>
# include <string>
# include "ast/synapse-decls.hh"
# include "ast/synapse-visitor.hh"
# include "parser/synapse-params.hh"
# include "parser/synapse-stream.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace file {

class interface : public ast::visitor {
public:
  /**
   * @brief Constructor
   * @param [in] params: parameters
   * @param [in] stream: file stream to generate the file
   */
  interface(const params& params, stream& stream)
    : _params(params),
      _stream(stream) {}

  /**
   * @brief Destructor
   */
  virtual ~interface() {}

  /**
   * @brief Parse the entire tree
   * @param [in] node: node to parse
   * @return true on success, false otherwise
   */
  virtual bool parse(const ast::decls *node) = 0;


  bool visite(const ast::include *node) {
    std::string name = std::string();

    switch (node->get_type()) {
    case ast::include::e_type_libc:
      name = node->get_name();
      break;
    case ast::include::e_type_protobuf:
      name = std::string(strip_suffix(node->get_name(), ".proto") +
        ".synapse.h");
      break;
    case ast::include::e_type_synapse:
      name = std::string("synapse/" + node->get_name());
      break;
    }
    _stream << name;
    return true;
  }

protected:
  const std::map<std::string, std::string>& _params;
  stream& _stream;
};

};  // namespace file
};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_FILE_SYNAPSE_FILE_HH_ */
