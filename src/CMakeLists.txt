add_subdirectory(amq_communication)
add_executable(${EXE_NAME} main.cpp)
target_link_libraries(${EXE_NAME} PUBLIC 
    ${LIBRARY_NAME})

if(NOT "$ENV{PAT_TOKEN}" STREQUAL "")
    message("The PAT_TOKEN environment variable exists - therefore we are running in a CI/CD Runner")
    message("Adjusting External Project URLS to use HTTPS")
    set(GITHUB_PACKAGE_URL https://$ENV{PAT_TOKEN}@github.com/ZenobeEnergy/sitecontroller-lock-)
else()
    message("Local environment detected - using ssh urls")
    message("Adjusting External Project URLS to use SSH")
    set(GITHUB_PACKAGE_URL git@github.com:ZenobeEnergy/sitecontroller-lock-)
endif()

########################################################
# apache qpid proton

ExternalProject_Add(qpid_ext
    GIT_REPOSITORY    ${GITHUB_PACKAGE_URL}qpid-proton.git
    GIT_TAG           0.36.0
    CMAKE_ARGS        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}
                      -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
                      -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
					  -DENABLE_JSONCPP=OFF
                      -DBUILD_WITH_CXX=ON
                      -DBUILD_CPP=ON
                      -DBUILD_CPP_03=OFF
                      -DBUILD_STATIC_LIBS=OFF
                      -DENABLE_WARNING_ERROR=OFF
                      #-DENABLE_UNDEFINED_ERROR=ON
                      #-DENABLE_LINKTIME_OPTIMIZATION=ON
                      #-DENABLE_HIDE_UNEXPORTED_SYMBOLS=OFF
                      -DENABLE_FUZZ_TESTING=OFF
                      -DENABLE_BENCHMARKS=OFF
                      -DBUILD_EXAMPLES=OFF
                      -DFUZZ_LONG_TESTS=OFF
                      -DFUZZ_REGRESSION_TESTS=OFF
                      -DBUILD_TESTING=OFF
                      -DBUILD_BINDINGS="" # no bindings enabled
                      -DSYSINSTALL_BINDINGS=ON
    TEST_COMMAND      "" # do not run tests
    UPDATE_COMMAND    "" # do not check git repo again
)

set(qpid_INCLUDE_DIR ${CMAKE_BINARY_DIR}/lib/include)
file(MAKE_DIRECTORY ${qpid_INCLUDE_DIR})  # Must exists

add_library(qpid SHARED IMPORTED)
set_target_properties(qpid PROPERTIES
    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}qpid-proton${CMAKE_SHARED_LIBRARY_SUFFIX}
    INTERFACE_INCLUDE_DIRECTORIES ${qpid_INCLUDE_DIR}
)
add_dependencies(qpid qpid_ext)
target_link_libraries(${LIBRARY_NAME} qpid)

add_library(qpid_core SHARED IMPORTED)
set_target_properties(qpid_core PROPERTIES
    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}qpid-proton-core${CMAKE_SHARED_LIBRARY_SUFFIX}
    INTERFACE_INCLUDE_DIRECTORIES ${qpid_INCLUDE_DIR}
)
add_dependencies(qpid_core qpid_ext)
target_link_libraries(${LIBRARY_NAME} qpid_core)

add_library(qpid_cpp SHARED IMPORTED)
set_target_properties(qpid_cpp PROPERTIES
    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}qpid-proton-cpp${CMAKE_SHARED_LIBRARY_SUFFIX}
    INTERFACE_INCLUDE_DIRECTORIES ${qpid_INCLUDE_DIR}
)
add_dependencies(qpid_cpp qpid_ext)
target_link_libraries(${LIBRARY_NAME} qpid_cpp)

add_library(qpid_proactor SHARED IMPORTED)
set_target_properties(qpid_proactor PROPERTIES
    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}qpid-proton-proactor${CMAKE_SHARED_LIBRARY_SUFFIX}
    INTERFACE_INCLUDE_DIRECTORIES ${qpid_INCLUDE_DIR}
)
add_dependencies(qpid_proactor qpid_ext)
target_link_libraries(${LIBRARY_NAME} qpid_proactor)

#############################################