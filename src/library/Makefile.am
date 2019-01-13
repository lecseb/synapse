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

lib_LTLIBRARIES= libsynapse.la

nobase_includedir= $(includedir)/synapse
protodir= $(top_srcdir)/synapse/proto

nobase_proto_DATA = \
	proto/bytes.proto \
	proto/type.proto

libsynapse_la_CFLAGS= \
	$(synapse_CFLAGS) \
	-I$(top_srcdir)/src/library

nobase_include_HEADERS= \
	synapse/bytes.synapse.h \
	synapse/export.h \
	synapse/type.synapse.h

noinst_HEADERS= \
	synapse/alloc.h \
	synapse/condition.h \
	synapse/log.h

libsynapse_la_SOURCES= \
	synapse.c

if synapse_SILENT
synapse/%.synapse.h: proto/%.proto $(top_srcdir)/src/compiler/synapse-header
	@echo "  proto    $< -> $@"
	@LD_LIBRARY_PATH=/usr/local/lib \
		$(top_srcdir)/src/compiler/synapse-header \
			--proto_path=proto \
			--synapse_out=synapse \
			--synapse_opt=export $<
else
synapse/%.synapse.h: proto/%.proto $(top_srcdir)/src/compiler/synapse-header
	@LD_LIBRARY_PATH=/usr/local/lib \
		$(top_srcdir)/src/compiler/synapse-header \
			--proto_path=proto \
			--synapse_out=synapse \
			--synapse_opt=export $<
endif

clean-local:
	@rm synapse/*.synapse.h

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(nobase_include_HEADERS) \
  $(libsynapse_la_SOURCES))))

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libsynapse.pc
