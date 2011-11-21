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

#ifndef __PF_INTERSECTABLE_HPP__
#define __PF_INTERSECTABLE_HPP__

#include "sys/ref.hpp"

namespace pf
{
  struct Ray;             // Single ray structure
  struct RayPacket;       // Packet of rays
  struct Hit;             // Store ray hit information
  struct PacketHit;       // Store ray packet hit information
  struct PacketOcclusion; // Store occlusion information of a packet

  /*! Represents any kind of intersectable geometry that we are going to
   *  traverse with rays or packet of rays
   */
  class Intersectable : public RefCount
  {
    /*! Traverse routine for rays */
    virtual void traverse(const Ray &ray, Hit &hit) const = 0;

    /*! Traverse routine for ray packets. Return u,v,t and ID of primitive of
     *  for each ray of the packet
     */
    virtual void traverse(const RayPacket &pckt, PacketHit &hit) const = 0;

    /*! Shadow ray routine for rays. True if occluded */
    virtual bool occluded(const Ray &ray) const = 0;

    /*! Shadow ray routine for packet of rays. Fill the given occlusion
     *  structure
     */
    virtual void occluded(const RayPacket &pckt, PacketOcclusion &o) const = 0;
  };
} /* namespace pf */

#endif /* __PF_INTERSECTABLE_HPP__ */

