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

#include "synapse-params.hh"
#include "synapse-string.hh"

namespace synapse {
namespace compiler {

/**
 * @brief Parse a specific parameter
 * @param [in] str: parameter of the form --<name>=<value>
 * @return a pair of string <name,value>
 */
static std::pair<std::string, std::string> _parse_param(
    const std::string& str) {
  std::pair<std::string, std::string> param;

  size_t position = str.find("=");
  if (position == std::string::npos) {
    param.first = str;
    param.second = std::string();
  } else {
    param.first = str.substr(0, position - 1);
    param.second = str.substr(position + 1, str.size());
  }

  return param;
}

params::params(const std::string& str) {
  std::string tmp = str;

  while (tmp.size()) {
    std::pair<std::string, std::string> param;
    size_t position = tmp.find(",");

    if (position == std::string::npos) {
      param = _parse_param(tmp);
      tmp = std::string();
    } else {
      param = _parse_param(tmp.substr(0, position));
      tmp = tmp.substr(position + 1, tmp.size());
    }
    (*this)[param.first] = param.second;
  }
}

};  // namespace compiler
};  // namespace synapse
