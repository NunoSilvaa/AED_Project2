cmake_minimum_required(VERSION 3.20)
project(RedeDeAutocarros)

set(CMAKE_CXX_STANDARD 14)

add_executable(RedeDeAutocarros main.cpp src/stop.cpp src/stop.h src/line.cpp src/line.h utilities/graph.cpp utilities/graph.h utilities/minHeap.cpp utilities/minHeap.h src/makeGraph.cpp src/makeGraph.h menus/mainMenu.cpp menus/mainMenu.h utilities/os.h menus/fewerStopsMenu.cpp menus/fewerStopsMenu.h menus/shortestDistanceMenu.cpp menus/shortestDistanceMenu.h)
