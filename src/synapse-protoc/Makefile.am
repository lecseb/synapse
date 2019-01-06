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

bin_PROGRAMS= synapse-protoc

synapse_protoc_CXXFLAGS= \
	$(AM_CPPFLAGS) \
	$(libprotobuf_CFLAGS) \
	-I.

noinst_HEADERS= \
	synapse-generator.hh \
	ast/synapse-ast.hh \
	ast/synapse-data_factory.hh \
	ast/synapse-element.hh \
	ast/synapse-enum.hh \
	ast/synapse-field.hh \
	ast/synapse-include.hh \
	ast/synapse-label.hh \
	ast/synapse-struct.hh \
	ast/synapse-visitor.hh \
	visitor/synapse-file.hh \
	visitor/synapse-header.hh \
	visitor/synapse-stream.hh

synapse_protoc_SOURCES= \
	synapse-main.cc \
	ast/synapse-ast.cc \
	ast/synapse-data_factory.cc \
	ast/synapse-enum.cc \
	ast/synapse-field.cc \
	ast/synapse-function.cc \
	ast/synapse-include.cc \
	ast/synapse-label.cc \
	ast/synapse-struct.cc \
	visitor/synapse.cc \
	visitor/synapse-file.cc \
	visitor/synapse-header.cc \
	visitor/synapse-stream.cc

synapse_protoc_LDFLAGS= \
	-lprotoc \
	$(libprotobuf_LIBS)

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(synapse_protoc_SOURCES))))
