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

AC_INIT([libsynapse], [0.1])
AM_INIT_AUTOMAKE([subdir-objects foreign])
AM_CONFIG_HEADER([config.h])
#AM_SILENT_RULES([yes])

# Check programs
AC_PROG_CC
AC_PROG_CXX
AM_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LIBTOOL(libtool)

# Checks header files
AC_HEADER_STDC

# Check library
PKG_CHECK_MODULES([dbus], [dbus-1])
PKG_CHECK_MODULES([libcrypto], [libcrypto])
PKG_CHECK_MODULES([libevent], [libevent])
PKG_CHECK_MODULES([libevent_openssl], [libevent_openssl])
PKG_CHECK_MODULES([libssl], [libssl])
PKG_CHECK_MODULES([libprotobuf], [protobuf])

my_CPPFLAGS="\
-W \
-Werror \
-Wall \
-Wchar-subscripts \
-Wformat-security \
-Wmissing-declarations \
-Wpointer-arith \
-Wshadow \
-Wsign-compare \
-Wtype-limits \
-I`pwd`/src \
"

# debug mode activation
AC_ARG_ENABLE(debug, AS_HELP_STRING([--enable-debug]),
	[extra_CPPFLAGS="-g -ggdb"], [extra_CPPFLAGS="-O3"])

AC_SUBST([AM_CPPFLAGS], ["$AM_CPPFLAGS $my_CPPFLAGS $extra_CPPFLAGS"])

# Output generated file
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	src/synapse-protoc/Makefile
])

AC_OUTPUT

AC_MSG_RESULT([
    $PACKAGE $VERSION
    ==========================

    prefix:              ${prefix}
    sysconfdir:          ${sysconfdir}
    libdir:              ${libdir}
    rootlibdir:          ${rootlibdir}
    includedir:          ${includedir}
    bindir:              ${bindir}

    C compiler:          ${CC}
    CFLAGS:              ${AM_CPPFLAGS}
    LDFLAGS:             ${AM_LDFLAGS}
])
