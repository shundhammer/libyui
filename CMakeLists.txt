# CMakeLists.txt for libyui toplevel (all libyui* packages)
#
# Usage:
#
#   mkdir build
#   cd build
#   cmake ..
#
#   make
#   sudo make install
#
# Restart with a clean build environment:
#   rm -rf build
#
# Show the complete compiler commands with all arguments:
#   make VERBOSE=1

cmake_minimum_required( VERSION 3.17 )
project( libyui-all )

# Options usage:
#
#   cmake -DBUILD_DOC=on -DBUILD_EXAMPLES=off ..

option( WITH_QT           "With libyui-qt* packages"                  on  )
option( WITH_NCURSES      "With libyui-ncurses* packages"             on  )
option( WITH_PKG          "With libyui-*-pkg packages"                on  )
option( WITH_GRAPH        "With libyui-*-graph packages"              on  )
option( WITH_REST_API     "With libyui-*rest-api* packages"           off )
option( WITH_BINDINGS     "With libyui-bindings packages"             off )

option( BUILD_SRC         "Build in src/ subdirectory"                on  )
option( BUILD_DOC         "Build class documentation"                 off )
# option( BUILD_EXAMPLES    "Build C++ -based libyui examples"          on  )
# option( BUILD_PKGCONFIG   "Build pkg-config support files"            on  )
# option( LEGACY_BUILDTOOLS "Install legacy cmake buildtools"           on  )
option( WERROR            "Treat all compiler warnings as errors"     on  )


#----------------------------------------------------------------------


# As of now, no support for /usr/local instead of /usr. But CMake DESTDIR works.
set( CMAKE_INSTALL_PREFIX /usr )

set( CMAKE_INSTALL_MESSAGE LAZY ) # Suppress "up-to-date" messages during "make install"


# Initialize compiler flags for all targets in all subdirectories
add_compile_options( "-Wall" )
add_compile_options( "-Os" )    # Optimize for size (overrides CMake's -O3 in RELEASE builds)

if ( WERROR )
  add_compile_options( "-Werror" )
endif()


set( FROM_TOPLEVEL_CMAKELISTS on )


#
# Descend into subdirectories
#

add_subdirectory( libyui )      # unconditional

if ( WITH_QT )
  add_subdirectory( libyui-qt )

  if ( WITH_PKG )
    add_subdirectory( libyui-qt-pkg )
  endif()

  if ( WITH_GRAPH )
    add_subdirectory( libyui-qt-graph )
  endif()
endif()


if ( WITH_NCURSES )
  add_subdirectory( libyui-ncurses )

  if ( WITH_PKG )
    add_subdirectory( libyui-ncurses-pkg )
  endif()
endif()


if ( WITH_REST_API )
  add_subdirectory( libyui-rest-api )

  if ( WITH_QT )
    add_subdirectory( libyui-qt-rest-api )
  endif()

  if ( WITH_NCURSES )
    add_subdirectory( libyui-ncurses-rest-api )
  endif()
endif()


if ( WITH_BINDINGS )
  add_subdirectory( libyui-bindings )
endif()

