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

#include <synapse/condition.h>
#include <synapse/synapse-log.h>

void synapse_log(uint32_t level, const char *format, ...)
{
  synapse_return_if_fail(format);

  va_list arg_list;
  va_start(arg_list, format);
  vsyslog(level, format, arg_list);
  va_end(arg_list);
}

int synapse_log_init(const char *process, uint32_t bitfield)
{
  synapse_return_val_if_fail(process, -EINVAL);

  char full_name[128] = { 0, };
  if (snprintf(full_name, 128, "%s::synapse", process) < 0) {
    openlog(NULL, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
    synapse_warning("failed to create the proper name");
    return -errno;
  }
  setlogmask(LOG_UPTO(bitfield));
  openlog(full_name, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
  return 0;
}
