AC_INIT([aaf],[1.1.4])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_MAINTAINER_MODE

AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_SYS_LARGEFILE

AC_CHECK_HEADERS([inttypes.h stdint.h])

AC_CHECK_LIB([expat],[XML_ExpatVersion],,[AC_MSG_ERROR([expat is required in order to build the AAF SDK])])

ss_impl="no"
if test x"$ss_impl" = x"no" ; then
	AC_CHECK_LIB([ole32],[StgOpenStorageOnILockBytes],[ss_impl=win32])
fi
if test x"$ss_impl" = x"no" ; then
	PKG_CHECK_MODULES([GSF],[libgsf-1 >= 1.9.0],[ss_impl=gsf;pkg_requires="$pkg_requires libgsf-1 >= 1.90"])
fi

AC_MSG_CHECKING([which structured storage implementation to use])
if test x"$ss_impl" = x"schemasoft" ; then
	AC_DEFINE([OM_USE_SCHEMASOFT_SS],[1],[Use the Schemasoft structured-storage implementation])
	AC_MSG_RESULT([Schemasoft])
elif test x"$ss_impl" = x"win32" ; then
	AC_DEFINE([OM_USE_WINDOWS_SS],[1],[Use the Windows structured-storage implementation])
	AC_MSG_RESULT([Win32 OLE])
elif test x"$ss_impl" = x"gsf" ; then
	AC_DEFINE([OM_USE_GSF_SS],[1],[Use the GSF structured-storage implementation])
	CPPFLAGS="$CPPFLAGS $GSF_CFLAGS"
	LIBS="$GSF_LIBS $LIBS"
	AC_MSG_RESULT([GSF])
	AC_CHECK_FUNC([gsf_outfile_msole_new_full])
else
	AC_MSG_ERROR([no suitable structured storage implementation found; try installing GNOME's libgsf])
fi

AM_CONDITIONAL([OM_USE_GSF_SS],[test x"$ss_impl" = x"gsf"])

AC_CHECK_LIB([uuid],[uuid_generate])
AC_CHECK_FUNC([uuid_generate],,[AC_MSG_ERROR([an implementation of uuid_generate() is required to build the AAF SDK])])

INCLUDES="$INCLUDES -I\${top_srcdir}/ref-impl/include"
INCLUDES="$INCLUDES -I\${top_srcdir}/ref-impl/include/ref-api"
AC_SUBST([INCLUDES])

AC_SUBST([pkg_requires])
AC_SUBST([pkg_conflicts])

AC_CONFIG_FILES([
Makefile
ref-impl/Makefile
ref-impl/include/Makefile
ref-impl/include/ref-api/Makefile
ref-impl/aaflib/Makefile
ref-impl/aafiid/Makefile
ref-impl/src/Makefile
ref-impl/src/OM/Makefile
ref-impl/src/impl/Makefile
ref-impl/src/com-api/Makefile
ref-impl/plugins/Makefile
aaf.pc
aaf-uninstalled.pc
])

AC_OUTPUT
