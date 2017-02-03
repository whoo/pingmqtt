#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(PingMQTT,1.0,dd@gmail.com)
AM_INIT_AUTOMAKE([pingmqtt], [1.0])

#AC_CONFIG_SRCDIR([config.h.in])
#AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lmosquitto':
AC_CHECK_LIB([mosquitto], [mosquitto_lib_init])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h netdb.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([alarm gethostbyname memset socket])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
