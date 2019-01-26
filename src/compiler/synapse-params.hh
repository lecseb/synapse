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

#ifndef _SYNAPSE_PARAMS_HH_
# define _SYNAPSE_PARAMS_HH_

# include <map>
# include <string>

namespace synapse {
namespace compiler {

/**
 * @brief Params type
 */
class params : public std::map<std::string, std::string> {
public:
  /**
   * @brief Constructor
   * @param [in] str: parameter string to split by ','
   */
  explicit params(const std::string& str);

  /**
   * @brief Destructor
   */
  virtual ~params() {}
};

};  // namespace compiler
};  // namespace synapse

#endif /* !_SYNAPSE_PARAMS_HH_ */
