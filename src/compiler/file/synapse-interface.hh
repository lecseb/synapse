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

#ifndef _FILE_SYNAPSE_INTERFACE_HH_
# define _FILE_SYNAPSE_INTERFACE_HH_

# include <string>
# include "synapse-params.hh"
# include "synapse-stream.hh"
# include "ast/synapse-decls.hh"
# include "ast/synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace file {

class interface : public ast::visitor {
public:
  /**
   * @brief Constructor
   * @param [in] params: parameter list
   */
  explicit interface(params& params)
    : _params(params) {
  }

  /**
   * @brief Destructor
   */
  virtual ~interface() {}

  /**
   * @brief Parse the entire tree
   * @param [in] stream: file stream
   * @param [in] node: node to parse
   */
  virtual void parse(stream& stream, const ast::decls *) {
    stream << "/**" << stream::endl
      << " * synapse is free software: you can redistribute it and/or modify"
      << stream::endl
      << " * it under the terms of the GNU General Public License as published"
      << stream::endl
      << " * by the Free Software Foundation, either version 3 of the License,"
      << stream::endl
      << " * or (at your option) any later version." << stream::endl
      << " *" << stream::endl
      << " * synapse is distributed in the hope that it will be useful,"
      << stream::endl
      << " * but WITHOUT ANY WARRANTY; without even the implied warranty of"
      << stream::endl
      << " * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the"
      << stream::endl
      << " * GNU General Public License for more details." << stream::endl
      << " *" << stream::endl
      << " * You should have received a copy of the GNU General Public License"
      << stream::endl
      << " * along with synapse.  If not, see <https://www.gnu.org/licenses/>."
      << stream::endl << " */" << stream::endl;
  }

  /**
   * @brief Visite an error node
   * @param [in] stream: file stream
   * @param [in] node: node node to visite
   */
  virtual void visite(stream& stream, const ast::error *node) {
    error::get_instance() << node->get();
    stream << "#error " << node->get() << stream::endl;
  }

protected:
  params& _params;
};

};  // namespace file
};  // namespace compiler
};  // namespace synapse

#endif /* !_FILE_SYNAPSE_INTERFACE_HH_ */
