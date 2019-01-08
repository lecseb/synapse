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

#ifndef _SYNAPSE_BYTES_H_
# define _SYNAPSE_BYTES_H_

# include <synapse/export.h>

/**
 * opaque structure
 */
synapse_export struct s_synapse_bytes;

/**
 * @brief Allocate a new byte array
 * @param [in] size: number of byte in the array
 * @param [in] data: array content
 * @return a valid pointer on success, NULL on error
 */
synapse_export struct s_synapse_bytes *s_synapse_bytes_new(uint32_t size,
  uint8_t *data);

/**
 * @brief Deallocate a byte array
 * @param [in] bytes: bytes instance to delete
 */
synapse_export void s_synapse_bytes_free(struct s_synapse_bytes *bytes);

#endif /* !_SYNAPSE_BYTES_H_ */
