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
	$(synapse_CPPFLAGS) \
	$(libprotobuf_CFLAGS) \
	-I.

noinst_HEADERS= \
	synapse-error.hh \
	synapse-params.hh \
	synapse-stream.hh \
	synapse-string.hh \
	api/synapse-header.hh \
	api/synapse-source.hh \
	ast/synapse-decl.hh \
	ast/synapse-decls.hh \
	ast/synapse-enumeration.hh \
	ast/synapse-error.hh \
	ast/synapse-function.hh \
	ast/synapse-include.hh \
	ast/synapse-service.hh \
	ast/synapse-structure.hh \
	ast/synapse-type.hh \
	ast/synapse-visitor.hh \
	ast/functions/synapse-allocator.hh \
	ast/functions/synapse-dup.hh \
	ast/functions/synapse-free.hh \
	ast/functions/synapse-new.hh \
	ast/types/synapse-enumerator.hh \
	ast/types/synapse-enumeration.hh \
	ast/types/synapse-function.hh \
	ast/types/synapse-list.hh \
	ast/types/synapse-simple.hh \
	ast/types/synapse-structure.hh \
	file/synapse-header.hh \
	file/synapse-interface.hh \
	file/synapse-source.hh

synapse_protoc_SOURCES= \
	synapse-error.cc \
	synapse-generator.cc \
	synapse-params.cc \
	synapse-protoc.cc \
	synapse-stream.cc \
	synapse-string.cc \
	api/synapse-header.cc \
	api/synapse-source.cc \
	ast/synapse-decls.cc \
	ast/synapse-enumeration.cc \
	ast/synapse-error.cc \
	ast/synapse-function.cc \
	ast/synapse-include.cc \
	ast/synapse-structure.cc \
	ast/synapse-type.cc \
	ast/types/synapse-enumeration.cc \
	ast/types/synapse-function.cc \
	ast/types/synapse-list.cc \
	ast/types/synapse-simple.cc \
	ast/types/synapse-structure.cc

synapse_protoc_LDFLAGS= \
	-lprotoc \
	$(libprotobuf_LIBS)

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(synapse_protoc_SOURCES))))
