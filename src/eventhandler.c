/* eventhandler.c -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OOGAME_EVENTHANDLER_PRIV_H
#include <oogame/eventhandler.h>
#include <oogame/_defs/eventhandler.h>
#include <oogame/_priv/eventhandler.h>

static const void *_EventHandler = NULL;

const void *EventHandler (void)
{
    if (_EventHandler == NULL)
    {
        _EventHandler = new (
            Class (), "EventHandler",
            Object (), sizeof (struct EventHandler),
            "__constructor__", EventHandler_constructor,
            "__destructor__", EventHandler_destructor,
            "call", EventHandler_call,
            NULL
        );
    }

    return _EventHandler;
}

static void *EventHandler_constructor (void *_self, va_list *app)
{
    EventHandler_cb handler = va_arg (*app, EventHandler_cb);
    void *userdata = va_arg (*app, void *);

    Class_constructor_m ctor = method (super (EventHandler ()), "__constructor__");
    struct EventHandler *self = ctor (_self, app);

    self->handler = handler;
    self->userdata = userdata;

    return self;
}

static void *EventHandler_destructor (void *_self)
{
    struct EventHandler *self = cast (EventHandler (), _self);

    return self;
}

static bool EventHandler_call (void *_self, SDL_Event ev)
{
    struct EventHandler *self = cast (EventHandler (), _self);
    return self->handler (self, ev, self->userdata);
}
