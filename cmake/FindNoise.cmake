# NOISE_FOUND
# NOISE_INCLUDE_DIR
# NOISE_LIBRARY

if (WIN32)
  find_path (NOISE_INCLUDE_DIR noise/noise.h
             ${NOISE_ROOT_PATH}/include
             ${PROJECT_SOURCE_DIR}/extern/noise/include/
             doc "The directory where noise.h and other libnoise headers reside")
  find_library (NOISE_LIBRARY
                NAMES noise
                PATHS
                ${PROJECT_SOURCE_DIR}/extern/noise/lib
                DOC "The libnoise library")
else (WIN32)
    find_path (NOISE_INCLUDE_DIR noise/noise.h
               ${PROJECT_SOURCE_DIR}/extern/noise/include/
               ~/include/
               /usr/include/
               /usr/local/include)
    find_library (NOISE_LIBRARY noise
                  ~/lib/
                  /usr/lib
                  /usr/local/lib)
endif (WIN32)

if (NOISE_INCLUDE_DIR)
  set (NOISE_FOUND 1 CACHE STRING "Set to 1 if NOISE is found, 0 otherwise")
else (NOISE_INCLUDE_DIR)
  set (NOISE_FOUND 0 CACHE STRING "Set to 1 if NOISE is found, 0 otherwise")
endif (NOISE_INCLUDE_DIR)

mark_as_advanced (NOISE_FOUND)
