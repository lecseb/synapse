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

#include <list>
#include "synapse-error.hh"
#include "synapse-generator.hh"
#include "parser/synapse.hh"
#include "parser/synapse-interface.hh"
#include "parser/synapse-params.hh"

namespace synapse {
namespace compiler {

bool generator::Generate(const google::protobuf::FileDescriptor *descriptor,
    const std::string& str, google::protobuf::compiler::OutputDirectory *output,
    std::string *error) const {
  std::list<parser::interface *>::iterator it;
  parser::params params(str);
  std::list<parser::interface *> parsers = std::list<parser::interface *>();
  bool ret = true;

  std::string basename = synapse::compiler::parser::strip_suffix(
    descriptor->name(), ".proto");
  parsers.push_back(new parser::synapse(basename, params, output));
  // if (params.find("--with-dbus") != params.end())
  //   parsers.push_back(new dbus(basename, params, output));
  // if (params.find("--with-protobuf") != params.end())
  //   parsers.push_back(new protobuf(basename, params, output));

  for (it = parsers.begin(); it != parsers.end(); it++) {
    ret &= (*it)->parse(descriptor);
    delete (*it);
  }

  error::get_instance() >> *error;
  return ret;
}

};  // namespace compiler
};  // namespace synapse
