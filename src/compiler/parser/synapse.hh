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

#ifndef _PARSER_SYNAPSE_HH_
# define _PARSER_SYNAPSE_HH_

# include <map>
# include <string>
# include "synapse-interface.hh"
# include "synapse-params.hh"
# include "file/synapse-header.hh"
# include "file/synapse-source.hh"

namespace synapse {
namespace compiler {
namespace parser {

class synapse : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] name: name of the file to generate
   * @param [in] params: user params
   * @param [in] output: output directory representation
   */
  synapse(const std::string& name, const params& params,
    google::protobuf::compiler::OutputDirectory *output);

  /**
   * @brief Destructor
   */
  virtual ~synapse();

  /**
   * @brief Parse the protobuf AST and generate our own
   * @param [in] descriptor: entry node of the ast
   * @return true on success, false on error
   * @note see @error class in order to get all error message
   */
  virtual bool parse(const google::protobuf::FileDescriptor *descriptor);

private:
  /**
   * @brief factory class
   */
  class factory {
  public:
    /**
     * @brief create a header instance
     * @param [in] name: name of the header
     * @param [in] params: parameters list
     * @param [in] output: output file representation
     * @return a valid pointer
     */
    static file::header *create_header(const std::string& name,
      const params& params,
      google::protobuf::compiler::OutputDirectory *output);

    /**
     * @brief create a header instance
     * @param [in] name: name of the header
     * @param [in] params: parameters list
     * @param [in] output: output file representation
     * @return a valid pointer
     */
    static file::source *create_source(const std::string& name,
      const params& params,
      google::protobuf::compiler::OutputDirectory *output);
  };

  file::header *_header;
  file::source *_source;
};

};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_SYNAPSE_HH_ */
