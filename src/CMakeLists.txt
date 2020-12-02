set (CMAKE_CXX_STANDARD 17)

set (NACRE_SRC_FILES
    "main.cpp"
    "nacre_method.cpp"
    "nacre_handle.cpp"
    "nacre_uri.cpp"
    "nacre_route.cpp"
    "nacre_application.cpp"
    "nacre_environment.cpp"
)

# set (CMAKE_CXX_COMPILER             "/usr/bin/clang++")

# BOOST
set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)
find_package (Boost 1.66 REQUIRED COMPONENTS system thread)

# third party
set (THIRD_PARTY_DIRS "../third_party/")
set (THIRD_PARTY_INCLUDE_DIRS ${THIRD_PARTY_DIRS})

# Magic Enum
# Do nothing

add_executable (nacre ${NACRE_SRC_FILES})
target_include_directories (nacre PUBLIC ${Boost_INCLUDE_DIRS} ${THIRD_PARTY_INCLUDE_DIRS})
target_link_libraries (nacre ${Boost_SYSTEM_LIBRARY} pthread)
