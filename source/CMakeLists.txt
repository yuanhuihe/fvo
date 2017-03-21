
# 
# Configuration for all sub-projects
# 

# Generate version-header
string(TOUPPER ${META_PROJECT_NAME} META_PROJECT_NAME_UPPER)
configure_file(version.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/${META_PROJECT_NAME}/${META_PROJECT_NAME}-version.h)



# 
# Sub-projects
# 

# Libraries
set(IDE_FOLDER "")
 add_subdirectory(fvo)
 
# Examples
set(IDE_FOLDER "App")
 add_subdirectory(app)

set(IDE_FOLDER "Demo")
#add_subdirectory(test)

# Tests
set(IDE_FOLDER "Tests")
# add_subdirectory(tests)


# 
# Deployment
# 

# Deploy generated headers
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/${META_PROJECT_NAME} DESTINATION include COMPONENT dev)
