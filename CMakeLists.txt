project(BugExample)

cmake_minimum_required(VERSION 3.1)

find_package(Shiboken2 REQUIRED)
find_package(PySide2 REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(LIBRARY_OUTPUT_PATH  "${CMAKE_BINARY_DIR}/out")
set(EXECUTABLE_OUTPUT_PATH  "${CMAKE_BINARY_DIR}/out")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/BugExample.txt.in"
    "${CMAKE_CURRENT_BINARY_DIR}/BugExample.txt"
    @ONLY
)

set(wp ${CMAKE_CURRENT_BINARY_DIR}/wrap/BugExample)

set(BugExample_SRC
	"${wp}/bugexampleclass_vector3f_wrapper.cpp"
	"${wp}/bugexampleclass_vector3f_wrapper.h"
	"${wp}/bugexampleclass_wrapper.cpp"
	"${wp}/bugexampleclass_wrapper.h"
	"${wp}/bugexample_module_wrapper.cpp"
	"${wp}/bugexample_python.h"
)
set(BugExampleApi_SRC
	${CMAKE_CURRENT_SOURCE_DIR}/api/src/BugExample.cpp
)
set_property(SOURCE ${BugExample_SRC} PROPERTY SKIP_AUTOMOC ON)
add_custom_command(
    COMMAND ${SHIBOKEN_BINARY} --project-file=${CMAKE_CURRENT_BINARY_DIR}/BugExample.txt
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/BugExample.txt
    OUTPUT ${BugExample_SRC}
)

add_library(BugExample SHARED  ${BugExample_SRC} ${BugExampleApi_SRC})
target_link_libraries(BugExample
	PUBLIC
		Qt5::Core
		${SHIBOKEN_PYTHON_LIBRARIES}
		${SHIBOKEN_LIBRARY}
		${PYSIDE_LIBRARY}
)
target_include_directories(BugExample
	PUBLIC
		${PYSIDE_INCLUDE_DIR}
		${SHIBOKEN_INCLUDE_DIR}
		${SHIBOKEN_PYTHON_INCLUDE_DIR}
		${PYSIDE_INCLUDE_DIR}/QtCore
		${CMAKE_CURRENT_SOURCE_DIR}/api/include
		${CMAKE_CURRENT_SOURCE_DIR}/api/include/api
)
