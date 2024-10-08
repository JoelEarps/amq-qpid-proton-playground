set(LIBRARY_SOURCES "amq_container.cpp")
set(LIBRARY_HEADERS "amq_container.h")

add_library(${LIBRARY_NAME} STATIC 
${LIBRARY_SOURCES}
${LIBRARY_HEADERS})

target_include_directories(${LIBRARY_NAME} PUBLIC 
"./")
