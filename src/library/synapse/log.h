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

#ifndef _SYNAPSE_LOG_H_
# define _SYNAPSE_LOG_H_

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <syslog.h>

/**
 * @brief Level message logger
 * @param [in] format: format of the string to write
 * @param [in] ...: va_args
 */
void synapse_log(uint32_t level, const char *format, ...);

# define synapse_critical(fmt, ...) synapse_log(LOG_CRIT, fmt, # __VA_ARGS__)
# define synapse_debug(fmt, ...) synapse_log(LOG_DEBUG, fmt, # __VA_ARGS__)
# define synapse_error(fmt, ...) synapse_log(LOG_ERR, fmt, # __VA_ARGS__)
# define synapse_warning(fmt, ...) synapse_log(LOG_WARNING, fmt, # __VA_ARGS__)

/**
 * @brief Initialize the logger
 * @param [in] process: the process name to append to synapse library logging
 * @return 0 on success, an -errno on error
 */
int synapse_log_init(const char *process);

/**
 * @brief Initialize the logger
 * @param [in] levelt: one of LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR,
 * LOG_WARNING, LOG_NOTICE, LOG_INFO et LOG_DEBUG
 * @return 0 on success, an -errno on error
 * @note to receive all log, set log level to LOG_DEBUG
 */
static inline int synapse_log_set_level(uint32_t level)
{
  return setlogmask(LOG_UPTO(level));
}

/**
 * @brief Deinitialize the logger
 */
static inline void synapse_log_deinit(void)
{
  closelog();
}

#endif /* !_SYNAPSE_LOG_H_ */
