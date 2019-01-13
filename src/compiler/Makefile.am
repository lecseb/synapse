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
	-I.

noinst_HEADERS= \
	parser/synapse-generator.hh \
	parser/synapse-interface.hh \
	parser/synapse-stream.hh \
	parser/declaration/synapse-declaration.hh \
	parser/definition/synapse-api.hh \
	parser/definition/synapse-definition.hh \
	parser/definition/synapse-factory.hh

synapse_header_SOURCES= \
	synapse-header.cc \
	parser/synapse-stream.cc \
	parser/declaration/synapse-declaration.cc \
	parser/definition/synapse-api.cc \
	parser/definition/synapse-definition.cc \
	parser/definition/synapse-factory.cc

synapse_header_LDFLAGS= \
	-lprotoc \
	$(libprotobuf_LIBS) \
	$(top_srcdir)/src/compiler/ast/libsynapse-ast.a

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(synapse_header_SOURCES))))
