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

protodir= $(prefix)/include/synapse/proto
includedir= $(prefix)/include/synapse

proto_DATA = \
	bytes.proto \
	type.proto

include_HEADERS= \
	$(synapse_libdir)/synapse/bytes.synapse.h \
	$(synapse_libdir)/synapse/type.synapse.h

if synapse_SILENT
$(synapse_libdir)/synapse/%.synapse.h: %.proto $(synapse_cmpdir)/synapse-header
	@echo "  proto    $< -> $@"
	@cd ../ ; $(synapse_cmpdir)/synapse-header \
		--proto_path=proto \
		--synapse_out=synapse \
		--synapse_opt=export $<
else
$(synapse_libdir)/synapse/%.synapse.h: %.proto $(synapse_cmpdir)/synapse-header
	@cd ../ ; $(synapse_cmpdir)/synapse-header \
		--proto_path=proto \
		--synapse_out=synapse \
		--synapse_opt=export $<
endif

clean-local:
	rm -f $(noinst_HEADERS)

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS))))
