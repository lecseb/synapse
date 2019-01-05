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

#ifndef _HEADER_ADAPTOR_SYNAPSE_PREPROC_HH_
# define _HEADER_ADAPTOR_SYNAPSE_PREPROC_HH_

# include <string>
# include "synapse-ifile.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {
namespace adaptor {

class PreprocAdaptor {
public:
  /**
   * @brief Adapt a name into a preproc begin section
   * @param [in] file: file to write the converted data
   * @param [in] name: name to convert
   * @return an empty string on success, an explanation on error
   */
  static std::string begin(IFile& file, const std::string& name);

  /**
   * @brief Adapt a name into a preproc end section
   * @param [in] file: file to write the converted data
   * @param [in] name: name to convert
   * @return an empty string on success, an explanation on error
   */
  static std::string end(IFile& file, const std::string& name);
};

};  // namespace adaptor
};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_HEADER_ADAPTOR_SYNAPSE_PREPROC_HH_ */
