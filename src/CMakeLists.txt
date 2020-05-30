# Copyright 2020 Hal@shurabaP.  All rights reserved.
# Use of this source code is governed by a MIT style
# license that can be found in the LICENSE file.
cmake_minimum_required(VERSION 3.16)
project(uzume_vocal VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(uzume_vocal STATIC)

include(ExternalProject)

# depends on uzume_dsp module
ExternalProject_add(uzume_dsp
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/uzume_dsp
        GIT_REPOSITORY https://github.com/haruneko/uzume_dsp
        GIT_TAG master
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
        CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}"
        )
add_dependencies(uzume_vocal uzume_dsp)
link_directories(uzume_vocal PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/lib)
target_include_directories(uzume_vocal PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include)
target_link_libraries(uzume_vocal PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/lib/libuzume_dsp.a)

target_include_directories(uzume_vocal PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(uzume_vocal
        PRIVATE
        domain/Expression.cpp
        domain/Piece.cpp
        domain/SpectrogramReference.cpp
        domain/SpectrumReference.cpp
        domain/Track.cpp
        gateways/SpectrogramNaiveRepository.cpp
        usecases/TrackSpectrogram.cpp)
set_property(TARGET uzume_vocal
        PROPERTY PUBLIC_HEADER
        domain/Expression.hpp
        domain/Piece.hpp
        domain/SpectrogramReference.hpp
        domain/SpectrumReference.hpp
        domain/Track.hpp
        gateways/SpectrogramRepository.hpp
        gateways/SpectrogramNaiveRepository.hpp
        usecases/TrackSpectrogram.hpp)
target_include_directories(uzume_vocal
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>)
install(TARGETS uzume_vocal
        EXPORT libuzume_dsp
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)
