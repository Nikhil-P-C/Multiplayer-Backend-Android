cmake_minimum_required(VERSION 3.16)
project(AndroidGameServer)
      
set(CMAKE_CXX_STANDARD 17)

file(GLOB ENET_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/enet-1.3.18/*.c
)
add_library(enet SHARED ${ENET_SRC})
target_include_directories(enet PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/enet-1.3.18/include
)


add_executable(server server.cpp)
target_include_directories(server
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
) 
target_link_libraries(server PRIVATE enet)