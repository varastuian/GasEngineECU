# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ParadECU_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ParadECU_autogen.dir\\ParseCache.txt"
  "ParadECU_autogen"
  "src\\API\\API_autogen"
  "src\\API\\CMakeFiles\\API_autogen.dir\\AutogenUsed.txt"
  "src\\API\\CMakeFiles\\API_autogen.dir\\ParseCache.txt"
  "src\\CMakeFiles\\QGC_autogen.dir\\AutogenUsed.txt"
  "src\\CMakeFiles\\QGC_autogen.dir\\ParseCache.txt"
  "src\\Comms\\CMakeFiles\\Comms_autogen.dir\\AutogenUsed.txt"
  "src\\Comms\\CMakeFiles\\Comms_autogen.dir\\ParseCache.txt"
  "src\\Comms\\Comms_autogen"
  "src\\QGC_autogen"
  "src\\QmlControls\\CMakeFiles\\QmlControls_autogen.dir\\AutogenUsed.txt"
  "src\\QmlControls\\CMakeFiles\\QmlControls_autogen.dir\\ParseCache.txt"
  "src\\QmlControls\\QmlControls_autogen"
  "src\\Utilities\\CMakeFiles\\Utilities_autogen.dir\\AutogenUsed.txt"
  "src\\Utilities\\CMakeFiles\\Utilities_autogen.dir\\ParseCache.txt"
  "src\\Utilities\\Utilities_autogen"
  "src\\Vahid\\CMakeFiles\\Vahid_autogen.dir\\AutogenUsed.txt"
  "src\\Vahid\\CMakeFiles\\Vahid_autogen.dir\\ParseCache.txt"
  "src\\Vahid\\Vahid_autogen"
  )
endif()
