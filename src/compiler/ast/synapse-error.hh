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

#ifndef _AST_SYNAPSE_ERROR_HH_
# define _AST_SYNAPSE_ERROR_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-decl.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief error element
 */
class error : public decl {
public:
  /**
   * @brief Constructor
   * @param [in] str: string error
   */
  explicit error(const std::string& str)
    : _error(str) {
  }

  /**
   * @brief Constructor
   * @param [in] d: protobuf descriptor structure
   * @param [in] str: string error
   */
  error(const google::protobuf::Descriptor *d, const std::string& str);

  /**
   * @brief Constructor
   * @param [in] d: protobuf enumeration descriptor
   * @param [in] str: string error
   */
  error(const google::protobuf::EnumDescriptor *d, const std::string& str);

  /**
   * @brief Constructor
   * @param [in] d: protobuf enumeration descriptor
   * @param [in] str: string error
   */
  error(const google::protobuf::ServiceDescriptor *d, const std::string& str);

  /**
   * @brief destructor
   */
  virtual ~error() {}

  /**
   * @brief Accept function of the visitor design* pattern
   * @param [in] stream: file stream
   * @param [in] visitor: visitor to browse
   */
  virtual void accept(stream& stream, visitor *visitor) const;

  /**
   * @brief Get the error
   * @return a string
   */
  std::string get() const {
    return _error;
  }

private:
  std::string _error;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_ERROR_HH_ */
