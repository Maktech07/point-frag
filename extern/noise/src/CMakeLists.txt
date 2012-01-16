set (NOISE_SRC
  latlon.cpp
  noisegen.cpp
  model/cylinder.cpp
  model/line.cpp
  model/plane.cpp
  model/sphere.cpp
  module/abs.cpp
  module/add.cpp
  module/billow.cpp
  module/blend.cpp
  module/cache.cpp
  module/checkerboard.cpp
  module/clamp.cpp
  module/const.cpp
  module/curve.cpp
  module/cylinders.cpp
  module/displace.cpp
  module/exponent.cpp
  module/invert.cpp
  module/max.cpp
  module/min.cpp
  module/modulebase.cpp
  module/multiply.cpp
  module/perlin.cpp
  module/power.cpp
  module/ridgedmulti.cpp
  module/rotatepoint.cpp
  module/scalebias.cpp
  module/scalepoint.cpp
  module/select.cpp
  module/spheres.cpp
  module/terrace.cpp
  module/translatepoint.cpp
  module/turbulence.cpp
  module/voronoi.cpp
  basictypes.h
  exception.h
  interp.h
  latlon.h
  mathconsts.h
  misc.h
  noisegen.h
  noise.h
  vectortable.h
  model/cylinder.h
  model/model.h
  model/sphere.h
  model/line.h
  model/plane.h
  module/abs.h
  module/add.h
  module/billow.h
  module/blend.h
  module/cache.h
  module/checkerboard.h
  module/clamp.h
  module/const.h
  module/curve.h
  module/cylinders.h
  module/displace.h
  module/exponent.h
  module/invert.h
  module/max.h
  module/min.h
  module/module.h
  module/modulebase.h
  module/multiply.h
  module/perlin.h
  module/power.h
  module/ridgedmulti.h
  module/rotatepoint.h
  module/scalebias.h
  module/scalepoint.h
  module/select.h
  module/spheres.h
  module/terrace.h
  module/translatepoint.h
  module/turbulence.h
  module/voronoi.h)

add_library (noise SHARED ${NOISE_SRC})
install_targets (/bin/ noise)
file (GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install (FILES ${HEADERS} DESTINATION include/noise/)
file (GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/model/*.h")
install (FILES ${HEADERS} DESTINATION include/noise/model)
file (GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/module/*.h")
install (FILES ${HEADERS} DESTINATION include/noise/module)

