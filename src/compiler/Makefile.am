# This file is part of synapse.

# synapse is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# synapse is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with synapse.  If not, see <https://www.gnu.org/licenses/>.

include $(top_builddir)/script/cpplint.mk

SUBDIRS= ast

bin_PROGRAMS= synapse-header

synapse_header_CXXFLAGS= \
	$(synapse_CPPFLAGS) \
	$(libprotobuf_CFLAGS) \
	-I$(synapse_compdir)/include

noinst_HEADERS= \
	synapse-file.hh \
	synapse-stream.hh \
	synapse-string.hh \
	header/synapse.hh \
	header/synapse-ctx_factory.hh \
	header/synapse-generator.hh \
	header/synapse-header.hh

synapse_header_SOURCES= \
	synapse-file.cc \
	synapse-stream.cc \
	header/synapse.cc \
	header/synapse-ctx_factory.cc \
	header/synapse-header.cc \
	header/synapse-main.cc

synapse_header_LDFLAGS= \
	-lprotoc \
	$(libprotobuf_LIBS) \
	$(synapse_compdir)/ast/libsynapse-ast.a

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(synapse_header_SOURCES))))
