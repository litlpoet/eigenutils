# libeigenutils
project(libeigenutils VERSION 0.0.1 LANGUAGES CXX)

# add_library(eigenutils)

# target_include_directories(
#   eigenutils
#   PUBLIC
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include>
#   PRIVATE
#   src
#   )

# target_link_libraries(
#   eigenutils
#   Eigen3::Eigen
#   GTest::GTest
#   GTest::Main
#   )

# install(
#   TARGETS eigenutils EXPORT EigenUtilsConfig
#   ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
#   LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
#   RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}  # This is for Windows
#   )

# install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# install(EXPORT EigenUtilsConfig DESTINATION share/EigenUtilsConfig/cmake)

# export(TARGETS eigenutils EigenUtilsConfig.cmake)

add_executable(
  testeigenutils
  test/test_dims.cpp
  )

target_include_directories(
  testeigenutils
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  PRIVATE
  src
  )

target_link_libraries(
  testeigenutils
  Eigen3::Eigen
  GTest::GTest
  GTest::Main
  )

add_test(
  testeigenutils
  testeigenutils
  )

