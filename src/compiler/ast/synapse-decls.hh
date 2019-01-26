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
# include <vector>
# include "ast/synapse-decl.hh"

namespace synapse {
namespace compiler {
namespace ast {

class enumeration;
class structure;

/**
 * @brief declaration container definition
 */
class decls : public std::map<std::string, decl *> {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf file descriptor
   */
  explicit decls(const google::protobuf::FileDescriptor *desc);

  /**
   * @brief Destructor
   */
  virtual ~decls();

  /**
   * @brief Find and return the declaration of an enumeration by
   * its name
   * @param [in] name: name of the structure to find
   * @return a valid pointer on success, NULL on error
   */
  virtual const ast::enumeration *get_enumeration(
    const std::string& name) const;

  /**
   * @brief Find and return the declaration of a structure by
   * its name
   * @param [in] name: name of the structure to find
   * @return a valid pointer on success, NULL on error
   */
  virtual const ast::structure *get_structure(const std::string& name) const;

private:
  /**
   * @brief Create a structure
   * @param [in] desc: structure descriptor
   */
  void parse(const google::protobuf::Descriptor *desc);

  /**
   * @brief Create an enumeration
   * @param [in] desc: enumeration descriptor
   */
  void parse(const google::protobuf::EnumDescriptor *desc);

  /**
   * @brief Create an include
   * @param [in] desc: file descriptor
   */
  void parse(const google::protobuf::FileDescriptor *desc);

  std::vector<ast::structure *> _deps;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_DECLS_HH_ */
