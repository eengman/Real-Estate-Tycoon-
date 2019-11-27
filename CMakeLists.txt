cmake_minimum_required(VERSION 3.15)
project(RealEstateGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(RealEstateGame main.cpp Player.cpp Player.h Property.cpp Property.h House.cpp House.h Apartment.cpp Apartment.h Business.cpp Business.h Tenant.cpp Tenant.h)