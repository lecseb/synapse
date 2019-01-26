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

#ifndef _SYNAPSE_ALLOC_H_
# define _SYNAPSE_ALLOC_H_

# include <stdio.h>
# include <stdlib.h>
# include <synapse/condition.h>

/**
 * @brief Same behavior than the standard #calloc + control memory and assert if
 * no memory available + memset to 0
 * @param [in] nmemb : nmemb elements
 * @param [in] size : size bytes for each element
 * @return a valid pointer on success, NULL on error
 */
static inline void *synapse_calloc(size_t nmemb, size_t size)
{
  void *pointer = calloc(nmemb, size);
  synapse_assert(pointer, "allocator failed '%s'", strerror(errno));
  memset(pointer, 0, size * nmemb);
  return pointer;
}

/**
 * @brief Check pointer before calling #free alloc function
 * @param [in] ptr : pointer to free
 */
static inline void synapse_free(void *pointer)
{
  synapse_return_if_fail(pointer);
  free(pointer);
}

/**
 * @brief Same behavior than the standard #malloc + control memory and assert if
 * no memory available + memset to 0
 * @param [in] size : size bytes to allocate
 * @return a valid pointer on success, NULL on error
 */
static inline void *synapse_malloc(size_t size)
{
  void *pointer = malloc(size);
  synapse_assert(pointer, "allocator failed '%s'", strerror(errno));
  memset(pointer, 0, size);
  return pointer;
}

/**
 * @brief Same behavior than the standard #realloc + control memory and assert
 * if no memory available + memset to 0
 * @param [in] ptr : initial pointer to modify
 * @param [in] size : size bytes to allocate
 * @return a valid pointer on success, NULL on error
 */
static inline void *synapse_realloc(void *ptr, size_t size)
{
  void *pointer = realloc(ptr, size);
  synapse_assert(pointer, "allocator failed '%s'", strerror(errno));
  memset(pointer, 0, size);
  return pointer;
}

#endif /* !_SYNAPSE_ALLOC_H_ */
