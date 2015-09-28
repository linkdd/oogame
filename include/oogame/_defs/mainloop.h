/* _defs/mainloop.h -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_DEF_MAINLOOP_H
#define __OODUCK_DEF_MAINLOOP_H

/* definitions */

#include <ooduck/_defs/object.h>

#include <sys/queue.h>

typedef struct EventList
{
    void *handler;
    SLIST_ENTRY (EventList) next;
} EventList;

struct MainLoop
{
    struct Object _;

    SLIST_HEAD (, EventList) events[SDL_NUMEVENTS];
};

#endif /* __OODUCK_DEF_MAINLOOP_H */
