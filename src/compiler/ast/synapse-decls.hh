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

# include <map>
# include <string>
# include "synapse-decl.hh"
# include "synapse-elements.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief declaration list
 */
class decls : public elements<decl> {
public:
  /**
   * @brief Map typedef
   */
  typedef std::map<uint32_t, decl *> map;
  typedef std::map<uint32_t, decl *>::const_iterator const_iterator;

  /**
   * @brief Constructor
   * @param [in] desc: protobuf file descriptor structure
   */
  explicit decls(const google::protobuf::FileDescriptor *desc);

  /**
   * @brief Destructor
   */
  virtual ~decls() {}

  /**
   * @brief Allow parser to add declaration inside the tree
   * @param [in] decl: declaration to add
   */
  void add_decl(decl *decl);
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_DECLS_HH_ */
