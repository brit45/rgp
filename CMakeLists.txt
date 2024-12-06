cmake_minimum_required(VERSION 3.28)

project("Rgp")

# Définitions des numéros de version
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION_SUFFIX "dev")  # Changez en "beta" ou "alpha" selon le cas

# Génération du fichier de version
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/app/src/version.h
    @ONLY
)


# Inclure le répertoire contenant le fichier généré
include_directories(${CMAKE_CURRENT_BINARY_DIR})


file(GLOB_RECURSE SRC_LIST 
    app/**.h
    app/**.hpp
    app/**.inl
    app/**.cpp
)


set(SFML_STATIC_LIBRARIES false)
find_package(SFML 2 COMPONENTS system window graphics REQUIRED)

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

add_executable(Rgp ${SRC_LIST})
target_link_libraries(Rgp sfml-window sfml-graphics sfml-system sfml-audio sfml-network GL GLEW glfw)
