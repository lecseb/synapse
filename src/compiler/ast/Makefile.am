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

noinst_LIBRARIES= libsynapse-ast.a

libsynapse_ast_a_CXXFLAGS= \
	$(synapse_CPPFLAGS) \
	$(libprotobuf_CFLAGS) \
	-I$(synapse_compdir)/

noinst_HEADERS= \
	synapse-composite.hh \
	synapse-decl.hh \
	synapse-decls.hh \
	synapse-elements.hh \
	synapse-enumeration.hh \
	synapse-function.hh \
	synapse-include.hh \
	synapse-interface.hh \
	synapse-service.hh \
	synapse-structure.hh \
	synapse-visitor.hh

libsynapse_ast_a_SOURCES= \
	synapse-composite.cc \
	synapse-decl.cc \
	synapse-decls.cc \
	synapse-enumeration.cc \
	synapse-function.cc \
	synapse-include.cc \
	synapse-service.cc \
	synapse-structure.cc

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(libsynapse_ast_a_SOURCES))))
