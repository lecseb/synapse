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

#include "synapse-generator.hh"

int main(int argc, char *argv[]) {
  google::protobuf::compiler::CommandLineInterface client;
  synapse::compiler::generator generator;

  client.RegisterGenerator("--synapse_out", "--synapse_opt",
    &generator, "generate all synapse file and handler");

  client.SetVersionInfo("libprotoc 3.5.1");

  return client.Run(argc, argv);
}
