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

#ifndef _AST_SERVICE_SYNAPSE_FACTORY_HH_
# define _AST_SERVICE_SYNAPSE_FACTORY_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include "ast/service/synapse-service.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace svcs {

class factory {
public:
  /**
   * @brief Check if the name is handle by the factory
   * @param [in] name: name to check
   * @return true on success, false otherwise
   */
  static bool check_name(const std::string& name);

  /**
   * @brief Create the service according to the description structure
   * @param [in] desc: protobuf service description structure
   * @return a valid pointer on success, NULL on error
   */
  static ast::service *create_service(
    const google::protobuf::ServiceDescriptor *desc);
};

};  // namespace svcs
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* !_AST_SERVICE_SYNAPSE_FACTORY_HH_ */
