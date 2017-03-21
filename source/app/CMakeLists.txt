
# 
# External dependencies
# 

# find_package(THIRDPARTY REQUIRED)
find_package(Qt5 COMPONENTS Widgets Network)
find_package(Qt5LinguistTools)


# Target name
set(target fvoApp)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Language rc
SET(Lang_files ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/gui/fvoApp_zh.ts)
SET(Lang_en_files ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/gui/fvoApp_en.ts)
QT5_CREATE_TRANSLATION(LangSrcs ${Lang_files})
QT5_CREATE_TRANSLATION(LangenSrcs ${Lang_en_files})

add_definitions(-DUNICODE -D_UNICODE)


# Image, version rc
QT5_ADD_RESOURCES(fvo_app_QRC ${CMAKE_CURRENT_SOURCE_DIR}/gui/fvoApp.qrc)
if (MSVC)
 set(fvo_app_RC ${CMAKE_CURRENT_SOURCE_DIR}/gui/fvoApp.rc)
endif ()


# Exit here if required dependencies are not met
message(STATUS "App: ${target}")

# 
# Sources
# 

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include/${target}")
set(source_path  "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB headers
    "${include_path}/include/*.h"
    "${include_path}/include/*.hpp"
)

file(GLOB sources
    "${source_path}/*.cpp"
    "${source_path}/*.hpp"
    "${source_path}/*.h"
    "${source_path}/gui/*.cpp"
    "${source_path}/gui/*.hpp"
    "${source_path}/gui/*.h"
    "${source_path}/gui/fvoApp.ui"
)


# 
# Create executable
# 

# Build executable
add_executable(${target}  WIN32 ${sources} ${headers} ${fvo_app_QRC} ${fvo_app_RC} ${LangSrcs} ${LangenSrcs})

# Create namespaced alias
add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})

#qt5_use_modules(fvo_app Widgets Network )
# 
# Project options
# 

set_target_properties(${target}
    PROPERTIES
	${LIBUV_LIBRARY}
	${DEFAULT_PROJECT_OPTIONS}
	FOLDER "${IDE_FOLDER}"
)


# 
# Include directories
# 

target_include_directories(${target}
    PRIVATE
	${Qt5Widgets_INCLUDES}
	${Qt5Network_INCLUDES}
    ${PROJECT_SOURCE_DIR}/source/include
    ${PROJECT_SOURCE_DIR}/source/fvo/include
    ${PROJECT_BINARY_DIR}/source/fvo/include
	${PROJECT_SOURCE_DIR}/thirdparty/
    ${DEFAULT_INCLUDE_DIRECTORIES}
   )
message("    ${PROJECT_BINARY_DIR}/source/fvo/include")

# 
# Libraries
# 

target_link_libraries(${target}
    PRIVATE
	${Qt5Widgets_LIBRARIES}
	${Qt5Network_LIBRARIES}
	${META_PROJECT_NAME}::fvo
	${DEFAULT_LIBRARIES}
	)
		
# 
# Compile definitions
# 

target_compile_definitions(${target}
    PRIVATE
        ${DEFAULT_COMPILE_DEFINITIONS}
)


# 
# Compile options
# 

target_compile_options(${target}
    PRIVATE
        ${DEFAULT_COMPILE_OPTIONS}
)


# 
# Linker options
# 

target_link_libraries(${target}
    PRIVATE
        ${DEFAULT_LINKER_OPTIONS}
)


# 
# Deployment
# 

# Executable
install(TARGETS ${target}
    RUNTIME DESTINATION ${INSTALL_BIN} COMPONENT fvo_app
    BUNDLE  DESTINATION ${INSTALL_BIN} COMPONENT fvo_app
)

