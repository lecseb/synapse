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
	adaptor/synapse-ast.hh \
	adaptor/synapse-element.hh \
	adaptor/synapse-enum.hh \
	adaptor/synapse-field.hh \
	adaptor/synapse-label.hh \
	adaptor/synapse-struct.hh \
	adaptor/synapse-visitor.hh \
	visitor/synapse-default.hh \
	visitor/synapse-header.hh \
	visitor/synapse-stream.hh

synapse_protoc_SOURCES= \
	synapse-main.cc \
	visitor/synapse.cc \
	visitor/synapse-stream.cc

synapse_protoc_LDFLAGS= \
	-lprotoc \
	$(libprotobuf_LIBS)

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(synapse_protoc_SOURCES))))
