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

#ifndef _PARSER_SYNAPSE_ERROR_HH_
# define _PARSER_SYNAPSE_ERROR_HH_

# include <string>

namespace synapse {
namespace compiler {
namespace parser {

class error {
public:
  /**
   * @brief Singleton entry point
   */
  static error& get_instance();

  /**
   * @brief Push error data into the error pipe
   * @param [in] data: data to add
   * @return an error instance 
   */
  error& operator<<(const std::string& data);

  /**
   * @brief Pop the contained error data into the string
   * @param [out] data: error from the handler
   * @return an error instance
   */
  error& operator>>(std::string& data);

private:
  /**
   * @brief Constructor
   */
  error()
    : _error(std::string()) {}

  std::string _error;
};

};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_SYNAPSE_ERROR_HH_ */
