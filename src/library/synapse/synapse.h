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

#ifndef _SYNAPSE_SYNAPSE_H_
# define _SYNAPSE_SYNAPSE_H_

# include <event2/event.h>
# include <synapse/export.h>

/**
 * opaque structure
 */
synapse_export struct s_synapse;

/**
 * @brief Allocate a synapse instance
 * @param [in] device: name of the device to create
 * @return a valid pointer on success, NULL on error
 */
synapse_export struct s_synapse *s_synapse_new(const char *device);

/**
 * @brief Deallocate a specific synapse instance
 * @param [in] bytes: bytes instance to delete
 */
synapse_export void s_synapse_free(struct s_synapse *synapse);

/**
 * @brief Assign a loop to synapse
 * @param [in] loop: loop to assign
 * @return 0 on success, NULL on error
 * @note if no loop assigned, synapse will use an inaccessible or internal one
 */
synapse_export int s_synapse_assign_loop(struct event_base *base);

#endif /* !_SYNAPSE_SYNAPSE_H_ */
