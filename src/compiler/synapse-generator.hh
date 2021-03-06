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

#ifndef _SYNAPSE_GENERATOR_HH_
# define _SYNAPSE_GENERATOR_HH_

# include <map>
# include <string>
# include <google/protobuf/descriptor.h>
# include <google/protobuf/compiler/command_line_interface.h>
# include <google/protobuf/compiler/code_generator.h>

namespace synapse {
namespace compiler {

/**
 * @brief generator class: use to generate both source and header
 */
class generator : public google::protobuf::compiler::CodeGenerator {
public:
  /**
   * @brief Destructor
   */
  virtual ~generator() {}

  /**
   * @brief Generates code for the given proto file, generating one or more
   * files in the given output directory. A parameter to be passed to the
   * generator can be specified on the command line. This is intended to be
   * used to pass generator specific parameters. It is empty if no parameter
   * was given. ParseGeneratorParameter (below), can be used to accept
   * multiple parameters within the single parameter command line flag.
   * @return true if successful. Otherwise, sets *error to a description of
   * the problem (e.g. "invalid parameter") and returns false.
   */
  virtual bool Generate(const google::protobuf::FileDescriptor *desc,
      const std::string& params_str,
      google::protobuf::compiler::OutputDirectory *out,
      std::string *error) const;
};

};  // namespace compiler
};  // namespace synapse

#endif /* !_SYNAPSE_GENERATOR_HH_ */
