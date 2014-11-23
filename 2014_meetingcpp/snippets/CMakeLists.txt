# CMakeLists.txt
# Date: 2014-10-26
# Author: Karsten Ahnert (karsten.ahnert@gmx.de)
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or
# copy at http://www.boost.org/LICENSE_1_0.txt)
#


find_package ( Boost REQUIRED )

if ( CMAKE_COMPILER_IS_GNUCXX )
    set ( CMAKE_CXX_FLAGS "-std=c++14" )        ## Optimize
endif ()

include_directories ( ${Boost_INCLUDE_DIRS} )

add_executable ( examples_io examples_io.cpp )
add_executable ( logistic_map logistic_map.cpp )
add_executable ( functions functions.cpp )
add_executable ( newton_simple newton_simple.cpp )