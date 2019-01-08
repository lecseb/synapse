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

#include <synapse/alloc.h>
#include <synapse/condition.h>
#include <synapse/log.h>
#include <synapse/synapse.h>

struct s_synapse {
};

struct s_synapse *s_synapse_new(const char *device)
{
  synapse_return_val_if_fail(device, NULL);

  struct s_synapse *synapse = synapse_malloc(sizeof(struct s_synapse));
  return synapse;
}

void s_synapse_free(struct s_synapse *synapse)
{
  synapse_return_if_fail(synapse);
  synapse_free(synapse);
}

int s_synapse_assign_loop(struct event_base *base)
{
  synapse_return_val_if_fail(base, -EINVAL);
  return 0;
}
