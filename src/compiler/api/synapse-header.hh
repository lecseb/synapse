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

#ifndef _API_SYNAPSE_HEADER_HH_
# define _API_SYNAPSE_HEADER_HH_

# include <string>
# include "file/synapse-header.hh"

namespace synapse {
namespace compiler {
namespace api {

class header : public file::header {
public:
  /**
   * @brief Constructor
   * @param [in] params: parameter list
   */
  explicit header(params& params)
    : file::header(params) {
  }

  /**
   * @brief Destructor
   */
  virtual ~header() {}

  /**
   * @brief Visite an enumeration node
   * @param [in] stream: file stream
   * @param [in] node: node node to visite
   */
  virtual void visite(stream& stream, const ast::enumeration *node);

  /**
   * @brief Visite an structure node
   * @param [in] stream: file stream
   * @param [in] node: node to visite
   */
  virtual void visite(stream& stream, const ast::structure *node);
};

};  // namespace api
};  // namespace compiler
};  // namespace synapse

#endif /* !_API_SYNAPSE_HEADER_HH_ */
