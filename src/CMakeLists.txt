# eigenutils
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
  )

# install(
#   TARGETS eigenutils EXPORT EigenUtilsConfig
#   ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
#   LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
#   RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}  # This is for Windows
#   )

# install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# install(EXPORT EigenUtilsConfig DESTINATION share/EigenUtilsConfig/cmake)

# export(TARGETS eigenutils EigenUtilsConfig.cmake)
