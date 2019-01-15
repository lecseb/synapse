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

#bin_PROGRAMS= synapse-header synapse-source

#noinst_HEADERS=

################################################################################
#                               header bin                                     #
################################################################################

#synapse_header_CXXFLAGS= \
#	$(synapse_CPPFLAGS) \
#	$(libprotobuf_CFLAGS) \
#	-I.

#synapse_header_SOURCES=
#	synapse-header.cc

#synapse_header_LDFLAGS= \
#	-lprotoc \
#	$(libprotobuf_LIBS) \
#	$(top_srcdir)/src/compiler/ast/libsynapse-ast.a

################################################################################
#                               source bin                                     #
################################################################################

#synapse_source_CXXFLAGS= $(synapse_header_CXXFLAGS)

#synapse_source_LDFLAGS= $(synapse_header_LDFLAGS)

#synapse_source_SOURCES=
#	synapse-source.cc

################################################################################
#                               coding style                                   #
################################################################################


bin_PROGRAMS= synapse-protoc

synapse_protoc_CXXFLAGS= \
	$(synapse_CPPFLAGS) \
	$(libprotobuf_CFLAGS) \
	-I.

noinst_HEADERS= \
	synapse-error.hh \
	parser/synapse.hh \
	parser/synapse-header.hh \
	parser/synapse-interface.hh \
	parser/synapse-params.hh \
	parser/synapse-source.hh \
	parser/synapse-stream.hh \
	parser/declaration/synapse.hh \
	parser/declaration/synapse-interface.hh \
	parser/definition/synapse.hh \
	parser/definition/synapse-interface.hh

synapse_protoc_SOURCES= \
	synapse-error.cc \
	synapse-generator.cc \
	synapse-protoc.cc \
	parser/synapse.cc \
	parser/synapse-header.cc \
	parser/synapse-params.cc \
	parser/synapse-source.cc \
	parser/synapse-stream.cc \
	parser/declaration/synapse.cc \
	parser/definition/synapse.cc

synapse_protoc_LDFLAGS= \
	-lprotoc \
	$(libprotobuf_LIBS) \
	$(top_srcdir)/src/compiler/ast/libsynapse-ast.a


# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(synapse_protoc_SOURCES))))
