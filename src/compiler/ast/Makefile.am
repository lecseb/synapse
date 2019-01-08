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
	synapse-ast.hh \
	synapse-element.hh \
	synapse-enum.hh \
	synapse-field.hh \
	synapse-function.hh \
	synapse-include.hh \
	synapse-label.hh \
	synapse-struct.hh \
	synapse-visitor.hh

libsynapse_ast_a_SOURCES= \
	synapse-ast.cc \
	synapse-enum.cc \
	synapse-field.cc \
	synapse-function.cc \
	synapse-include.cc \
	synapse-label.cc \
	synapse-struct.cc

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(libsynapse_ast_a_SOURCES))))
