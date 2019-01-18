/** This file is part of synapse.
 *
 * synapse is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * synapse is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with synapse.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _PARSER_SYNAPSE_INTERFACE_HH_
# define _PARSER_SYNAPSE_INTERFACE_HH_

# include <google/protobuf/descriptor.h>

namespace synapse {
namespace compiler {
namespace parser {

/**
 * @brief generator class: use to generate both source and header
 */
class interface {
public:
  /**
   * @brief Destructor
   */
  virtual ~interface() {}

  /**
   * @brief Parse the protobuf AST and generate our own
   * @param [in] descriptor: entry node of the ast
   * @return true on success, false on error
   * @note see @error class in order to get all error message
   */
  virtual bool parse(const google::protobuf::FileDescriptor *descriptor) = 0;
};

};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_SYNAPSE_GENERATOR_HH_ */
