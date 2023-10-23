cmake_minimum_required(VERSION 3.5)

project(Astro LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Astro main.cpp main.hpp Ball.cpp Ball.hpp Button.cpp Button.hpp num_enter.cpp num_enter.hpp)
target_link_libraries(Astro PRIVATE sfml-graphics)
target_compile_features(Astro PRIVATE cxx_std_17)

install(TARGETS Astro)