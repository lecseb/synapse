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

bin_PROGRAMS= synapse-protoc

synapse_protoc_CXXFLAGS= \
	$(synapse_CPPFLAGS) \
	$(libprotobuf_CFLAGS) \
	-I.

noinst_HEADERS= \
	synapse-error.hh \
	parser/synapse.hh \
	parser/synapse-interface.hh \
	parser/synapse-params.hh \
	parser/synapse-stream.hh \
	parser/declaration/synapse.hh \
	parser/declaration/synapse-interface.hh \
	parser/definition/synapse.hh \
	parser/definition/synapse-interface.hh \
	parser/file/synapse-interface.hh \
	parser/file/synapse-header.hh \
	parser/file/synapse-source.hh

synapse_protoc_SOURCES= \
	synapse-error.cc \
	synapse-generator.cc \
	synapse-protoc.cc \
	parser/synapse.cc \
	parser/synapse-params.cc \
	parser/synapse-stream.cc \
	parser/declaration/synapse.cc \
	parser/definition/synapse.cc \
	parser/file/synapse-header.cc \
	parser/file/synapse-source.cc

synapse_protoc_LDFLAGS= \
	-lprotoc \
	$(libprotobuf_LIBS) \
	$(top_srcdir)/src/compiler/ast/libsynapse-ast.a


# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(synapse_protoc_SOURCES))))
