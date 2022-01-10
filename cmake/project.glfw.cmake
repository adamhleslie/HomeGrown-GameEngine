# Find GLFW - use add_library_glfw to link
find_path(GLFW3_INCLUDE_DIR "GLFW/glfw3.h" PATHS "Libraries/glfw/Include" NO_DEFAULT_PATH)
find_library(GLFW3_LIBRARY_DEBUG "glfw3" PATHS "Libraries/glfw/Debug" NO_DEFAULT_PATH)
find_library(GLFW3_LIBRARY_RELEASE "glfw3" PATHS "Libraries/glfw/Release" NO_DEFAULT_PATH)
if ((NOT GLFW3_INCLUDE_DIR) OR (NOT GLFW3_LIBRARY_DEBUG) OR (NOT GLFW3_LIBRARY_RELEASE))
    message(STATUS "Could not find GLFW3 at project level, using find_package")
    find_package(GLFW3 REQUIRED)
    set(GLFW3_LIBRARY_DEBUG ${GLFW3_LIBRARY})
    set(GLFW3_LIBRARY_RELEASE ${GLFW3_LIBRARY})
endif()

function(add_library_glfw target)
    target_include_directories(${target} PRIVATE ${GLFW3_INCLUDE_DIR})
    target_link_libraries(${target} PRIVATE debug ${GLFW3_LIBRARY_DEBUG} optimized ${GLFW3_LIBRARY_RELEASE})
endfunction()