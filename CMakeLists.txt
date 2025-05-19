cmake_minimum_required(VERSION 3.16)
project(ParticleSimulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output path for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# --- Directory setup ---
set(SRC_DIR         ${CMAKE_SOURCE_DIR}/src)
set(LIB_DIR         ${CMAKE_SOURCE_DIR}/lib)
set(IMGUI_DIR       ${LIB_DIR}/imgui)
set(IMGUI_SFML_DIR  ${LIB_DIR}/imgui-sfml)
set(SFML_DIR        ${LIB_DIR}/SFML)

# --- Find OpenGL ---
find_package(OpenGL REQUIRED)

# --- Add SFML (from source or pre-downloaded) ---
add_subdirectory(${SFML_DIR})

# --- ImGui sources ---
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_demo.cpp  # optional
)

# --- ImGui-SFML sources ---
set(IMGUI_SFML_SOURCES
    ${IMGUI_SFML_DIR}/imgui-SFML.cpp
)

# --- Create ImGui static library ---
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC ${IMGUI_DIR} ${SFML_DIR}/include)

# --- Create ImGui-SFML static library ---
add_library(imgui-sfml STATIC ${IMGUI_SFML_SOURCES})
target_include_directories(imgui-sfml PUBLIC ${IMGUI_SFML_DIR} ${IMGUI_DIR} ${SFML_DIR}/include)

# --- Link ImGui-SFML to dependencies ---
target_link_libraries(imgui-sfml PUBLIC
    imgui
    sfml-system
    sfml-window
    sfml-graphics
    OpenGL::GL
)

# --- Force usage of your custom imconfig.h ---
target_compile_definitions(imgui PRIVATE -DIMGUI_USER_CONFIG="imconfig.h")

# --- Main executable ---
set (SOURCES
    Theme/colors.cpp
    Theme/style.cpp

    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/App.cpp

    ${SRC_DIR}/Simulation/Particle.cpp
    ${SRC_DIR}/Simulation/Math/vec.cpp
    ${SRC_DIR}/Simulation/Solver.cpp
    ${SRC_DIR}/Panels/ParticleCreationPanel/ParticleCreationPanel.cpp
    ${SRC_DIR}/Panels/SimulationControlPanel/SimulationControlPanel.cpp
)

add_executable(ParticleSimulation ${SOURCES})

target_include_directories(ParticleSimulation PRIVATE ${SRC_DIR} ${SFML_DIR}/include)
target_link_libraries(ParticleSimulation PRIVATE imgui imgui-sfml sfml-system sfml-window sfml-graphics OpenGL::GL)