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

#include "frame.hpp"
#include "camera.hpp"
#include "event.hpp"
#include "render.hpp"
#include "sys/alloc.hpp"

namespace pf
{
  Frame::Frame(Frame *previous) {
    if (previous == NULL) {
      this->cam = PF_NEW(FlyCamera);
      this->event = PF_NEW(InputEvent);
    } else {
      this->cam = PF_NEW(FlyCamera, *previous->cam.ptr);
      this->event = PF_NEW(InputEvent, previous->event.ptr);
    }
  }

  TaskFrame::TaskFrame(Frame *previous) { this->previous = previous; }

  Task *TaskFrame::run(void)
  {
    // User pressed ESCAPE
    if (UNLIKELY(previous && previous->event->getKey(27))) {
      TaskingSystemInterruptMain();
      return NULL;
    }

    // Generate the current frame tasks
    InputEvent *previousEvent = previous ? previous->event.ptr : NULL;
    Frame *current = PF_NEW(Frame, previous.ptr);
    Task *eventTask = PF_NEW(TaskEvent, current->event.ptr, previousEvent);
    Task *cameraTask = PF_NEW(TaskCamera, current->cam.ptr, current->event.ptr);
    Task *renderTask = PF_NEW(TaskRender, current->cam.ptr, current->event.ptr);
    eventTask->starts(cameraTask);
    cameraTask->starts(renderTask);
    renderTask->ends(this);
    cameraTask->scheduled();
    eventTask->scheduled();
    renderTask->scheduled();

    // Spawn the next frame. Right now there is no overlapping
    TaskFrame *next = PF_NEW(TaskFrame, current);
    this->starts(next);
    next->scheduled();

    return NULL;
  }
} /* namespace pf */

