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

#include "synapse-string.hh"

namespace synapse {
namespace compiler {

std::string strip_suffix(const std::string& var, const std::string& suffix) {
  if (suffix.size() > var.size())
    return var;
  if (var.compare(var.size() - suffix.size(), suffix.size(), suffix) == 0)
    return var.substr(0, var.size() - suffix.size());
  return std::string("");
}

std::string strip_prefix(const std::string& var, const std::string& prefix) {
  if (prefix.size() > var.size())
    return var;
  if (var.compare(0, prefix.size(), prefix) == 0)
    return var.substr(prefix.size(), var.size() - prefix.size());
  return std::string("");
}

};  // namespace compiler
};  // namespace synapse
