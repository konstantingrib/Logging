cmake_minimum_required(VERSION 3.22)
project(Logging)

set(CMAKE_CXX_STANDARD 14)
add_executable(main.cpp)
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
#set(BOOST_LIBST log)
set(BOOST_LIBST thread filesystem date_time system log)

#find_package(Boost COMPONENTS ${BOOST_LIBS} REQUIRED)
find_package(Boost REQUIRED COMPONENTS log system thread filesystem)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    message("Boost VERSION: ${Boost_VERSION}")
    message("Boost INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message("Boost Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
    message("Boost LIBRARIES: ${Boost_LIBRARIES}")

    TARGET_LINK_LIBRARIES(Logging LINK_PUBLIC ${BOOST_LIBRARIES})
endif ()

target_link_libraries(Logging LINK_PUBLIC ${BOOST_LIBRARIES})