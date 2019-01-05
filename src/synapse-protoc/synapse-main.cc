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

#include <google/protobuf/compiler/command_line_interface.h>
#include "synapse-generator.hh"

int main(int argc, char *argv[]) {
  static const std::string _cmd_out = "--synapse_out";
  static const std::string _cmd_brief = "Generate synapse headers/sources";

  google::protobuf::compiler::CommandLineInterface client;
  google::protobuf::compiler::Generator generator;

  client.SetVersionInfo("libprotoc 3.5.1");

  client.RegisterGenerator(_cmd_out, &generator, _cmd_brief);

  return client.Run(argc, argv);
}
