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

noinst_LTLIBRARIES= libsynapse-proto.la

noinst_DATA= \
	connection.proto

noinst_HEADERS= \
	$(synapse_libdir)/synapse/connection.synapse.h

libsynapse_proto_la_SOURCES= \
	connection.synapse.c

if synapse_SILENT
%.synapse.c: %.proto $(top_srcdir)/src/compiler/synapse-header
	@echo "  proto    $< -> $(synapse_libdir)/synapse/$(basename $<).synapse.h"
	@$(top_srcdir)/src/compiler/synapse-header \
		--proto_path=$(synapse_libdir)/proto \
		--synapse_out=$(top_srcdir)/src/library/synapse $<
	@echo "  proto    $< -> $(basename $<).synapse.c"
	@touch $(top_srcdir)/src/library/proto/$(basename $<).synapse.c
else
%.synapse.c: %.proto $(top_srcdir)/src/compiler/synapse-protoc
	$(top_srcdir)/src/compiler/synapse-header \
		--proto_path=$(synapse_libdir)/proto \
		--synapse_out=$(top_srcdir)/src/library/synapse $<
	@touch $(top_srcdir)/src/library/proto/$(basename $<).synapse.c
endif

clean-local:
	rm -f $(libsynapse_proto_la_SOURCES) $(noinst_HEADERS)

# eval to create the coding style rule
$(eval $(call check, $(sort $(include_HEADERS) $(libsynapse_proto_SOURCES))))
