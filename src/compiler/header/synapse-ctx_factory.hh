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

#ifndef _HEADER_SYNAPSE_CTX_FACTORY_HH_
# define _HEADER_SYNAPSE_CTX_FACTORY_HH_

# include "ast/synapse-ast.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {

class CtxFactory {
public:
  /**
   * @brief Generate header declaration for all usefull callback that structure
   * will need
   * @param [in] root: root of the ast tree
   * @param [in] node: node to parse
   */
  static void generate_callback_from_structure(ast::Ast *root,
    ast::Struct *node);

  /**
   * @brief Generate header declaration for all usefull callback that
   * enumeration will need
   * @param [in] root: root of the ast tree
   * @param [in] node: node to parse
   */
  static void generate_callback_from_enum(ast::Ast *root, ast::Enum *node);

private:
  /**
   * @brief Generate allocator declaration for all usefull callback that
   * structure will need
   * @param [in] root: root of the ast tree
   * @param [in] node: node to parse
   */
  static void _generate_allocator_callback(ast::Ast *root, ast::Struct *node);
};

};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_HEADER_SYNAPSE_CTX_FACTORY_HH_ */
