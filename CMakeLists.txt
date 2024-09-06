cmake_minimum_required(VERSION 3.28)

project("Rgp")

file(GLOB_RECURSE SRC_LIST 
    app/**.h
    app/**.hpp
    app/**.inl
    app/**.cpp
)


set(SFML_STATIC_LIBRARIES false)
find_package(SFML 2 COMPONENTS system window graphics REQUIRED)

add_executable(Rgp ${SRC_LIST})
target_link_libraries(Rgp sfml-window sfml-graphics sfml-system sfml-audio sfml-network)
