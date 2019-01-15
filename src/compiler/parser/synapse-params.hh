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

#ifndef _PARSER_SYNAPSE_OPTIONS_HH_
# define _PARSER_SYNAPSE_OPTIONS_HH_

# include <map>
# include <string>

namespace synapse {
namespace compiler {
namespace parser {

/**
 * @brief Strip a suffix from a string given in parameter
 * @param [in] var: var to strip
 * @param [in] suffix: suffix to find and remove
 * @return a string
 */
std::string strip_suffix(const std::string& var, const std::string& suffix);

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

};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_SYNAPSE_OPTIONS_HH_ */
