/* eventhandler.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_EVENTHANDLER_H
#define __OODUCK_EVENTHANDLER_H

#include <oogame/oogame.h>

const void *EventHandler (void);

typedef bool (*EventHandler_cb) (void *, SDL_Event, void *);

typedef bool (*EventHandler_call_m) (void *, SDL_Event);

#endif /* __OODUCK_EVENTHANDLER_H */