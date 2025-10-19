cmake_minimum_required(VERSION 3.8)
project(rr_common_base)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rr_interfaces REQUIRED)
find_package(pluginlib REQUIRED)

# Create an INTERFACE library for header-only usage
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Specify header include paths for build and install
target_include_directories(${PROJECT_NAME} INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

# (Optional) Set standard requirements if headers use C++17 or newer
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

# Install header files
install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

# Export the INTERFACE target for other packages
install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
)

# Export include paths and target info to downstream packages
ament_export_include_directories(include)
ament_export_targets(export_${PROJECT_NAME})
ament_package()
