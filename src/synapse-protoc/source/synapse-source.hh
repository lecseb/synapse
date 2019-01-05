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

#ifndef _SOURCE_SYNAPSE_SOURCE_HH_
# define _SOURCE_SYNAPSE_SOURCE_HH_

# include <string>
# include <google/protobuf/stubs/common.h>
# include "synapse-isource.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace source {

class Synapse : public Source {
public:
  /**
   * @brief Generate a generic file
   * @param [in] desc: proto description class
   * @param [in] out: proto output description class
   */
  Synapse(const FileDescriptor *desc, OutputDirectory *out);

  /**
   * @brief Destructor
   */
  virtual ~Synapse();

  /**
   * @brief Generates code for the given proto file, generating one or more
   * files in the given output directory. A parameter to be passed to the
   * generator can be specified on the command line. This is intended to be used
   * to pass generator specific parameters. It is empty if no parameter was
   * given. ParseGeneratorParameter (below), can be used to accept multiple
   * parameters within the single parameter command line flag.
   * @return true if successful. Otherwise, sets *error to a description of the
   * problem (e.g. "invalid parameter") and returns false.
   */
  virtual bool generate(const std::string& param, std::string *error);
};

};  // namespace source
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_SOURCE_SYNAPSE_SOURCE_HH_ */
