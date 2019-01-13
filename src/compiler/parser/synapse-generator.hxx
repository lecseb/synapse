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

# include <string>
# include <utility>
# include <vector>

namespace synapse {
namespace compiler {
namespace parser {

template<class T>
generator<T>::generator(int argc, char *argv[])
  : _params(std::vector<std::pair<std::string, std::string> >()) {
  std::string name = std::string();
  std::string value = std::string();
  std::string arg = std::string();

  for (int i = 0; i < argc; i++) {
    arg = argv[i];
    if (arg.size() > 2 && arg[0] == '-' && arg[1] == '-') {
      size_t position = arg.find("=");
      if (position == std::string::npos) {
	name = arg.substr(2, arg.size());
	value = std::string();
      } else {
	name = arg.substr(2, position);
	value = arg.substr(position + 1, arg.size());
      }
      _params.push_back(std::pair<std::string, std::string> (name, value));
    }
  }
}

template<class T>
bool generator<T>::Generate(const google::protobuf::FileDescriptor *desc,
    const std::string& params_str,
    google::protobuf::compiler::OutputDirectory *out,
    std::string *error) const {
  std::vector<std::pair<std::string, std::string> > all_params(_params);
  std::vector<std::pair<std::string, std::string> > params;
  google::protobuf::compiler::ParseGeneratorParameter(params_str, &params);
  all_params.insert(all_params.end(), params.begin(), params.end());

  T *def = new T(all_params, desc->name(), out);
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
