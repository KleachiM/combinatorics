set(BOOST_ROOT /usr/local/Cellar/boost/1.80.0)
set(BOOST_INCLUDEDIR /usr/local/Cellar/boost/1.80.0/include)
set(BOOST_LIBRARY_DIR /usr/local/Cellar/boost/1.80.0/lib)

find_package(Boost 1.80.0 COMPONENTS system filesystem REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

add_executable(travelling_salesman main.cpp)