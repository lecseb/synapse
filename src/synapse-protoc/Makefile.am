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
	synapse-ifile.hh \
	header/synapse-iheader.hh \
	header/adaptor/synapse-adaptor.hh \
	header/adaptor/synapse-desc.hh \
	header/adaptor/synapse-enum.hh \
	header/adaptor/synapse-preproc.hh \
	header/adaptor/synapse-service.hh \
	header/adaptor/synapse-struct.hh \
	source/synapse-isource.hh \
	source/synapse-source.hh

synapse_protoc_SOURCES= \
	synapse-ifile.cc \
	synapse-main.cc \
	header/synapse-header.cc \
	header/adaptor/synapse-desc.cc \
	header/adaptor/synapse-enum.cc \
	header/adaptor/synapse-preproc.cc \
	header/adaptor/synapse-service.cc \
	header/adaptor/synapse-struct.cc \
	source/synapse-source.cc

synapse_protoc_LDFLAGS= \
	-lprotoc \
	$(libprotobuf_LIBS)

# eval to create the coding style rule
$(eval $(call check, $(sort $(noinst_HEADERS) $(synapse_protoc_SOURCES))))
