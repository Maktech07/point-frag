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

#ifndef __OBJ_HPP__
#define __OBJ_HPP__

#include "sys/platform.hpp"
#include "sys/filename.hpp"
#include "math/vec.hpp"

namespace pf
{

  /*! OBJ - an obj file (vertices are processed and merged) */
  struct Obj : public NonCopyable
  {
    /*! OBJ triangle - indexes vertices and material */
    struct Triangle {
      INLINE Triangle(void) {}
      INLINE Triangle(vec3i v, int m) : v(v), m(m) {}
      vec3i v;
      int m;
      PF_STRUCT(Triangle);
    };

    /*! OBJ vertex - stores position, normal and texture coordinates */
    struct Vertex {
      INLINE Vertex(void) {}
      INLINE Vertex(vec3f p, vec3f n, vec2f t) : p(p), n(n), t(t) {}
      vec3f p, n;
      vec2f t;
      PF_STRUCT(Vertex);
    };

    /*! OBJ material group - triangles are grouped by material */
    struct MatGroup {
      MatGroup(int first, int last, int m) : first(first), last(last), m(m) {}
      MatGroup(void) {}
      int first, last, m;
      PF_STRUCT(MatGroup);
    };

    /*! OBJ Material - just a dump of mtl description */
    struct Material
    {
      /*! Default material does not use any texture */
      Material(void) :
        name(NULL), map_Ka(NULL), map_Kd(NULL), map_D(NULL), map_Bump(NULL)
      {
        amb[0] = amb[1] = amb[2] = 0.;
        diff[0] = diff[1] = diff[2] = 0.6;
        spec[0] = spec[1] = spec[2] = 0.;
        km = reflect = refract = trans = shiny = glossy = refract_index = 0.;
      }
      /*! Free texture names if any */
      ~Material(void) {
        PF_SAFE_DELETE_ARRAY(name);
        PF_SAFE_DELETE_ARRAY(map_Ka);
        PF_SAFE_DELETE_ARRAY(map_Kd);
        PF_SAFE_DELETE_ARRAY(map_D);
        PF_SAFE_DELETE_ARRAY(map_Bump);
      }
      char *name;
      char *map_Ka;
      char *map_Kd;
      char *map_D;
      char *map_Bump;
      double amb[3];
      double diff[3];
      double spec[3];
      double km;
      double reflect;
      double refract;
      double trans;
      double shiny;
      double glossy;
      double refract_index;
      PF_STRUCT(Material);
    };

    /*! Create an empty OBJ */
    Obj(void);
    /*! Release everything */
    ~Obj(void);
    /*! To be valid, an OBJ must contain some geometry */
    INLINE bool isValid(void) const {return this->triNum > 0;}
    /*! Load a obj from a file. Return true if success */
    bool load(const FileName &fileName);
    Triangle *tri;
    Vertex *vert;
    MatGroup *grp;
    Material *mat;
    size_t triNum;
    size_t vertNum;
    size_t grpNum;
    size_t matNum;
    PF_STRUCT(Obj);
  };
} /* namespace pf */

#endif /* __OBJ_HPP__ */

