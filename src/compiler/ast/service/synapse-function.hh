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

#ifndef _AST_SERVICE_SYNAPSE_FUNCTION_HH_
# define _AST_SERVICE_SYNAPSE_FUNCTION_HH_

# include <string>
# include "synapse-decl.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace svcs {

/**
 * @brief Function element of the AST
 */
class function {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf service descriptor structure
   */
  explicit function(const google::protobuf::MethodDescriptor *desc);

  /**
   * @brief destructor
   */
  virtual ~function() {}

  /**
   * @brief Get the input
   * @return input instance
   */
  const google::protobuf::Descriptor *get_input() const {
    return _input;
  }

  /**
   * @brief Get the output
   * @return output instance
   */
  const google::protobuf::Descriptor *get_output() const {
    return _output;
  }

  /**
   * @brief Get the function name
   * @return a string
   */
  const std::string& get_name() const {
    return _desc->name();
  }

private:
  const google::protobuf::MethodDescriptor *_desc;
  const google::protobuf::Descriptor *_input;
  const google::protobuf::Descriptor *_output;
};

};  // namespace svcs
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SERVICE_FUNCTION_SYNAPSE_FUNCTION_HH_ */
