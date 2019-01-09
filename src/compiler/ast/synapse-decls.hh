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

#ifndef _AST_SYNAPSE_DECLS_HH_
# define _AST_SYNAPSE_DECLS_HH_

# include <list>
# include <string>
# include "synapse-decl.hh"
# include "synapse-node.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

/**
 * @brief declaration list
 */
class decls : public node {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf file descriptor structure
   */
  explicit decls(const FileDescriptor *desc);

  /**
   * @brief Constructor
   */
  decls(const std::initializer_list<decl *>& list)
    : _decls(list) {}

  /**
   * @brief Destructor
   */
  virtual ~decls() {}

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   */
  virtual std::string accept(visitor *visitor) const;

  /**
   * @brief Return the contained declarations list
   * @return a list
   */
  const std::list<decl *>& get_declarations() const {
    return _decls;
  }

private:
  std::list<decl *> _decls;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* _AST_SYNAPSE_DECLS_HH_ */