if(WIN32)
cmake_minimum_required (VERSION 3.1)
else()
cmake_minimum_required (VERSION 3.0)
endif()

project(ThirdParty)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#HANDLE ASSIMP THIRD PARTY LIBRARY
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/assimp")

set_target_properties(uninstall unit gtest UpdateAssimpLibsDebugSymbolsAndDLLs PROPERTIES EXCLUDE_FROM_ALL 1 EXCLUDE_FROM_DEFAULT_BUILD 1)
set_target_properties(assimp uninstall unit gtest UpdateAssimpLibsDebugSymbolsAndDLLs zlibstatic PROPERTIES FOLDER Assimp)
set_target_properties(assimp
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/assimp/"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/assimp/"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/assimp/bin"
                      OUTPUT_NAME "assimp")

#HANDLE SDL2 THIRD PARTY LIBRARY
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/SDL2")

set_target_properties(SDL2 SDL2main SDL2-static PROPERTIES FOLDER SDL)
set_target_properties(SDL2
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2/bin")
set_target_properties(SDL2main
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2/bin")
