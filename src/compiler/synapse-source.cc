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

#include <typeinfo>
#include "parser/synapse-interface.hh"
#include "parser/synapse-generator.hh"
#include "parser/declaration/synapse-api.hh"

std::vector<synapse::compiler::parser::interface::option> _g_parsers = {
  synapse::compiler::parser::declaration::api::get_option(),
  synapse::compiler::parser::interface::option()
};

static const synapse::compiler::parser::interface::option&
_get_parser_option(int argc, char *argv[]) {
  for (int32_t i = 1; i < argc; i++) {
    std::string param = std::string(argv[i]);

    if (param.size() > 2 &&
	param[0] == '-' && param[1] == '-') {
      size_t position = param.find("=");
      std::string name = (position == std::string::npos) ?
	param.substr(0, param.size()) :
	param.substr(0, position);
      for (uint32_t j = 0; j < _g_parsers.size(); j++) {
	if (_g_parsers[j].cmd == name) {
	  return _g_parsers[j];
	}
      }
    }
  }
  return _g_parsers[_g_parsers.size() - 1];
}

int main(int argc, char *argv[]) {
  const synapse::compiler::parser::interface::option& opt =
    _get_parser_option(argc, argv);

  if (_g_parsers[_g_parsers.size() - 1] == opt) {
    std::cerr << argv[0] << ": unknown type of generation" << std::endl;
    return -EBADE;
  } else {
    google::protobuf::compiler::CommandLineInterface client;
    synapse::compiler::parser::generator<
      synapse::compiler::parser::declaration::api> gen(argc, argv);

    client.RegisterGenerator(opt.cmd, opt.cmd_opt, &gen, opt.brief);
    client.SetVersionInfo("libprotoc 3.5.1");
    return client.Run(argc, argv);
  }
}
