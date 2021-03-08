cmake_minimum_required(VERSION 3.1)

project(ClntN)

include_directories(${PROJECT_SOURCE_DIR})

set (ClntN_SRC  main.cpp autotest.cpp func.cpp ClntN.cpp ClntN0.cpp ClntN1.cpp)
set (ClntN_HDR ClntN.h ClntN0.h ClntN1.h wh.h)
set (ClntN_OTH Auto.txt Auto1.txt Auto0.txt Data.txt Data1.txt Data0.txt)

add_executable (${PROJECT_NAME} ${ClntN_SRC} ${ClntN_HDR})