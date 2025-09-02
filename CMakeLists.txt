add_library(CMBTL_DAQInfrastructure INTERFACE)

target_link_libraries(CMBTL_DAQInfrastructure CommboardTransmissionLibrary)
target_include_directories(CMBTL_DAQInfrastructure INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(Testing)