/**
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

#ifndef _SYNAPSE_CONNECTION_SYNAPSE_H_
# define _SYNAPSE_CONNECTION_SYNAPSE_H_

enum type {
  dbus = 0,
  client_ssl = 1,
  server_ssl = 2
};

struct SearchRequest {
  uint32_t test;
  uint32_t tetst_2;
  struct s_synapse_bytes *test3;
};

struct SearchResponse {
  uint32_t test;
  uint32_t tetst_2;
  struct s_synapse_bytes *test3;
};

struct SearchRequest *SearchRequest0Search(
  struct SearchResponse *SearchResponse0);

#endif /* !_SYNAPSE_CONNECTION_SYNAPSE_H_ */
