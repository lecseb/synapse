# This file is part of synapse.
#
# synapse is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# synapse is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with synapse.  If not, see <https://www.gnu.org/licenses/>.

include $(top_builddir)/script/checkpatch.mk

SUBDIRS= proto

lib_LTLIBRARIES= libsynapse.la

libsynapse_la_CFLAGS= \
	$(synapse_CFLAGS) \
	-I$(synapse_libdir)/

nobase_includedir= $(prefix)/include/synapse

nobase_include_HEADERS= \
	synapse/export.h

noinst_HEADERS= \
	synapse/alloc.h \
	synapse/condition.h \
	synapse/log.h

libsynapse_la_SOURCES= \
	synapse.c

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(nobase_include_HEADERS) \
  $(libsynapse_la_SOURCES))))

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libsynapse.pc
