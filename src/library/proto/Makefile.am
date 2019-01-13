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
	bytes.proto \
	connection.proto \
	type.proto

noinst_HEADERS= \
	synapse/bytes.synapse.h \
	synapse/connection.synapse.h \
	synapse/type.synapse.h

libsynapse_proto_la_SOURCES= \
	bytes.synapse.c \
	connection.synapse.c

if synapse_SILENT
synapse/%.synapse.h: %.proto $(top_srcdir)/src/compiler/synapse-header
	@echo "  proto    $< -> $(basename $<).synapse.h"
	@LD_LIBRARY_PATH=/usr/local/lib $(top_srcdir)/src/compiler/synapse-header \
		--proto_path=. \
		--synapse_out=synapse \
		--synapse_opt=export $<

%.synapse.c: %.proto
	@echo "  proto    $< -> $(basename $<).synapse.c"
	@touch $(top_srcdir)/src/library/proto/$(basename $<).synapse.c
else
synapse/%.synapse.h: %.proto $(top_srcdir)/src/compiler/synapse-header
	LD_LIBRARY_PATH=/usr/local/lib $(top_srcdir)/src/compiler/synapse-header \
		--proto_path=. \
		--synapse_out=synapse
		--synapse_opt=export $<
	@touch $(top_srcdir)/src/library/proto/$(basename $<).synapse.c

%.synapse.c:
	@touch $(top_srcdir)/src/library/proto/$(basename $<).synapse.c

endif

all-local: $(noinst_HEADERS)

clean-local:
	rm -f $(libsynapse_proto_la_SOURCES) $(noinst_HEADERS)

# eval to create the coding style rule
$(eval $(call check, $(sort $(include_HEADERS) $(libsynapse_proto_SOURCES))))
