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

#include "synapse-preproc.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {
namespace adaptor {

std::string PreprocAdaptor::begin(IFile& file, const std::string& name) {
  std::string temp = std::string("_GENERATE_" + name);
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');

  file << "#ifndef " << temp << IFile::endl;
  file << "# define " << temp << IFile::endl;
  file << IFile::endl;

  return std::string();
}

std::string PreprocAdaptor::end(IFile& file, const std::string& name) {
  std::string temp = std::string("_GENERATE_" + name);
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');

  file << "#endif /* !" << temp << " */" << IFile::endl;
  return std::string();
}

};  // namespace adaptor
};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
