cmake_minimum_required(VERSION 3.19)
project(CSC340GroupProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(Alan)
include_directories(Jed)
include_directories(Tommy)

add_executable(CSC340GroupProject
        Alan/CompanyProcessor.cpp
        Alan/CompanyProcessor.h
        Jed/ActorDirectorProcessor.cpp
        Jed/ActorDirectorProcessor.h
        Kobe/ActorsProfit.h
        Kobe/ActorsProfitProcessor.cpp
        Tommy/Movie.cpp
        Tommy/Movie.h
        Tommy/MovieReader.cpp
        Tommy/MovieReader.h
        Tommy/tmdb_5000_credits.csv
        Tommy/tmdb_5000_movies.csv
        main.cpp)
