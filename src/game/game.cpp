// ======================================================================== //
// Copyright (C) 2011 Benjamin Segovia                                      //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#include "game.hpp"
#include "camera.hpp"
#include "game_event.hpp"
#include "game_frame.hpp"
#include "renderer/renderer_context.hpp"
#include "rt/intersector.hpp"
#include "rt/rt_triangle.hpp"
#include "rt/bvh2.hpp"
#include "rt/bvh2_traverser.hpp"

#include "sys/alloc.hpp"
#include "sys/tasking.hpp"
#include "sys/windowing.hpp"
#include "sys/logging.hpp"
#include "sys/default_path.hpp"

#include "models/obj.hpp"
#include "noise/noise.h"

#include <cstdio>
#include <iostream>

namespace pf
{
  static const int defaultWidth = 800, defaultHeight = 600;
  static const char *objName = "arabic_city_II.obj";
  //static const char *objName = "f000.obj";
  //static const char *objName = "small.obj";
  //static const char *objName = "Arabic_City.obj";
  //static const char *objName = "conference.obj";
  //static const char *objName = "sibenik.obj";
  //static const char *objName = "sponza.obj";
  RnContext renderer = NULL;
  RnObj renderObj = NULL;

  static const uint32 noiseSize = 64;
  static Obj *buildNoiseObj(void)
  {
    using namespace noise;
    PF_MSG("Obj: Building random 3d structure");
    Obj *obj = NULL;
    module::Perlin perlin;
    perlin.SetSeed (0);
    perlin.SetFrequency (1.0);
    perlin.SetPersistence (0.4);
    perlin.SetLacunarity (1.6);
    perlin.SetOctaveCount (5);
    perlin.SetNoiseQuality (QUALITY_STD);

    // Put the geometry here
    vector<Obj::Vertex> vert;
    vector<Obj::Triangle> tri;

    // Create one cube per full cell
    uint32 cubeNum = 0;
    const double rcp = 1. / double(noiseSize);
    for (uint32 z = 0; z < noiseSize*4; ++z)
    for (uint32 y = 0; y < noiseSize; ++y)
    for (uint32 x = 0; x < noiseSize*4; ++x) {
      const double value = perlin.GetValue(x*rcp,y*rcp,z*rcp);
      if (value < 0.f) continue;
      const double value0 = perlin.GetValue(x*rcp+rcp,y*rcp,z*rcp);
      const double value1 = perlin.GetValue(x*rcp-rcp,y*rcp,z*rcp);
      const double value2 = perlin.GetValue(x*rcp,y*rcp+rcp,z*rcp);
      const double value3 = perlin.GetValue(x*rcp,y*rcp-rcp,z*rcp);
      const double value4 = perlin.GetValue(x*rcp,y*rcp,z*rcp+rcp);
      const double value5 = perlin.GetValue(x*rcp,y*rcp,z*rcp-rcp);
      if (value0 > 0. && value1 > 0. && value2 > 0. && value3 > 0.f && value4 > 0. && value5 > 0.f)
        continue;

      // Generate the six faces (12 triangles)
#define MAKE_FACE(X0,Y0,Z0, X1,Y1,Z1, X2,Y2,Z2, X3,Y3,Z3)\
      do {\
        const vec3f v0(float(x)+X0, float(y)+Y0, float(z)+Z0);\
        const vec3f v1(float(x)+X1, float(y)+Y1, float(z)+Z1);\
        const vec3f v2(float(x)+X2, float(y)+Y2, float(z)+Z2);\
        const vec3f v3(float(x)+X3, float(y)+Y3, float(z)+Z3);\
        const vec3f normal = cross(v0 - v1, v0 - v2);\
        const vec2f t0(0.f, 0.f);\
        const vec2f t1(0.f, 1.f);\
        const vec2f t2(1.f, 1.f);\
        const vec2f t3(1.f, 0.f);\
        const Obj::Vertex vert0(v0, normal, t0);\
        const Obj::Vertex vert1(v1, normal, t1);\
        const Obj::Vertex vert2(v2, normal, t2);\
        const Obj::Vertex vert3(v3, normal, t3);\
        const int n = int(vert.size());\
        const Obj::Triangle tri0(vec3i(n+0,n+1,n+2), 0);\
        const Obj::Triangle tri1(vec3i(n+3,n+0,n+2), 0);\
        tri.push_back(tri0);\
        tri.push_back(tri1);\
        vert.push_back(vert0);\
        vert.push_back(vert1);\
        vert.push_back(vert2);\
        vert.push_back(vert3);\
      } while (0)

      if (value0 < 0.f) MAKE_FACE(1.f,0.f,1.f, 1.f,0.f,0.f, 1.f,1.f,0.f, 1.f,1.f,1.f);
      if (value1 < 0.f) MAKE_FACE(0.f,0.f,0.f, 0.f,0.f,1.f, 0.f,1.f,1.f, 0.f,1.f,0.f);
      if (value2 < 0.f) MAKE_FACE(0.f,1.f,0.f, 0.f,1.f,1.f, 1.f,1.f,1.f, 1.f,1.f,0.f);
      if (value3 < 0.f) MAKE_FACE(0.f,0.f,1.f, 0.f,0.f,0.f, 1.f,0.f,0.f, 1.f,0.f,1.f);
      if (value4 < 0.f) MAKE_FACE(0.f,1.f,1.f, 0.f,0.f,1.f, 1.f,0.f,1.f, 1.f,1.f,1.f);
      if (value5 < 0.f) MAKE_FACE(0.f,0.f,0.f, 0.f,1.f,0.f, 1.f,1.f,0.f, 1.f,0.f,0.f);
#undef MAKE_FACE
    }
    PF_MSG("Obj: " << cubeNum << " cube elements");
    obj = PF_NEW(Obj);
    obj->tri = PF_NEW_ARRAY(Obj::Triangle, tri.size());
    obj->vert = PF_NEW_ARRAY(Obj::Vertex, vert.size());
    obj->grp = PF_NEW_ARRAY(Obj::MatGroup, 1);
    obj->mat = PF_NEW_ARRAY(Obj::Material, 1);
    for (uint32 i = 0; i < tri.size(); ++i) obj->tri[i] = tri[i];
    for (uint32 i = 0; i < vert.size(); ++i) obj->vert[i] = vert[i];
    obj->grp[0] = Obj::MatGroup(0, tri.size()-1, 0);
    obj->mat[0] = Obj::Material();
    obj->triNum = tri.size();
    obj->vertNum = vert.size();
    obj->grpNum = 1;
    obj->matNum = 1;
    return obj;
  }

  static Obj *loadModel(const char *fileName)
  {
    PF_ASSERT(fileName);
    const FileName objName(fileName);
    size_t path = 0;
    Obj *obj = PF_NEW(Obj);
    for (path = 0; path < defaultPathNum; ++path) {
      if (obj->load(FileName(defaultPath[path]) + objName)) {
        PF_MSG_V("Obj: " << objName << " loaded from " << defaultPath[path]);
        break;
      }
    }
    if (path == defaultPathNum) {
      PF_WARNING_V("Obj: " << objName << " not found");
      return NULL;
    }
    return obj;
  }

  static Intersector *buildIntersector(const Obj &obj)
  {
    PF_MSG_V("Game: building BVH");
    RTTriangle *tris = PF_NEW_ARRAY(RTTriangle, obj.triNum);
    for (size_t triID = 0; triID < obj.triNum; ++triID) {
      const uint32 index0 = obj.tri[triID].v[0];
      const uint32 index1 = obj.tri[triID].v[1];
      const uint32 index2 = obj.tri[triID].v[2];
      const vec3f &v0 = obj.vert[index0].p;
      const vec3f &v1 = obj.vert[index1].p;
      const vec3f &v2 = obj.vert[index2].p;
      tris[triID] = RTTriangle(v0,v1,v2);
    }
    BVH2<RTTriangle>* bvh = PF_NEW(BVH2<RTTriangle>);
    buildBVH2(tris, obj.triNum, *bvh);
    PF_DELETE_ARRAY(tris);
    return PF_NEW(BVH2Traverser<RTTriangle>, bvh);
  }

  static void GameStart(int argc, char **argv) {
    WinOpen(defaultWidth, defaultHeight);
    renderer = rnContextNew();
#if 1
    Obj *obj = loadModel(objName);
#else
    Obj *obj = buildNoiseObj();
#endif
    renderObj = rnObjNew(renderer, *obj);
    Intersector *intersector = buildIntersector(*obj);
    rnObjSetIntersector(renderObj, intersector);
    rnObjCompile(renderObj);
    PF_DELETE(obj);
  }

  static void GameEnd(void) {
    rnObjDelete(renderObj);
    rnContextDelete(renderer);
    WinClose();
  }

} /* namespace pf */

void game(int argc, char **argv)
{
  using namespace pf;
  GameStart(argc, argv);

  // We create a dummy frame such that a previous frame always exists in the
  // system. This makes everything a lot easier to handle. We do not destroy it
  // since it is referenced counted
  GameFrame *dummyFrame = PF_NEW(GameFrame, defaultWidth, defaultHeight);
  Task *frameTask = PF_NEW(TaskGameFrame, *dummyFrame);
  frameTask->scheduled();
  TaskingSystemEnter();

  // We must be sure that all pending tasks are done
  TaskingSystemWaitAll();

  // Beyond this point, the worker threads are not doing anything
  GameEnd();
}

