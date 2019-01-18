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

#include "synapse.hh"
#include "synapse-stream.hh"
#include "ast/synapse-decls.hh"
#include "declaration/synapse.hh"
#include "definition/synapse.hh"

namespace synapse {
namespace compiler {
namespace parser {

file::header *synapse::factory::create_header(const std::string& name,
  const params& params, google::protobuf::compiler::OutputDirectory *output) {
  std::string filename = std::string(name + ".synapse.h");
  stream *file = new stream(filename, output);

  return new file::header(params, file, new definition::synapse(*file, params));
}

file::source *synapse::factory::create_source(const std::string& name,
  const params& params, google::protobuf::compiler::OutputDirectory *output) {
  std::string filename = std::string(name + ".synapse.c");
  stream *file = new stream(filename, output);

  return new file::source(params, file, new definition::synapse(*file, params),
    new declaration::synapse(*file));
}

synapse::synapse(const std::string& name, const params& params,
    google::protobuf::compiler::OutputDirectory *output)
  : _header(factory::create_header(name, params, output)),
    _source(factory::create_source(name, params, output)) {
}

synapse::~synapse() {
  delete _source;
  delete _header;
}

bool synapse::parse(const google::protobuf::FileDescriptor *desc) {
  ast::decls *decls = new ast::decls(desc);
  bool error = _header->parse(decls);
  error &= _source->parse(decls);
  delete decls;
  return error;
}

};  // namespace parser
};  // namespace compiler
};  // namespace synapse
