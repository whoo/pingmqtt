#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(PingMQTT,1.0,dd@gmail.com)
AM_INIT_AUTOMAKE([pingmqtt], [1.0])

#AC_CONFIG_SRCDIR([config.h.in])
#AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_CONFIG_SRCDIR([src])
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lmosquitto':
AC_CHECK_LIB([mosquitto], [mosquitto_lib_init])
AC_CHECK_LIB([mosquitto], [mosquitto_connect])
AC_CHECK_LIB([mosquitto], [mosquitto_publish])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h netdb.h stdlib.h string.h sys/socket.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_FUNC_MALLOC

# Checks for library functions.
AC_CHECK_FUNCS([alarm gethostbyname memset select socket strerror])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT

