set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wpedantic")
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR})

find_package(PkgConfig REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
add_definitions(-DGST_API_VERSION_1=1)

include_directories(
    ${GSTREAMER_INCLUDE_DIRS}
)

link_directories(
    ${GSTREAMER_LIBRARY_DIRS}
)

set(LIBRARIES
    ${GSTREAMER_LIBRARIES}
)
set(SOURCES
    ${PROJECT_SOURCES_DIR}/main.cpp

    ${PROJECT_SOURCES_DIR}/gstreamer/GStreamerLauncher.cpp
    ${PROJECT_SOURCES_DIR}/gstreamer/GStreamerSource.cpp
    ${PROJECT_SOURCES_DIR}/gstreamer/GStreamerSink.cpp
    ${PROJECT_SOURCES_DIR}/gstreamer/GStreamerFilter.cpp
    ${PROJECT_SOURCES_DIR}/gstreamer/GStreamerBus.cpp
    ${PROJECT_SOURCES_DIR}/gstreamer/GStreamerPipeline.cpp
    ${PROJECT_SOURCES_DIR}/gstreamer/GStreamerMessage.cpp
    ${PROJECT_SOURCES_DIR}/gstreamer/GStreamerDeleter.cpp

    ${PROJECT_SOURCES_DIR}/gstreamer/handlers/MsgHandleError.cpp
    ${PROJECT_SOURCES_DIR}/gstreamer/handlers/MsgHandleEos.cpp
    ${PROJECT_SOURCES_DIR}/gstreamer/handlers/MsgHandleFactory.cpp

    ${PROJECT_SOURCES_DIR}/exceptions/LogMsgCreator.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${LIBRARIES})