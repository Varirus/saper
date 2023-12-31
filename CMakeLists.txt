cmake_minimum_required (VERSION 3.1)

project (saper)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

# Windows specific config
IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/lib/SFML-2.5.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Create a list with all .cpp source files
set(project_sources
    main.cpp
    MinesweeperBoard.cpp
    MSBoardTextView.cpp
    MSTextController.cpp
    MSBoardView.cpp
    MSController.cpp
)

# Create executable with all necessary source files
add_executable(${PROJECT_NAME}
    ${project_sources})

# Link SFML libraries
target_link_libraries(saper sfml-graphics)