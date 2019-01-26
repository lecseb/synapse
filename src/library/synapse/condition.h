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

#ifndef _SYNAPSE_CONDITION_H_
# define _SYNAPSE_CONDITION_H_

# include <assert.h>
# include <errno.h>
# include <string.h>
//# include <synapse/log.h>

/**
 * @brief Function argument checker. Check the condition 'cond' and return the
 * value 'value' in order to avoid fastidious checking parameter sequences
 * @param [in] cond: condition to check
 * @param [in] value: value to return
 * @return the givent value when the condition failed, nothing otherwise
 */
# define synapse_return_val_if_fail(cond, value) { \
  do { \
    if (!(cond)) { \
      return value; \
    } \
  } while (0); \
}

/**
 * @brief Function argument checker. Check the condition 'cond' and return in
 * order to avoid fastidious checking parameter sequences
 * @param [in] cond: condition to check
 */
/* codecheck_ignore[SPACING] */
# define synapse_return_if_fail(cond) { \
  do { \
    if (!(cond)) { \
      return; \
    } \
  } while (0); \
}

/**
 * @brief Extend the standard assert by adding a string to underline the reason
 * of the assert
 */
# define synapse_assert(cond, str, ...) { \
  do { \
    if (!(cond)) { \
      assert(0); \
    } \
  } while (0); \
}

#endif /* !_SYNAPSE_CONDITION_H_ */
