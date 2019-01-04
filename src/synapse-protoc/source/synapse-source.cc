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

#include "synapse-source.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace source {

Synapse::Synapse(const FileDescriptor *desc, OutputDirectory *out)
  : Source(desc, out, ".synapse.c") {
}

Synapse::~Synapse() {
}

bool Synapse::generate(const std::string&, std::string *) {
  const std::string header = strip_suffix(_full_name, ".c") + ".h";
  /* write preproc protection */
  _io_printer->Print(std::string("#include \"" + header + "\"\n").c_str());
  /* TODO: do the core parsing */
  _io_printer->Print("\n");
  return true;
}

};  // namespace source
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
