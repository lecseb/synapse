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

bin_PROGRAMS= synapse-header

synapse_header_CXXFLAGS= \
	$(synapse_CPPFLAGS) \
	$(libprotobuf_CFLAGS) \
	-I.

noinst_HEADERS= \
	synapse-generator.hh \
	synapse-string.hh \
	ast/synapse-ast.hh \
	ast/synapse-element.hh \
	ast/synapse-enum.hh \
	ast/synapse-field.hh \
	ast/synapse-function.hh \
	ast/synapse-include.hh \
	ast/synapse-label.hh \
	ast/synapse-struct.hh \
	ast/synapse-visitor.hh \
	visitor/header/synapse.hh \
	visitor/header/synapse-header.hh \
	visitor/synapse-file.hh \
	visitor/synapse-stream.hh

noinst_SOURCES=
# synapse-main.cc \
# ast/synapse-ast.cc \
# ast/synapse-enum.cc \
# ast/synapse-field.cc \
# ast/synapse-function.cc \
# ast/synapse-include.cc \
# ast/synapse-label.cc \
# ast/synapse-struct.cc \
# visitor/synapse.cc \
# visitor/synapse-file.cc \
# visitor/synapse-header.cc \
# visitor/synapse-stream.cc

synapse_header_LDFLAGS= \
	-lprotoc \
	$(libprotobuf_LIBS)

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(synapse_header_SOURCES))))
