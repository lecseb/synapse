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

#ifndef _AST_SERVICE_ALLOCATOR_SYNAPSE_FUNCTION_HH_
# define _AST_SERVICE_ALLOCATOR_SYNAPSE_FUNCTION_HH_

# include "ast/service/synapse-function.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace svcs {
namespace alloc {

class visitor;

/**
 * @brief Function element of the AST
 */
class function : public svcs::function {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf service descriptor structure
   */
  explicit function(const google::protobuf::MethodDescriptor *desc)
    : svcs::function(desc) {}

  /**
   * @brief destructor
   */
  virtual ~function() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const = 0;

  /**
   * @brief is the method descriptor is a duplicate function
   * @param [in] desc: protobuf method descriptor structure
   * @return true or false
   */
  static bool is_dup(const google::protobuf::MethodDescriptor *desc) {
    const google::protobuf::Descriptor *input = desc->input_type();
    std::string name = std::string(input->name() + "_dup");
    return name == desc->name() ? true : false;
  }

  /**
   * @brief is the method descriptor is a free function
   * @param [in] desc: protobuf method descriptor structure
   * @return true or false
   */
  static bool is_free(const google::protobuf::MethodDescriptor *desc) {
    const google::protobuf::Descriptor *input = desc->input_type();
    std::string name = std::string(input->name() + "_delete");
    return name == desc->name() ? true : false;
  }

  /**
   * @brief is the method descriptor is a new function
   * @param [in] desc: protobuf method descriptor structure
   * @return true or false
   */
  static bool is_new(const google::protobuf::MethodDescriptor *desc) {
    const google::protobuf::Descriptor *input = desc->input_type();
    std::string name = std::string(input->name() + "_new");
    return name == desc->name() ? true : false;
  }
};

};  // namespace alloc
};  // namespace svcs
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SERVICE_ALLOCATOR_SYNAPSE_NEW_HH_ */
