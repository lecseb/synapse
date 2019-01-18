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
	-I$(synapse_cmpdir)/

noinst_HEADERS= \
	synapse-adaptor.hh \
	synapse-decl.hh \
	synapse-decls.hh \
	synapse-enumeration.hh \
	synapse-error.hh \
	synapse-include.hh \
	synapse-structure.hh \
	synapse-visitor.hh \
	service/synapse-factory.hh \
	service/synapse-function.hh \
	service/synapse-service.hh \
	service/allocator/synapse-allocator.hh \
	service/allocator/synapse-decl.hh \
	service/allocator/synapse-decls.hh \
	service/allocator/synapse-dup.hh \
	service/allocator/synapse-error.hh \
	service/allocator/synapse-free.hh \
	service/allocator/synapse-new.hh \
	service/allocator/synapse-visitor.hh

libsynapse_ast_a_SOURCES= \
	synapse-adaptor.cc \
	synapse-decls.cc \
	synapse-enumeration.cc \
	synapse-error.cc \
	synapse-include.cc \
	synapse-structure.cc \
	service/synapse-factory.cc \
	service/allocator/synapse-allocator.cc \
	service/allocator/synapse-dup.cc \
	service/allocator/synapse-error.cc \
	service/allocator/synapse-free.cc \
	service/allocator/synapse-new.cc \
	service/synapse-function.cc

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(libsynapse_ast_a_SOURCES))))
