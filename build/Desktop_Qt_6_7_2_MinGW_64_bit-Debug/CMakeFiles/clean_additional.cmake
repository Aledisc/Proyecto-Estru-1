# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProyectoEstru1qtv_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProyectoEstru1qtv_autogen.dir\\ParseCache.txt"
  "ProyectoEstru1qtv_autogen"
  )
endif()
