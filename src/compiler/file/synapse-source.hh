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

#ifndef _FILE_SYNAPSE_SOURCE_HH_
# define _FILE_SYNAPSE_SOURCE_HH_

# include <string>
# include "synapse-interface.hh"
# include "synapse-string.hh"
# include "ast/synapse-decls.hh"

namespace synapse {
namespace compiler {
namespace file {

class source : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] params: parameter list
   */
  explicit source(params& params)
    : interface(params) {
  }

  /**
   * @brief Destructor
   */
  virtual ~source() {}

  /**
   * @brief Parse the entire tree
   * @param [in] stream: file stream
   * @param [in] node: node to parse
   */
  virtual void parse(stream& stream, const ast::decls *node) {
    std::string temp = strip_suffix(stream.get_name(), ".c");

    file::interface::parse(stream, node);
    stream << stream::endl;
    stream << "#include <synapse/alloc.h>" << stream::endl;
    stream << "#include <synapse/cond.h>" << stream::endl;
    stream << "#include \"" << temp << ".h\"" << stream::endl;
    stream << stream::endl;

    ast::decls::const_iterator it = node->begin();
    for (; it != node->end(); it++) {
      ast::decl *decl = it->second;
      decl->accept(stream, this);
    }
  }

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual void visite(stream&, const ast::include *) {
  }
};

};  // namespace file
};  // namespace compiler
};  // namespace synapse

#endif /* !_FILE_SYNAPSE_INTERFACE_HH_ */
