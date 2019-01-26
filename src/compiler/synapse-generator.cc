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

#include <map>
#include "synapse-error.hh"
#include "synapse-generator.hh"
#include "synapse-params.hh"
#include "api/synapse-header.hh"
#include "api/synapse-source.hh"
#include "ast/synapse-decls.hh"
#include "file/synapse-interface.hh"

namespace synapse {
namespace compiler {

bool generator::Generate(const google::protobuf::FileDescriptor *desc,
    const std::string& str, google::protobuf::compiler::OutputDirectory *out,
    std::string *error) const {
  ast::decls *decls = new ast::decls(desc);
  std::map<stream *, file::interface *> _files;
  params params(str);
  std::string name = strip_suffix(desc->name(), ".proto");

  /* api files: mandatory and the least */
  std::string api = "synapse-" + name;
  _files[new stream(std::string(api + ".h"), out)] = new api::header(params);
  _files[new stream(std::string(api + ".c"), out)] = new api::source(params);

  std::map<stream *, file::interface *>::iterator it = _files.begin();
  for (; it != _files.end(); it++) {
    stream *stream = it->first;
    file::interface *file = it->second;
    file->parse(*stream, decls);
    delete stream;
    delete file;
  }
  error::get_instance() >> *error;
  return error->size() ? false : true;
}

};  // namespace compiler
};  // namespace synapse
