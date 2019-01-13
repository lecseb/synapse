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

#ifndef _PARSER_SYNAPSE_GENERATOR_HXX_
# define _PARSER_SYNAPSE_GENERATOR_HXX_

# include <map>
# include <string>

namespace synapse {
namespace compiler {
namespace parser {

template<class T>
generator<T>::generator(int argc, char *argv[])
  : _params(std::map<std::string, std::string>()) {
  for (int i = 0; i < argc; i++) {
    std::string arg = argv[i];
    if (arg.size() > 2 && arg[0] == '-' && arg[1] == '-') {
      size_t position = arg.find("=");
      if (position == std::string::npos)
	_params[arg.substr(2, arg.size())] = std::string();
      else
	_params[arg.substr(2, position - 2)] =
	  arg.substr(position + 1, arg.size());
    }
  }
}

template<class T>
bool generator<T>::Generate(const google::protobuf::FileDescriptor *desc,
    const std::string&,
    google::protobuf::compiler::OutputDirectory *out,
    std::string *error) const {
  T *def = new T(_params, desc->name(), out);
  bool ret = def->parse(desc);
  if (!ret)
    error::get_instance() >> *error;
  delete def;
  return ret;
}

};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_SYNAPSE_GENERATOR_HXX_ */
