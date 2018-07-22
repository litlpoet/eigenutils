set(UNITTESTS_NAME ${PROJECT_NAME}_unittests)

file(GLOB SRC_UNITTESTS ${CMAKE_CURRENT_SOURCE_DIR}/unittests/*.cpp)

add_executable(
  ${UNITTESTS_NAME}
  ${SRC_UNITTESTS}
  )

target_include_directories(
  ${UNITTESTS_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/thirdparties>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/thirdparties/eigen3>
  PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  )

target_link_libraries(
  ${UNITTESTS_NAME}
  ${PROJECT_NAME}
  )

add_test(
  NAME
  ${UNITTESTS_NAME}
  COMMAND
  ${UNITTESTS_NAME}
  )
