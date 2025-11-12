cmake_minimum_required(VERSION 3.10)
project(Projekat_47_2022)

set(CXX_CMAKE_COMPILE_STANDARD 14)
set(SOURCE_FILES
        ../code/main.cpp
        ../code/osoba.cpp
        ../code/medicinskaIstorija.cpp
        ../code/pacijent.cpp
        ../code/doktor.cpp
        ../code/sistemZdravstva.cpp
        ../code/lek.cpp
        ../code/datum.cpp
)

add_executable(exe ${SOURCE_FILES})