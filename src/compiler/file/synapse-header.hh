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

#ifndef _FILE_SYNAPSE_HEADER_HH_
# define _FILE_SYNAPSE_HEADER_HH_

# include <algorithm>
# include <string>
# include "synapse-interface.hh"

namespace synapse {
namespace compiler {
namespace file {

class header : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] params: parameter list
   */
  explicit header(params& params)
    : interface(params) {
  }

  /**
   * @brief Destructor
   */
  virtual ~header() {}

  /**
   * @brief Parse the entire tree
   * @param [in] stream: file stream
   * @param [in] node: node to parse
   */
  virtual void parse(stream& stream, const ast::decls *node) {
    std::string temp = std::string("_" + stream.get_name() + "_");
    std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    std::replace_if(temp.begin(), temp.end(), ispunct, '_');

    file::interface::parse(stream, node);
    stream << stream::endl;
    stream << "#ifndef " << temp << stream::endl;
    stream << "# define " << temp << stream::endl;
    stream << stream::endl;
    stream << "# include <stdint.h>" << stream::endl;
    stream << stream::endl;

    ast::decls::const_iterator it = node->begin();
    for (; it != node->end(); it++) {
      ast::decl *decl = it->second;
      decl->accept(stream, this);
    }
    stream << "#endif /* !" << temp << " */" << stream::endl;
  }

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return true on success, false otherwise
   */
  virtual void visite(stream& stream, const ast::include *node) {
    stream << "# include \"" << node->get_name() << "\"" << stream::endl;
  }
};

};  // namespace file
};  // namespace compiler
};  // namespace synapse

#endif /* !_FILE_SYNAPSE_INTERFACE_HH_ */
