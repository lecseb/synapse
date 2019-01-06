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

#ifndef _AST_SYNAPSE_DATA_FACTORY_HH_
# define _AST_SYNAPSEH_DATA_FACTORY_H_

# include <string>
# include <google/protobuf/descriptor.h>

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

class DataFactory {
public:
  /**
   * @brief Create some contextual data for the AST
   * @param [in] ast: ast to modify
   */
  static void add_context_data(ast::Ast *ast);

private:
  /**
   * @brief Browse the Ast in order to add necessary include
   * @param [in] ast: ast to browse and modify
   */
  static void _add_context_includes(ast::Ast *ast);

  /**
   * @brief Browse the Ast in order to add necessary allocation function
   * @param [in] ast: ast to browse and modify
   */
  static void _add_context_functions(ast::Ast *ast);
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_AST_SYNAPSE_DATA_FACTORY_HH_ */
