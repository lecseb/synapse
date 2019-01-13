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

#ifndef _AST_SYNAPSE_INCLUDE_HH_
# define _AST_SYNAPSE_INCLUDE_HH_

# include <string>
# include "synapse-decl.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief declaration
 */
class include : public decl {
public:
  /**
   * @brief Define the type of include
   */
  enum e_type {
    e_type_synapse,
    e_type_protobuf,
    e_type_libc
  };

  /**
   * @brief Constructor
   * @param [in] desc: protobuf file descriptor
   */
  explicit include(const google::protobuf::FileDescriptor *desc);

  /**
   * @brief Constructor
   * @param [in] type: type of the include
   * @param [in] name: name of the include
   */
  include(enum e_type type, const std::string& name);

  /**
   * @brief destructor
   */
  virtual ~include() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const;

  /**
   * @brief Get the declaration name
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

  /**
   * @brief Get the inclusion type
   * @return a type
   */
  enum e_type get_type() const {
    return _type;
  }

private:
  enum e_type _type;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_INCLUDE_HH_ */
