/* mainloop.c -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OOGAME_MAINLOOP_PRIV_H
#include <oogame/mainloop.h>
#include <oogame/_defs/mainloop.h>
#include <oogame/_priv/mainloop.h>

static const void *_MainLoop = NULL;

const void *MainLoop (void)
{
    if (_MainLoop == NULL)
    {
        _MainLoop = new (
            Class (), "MainLoop",
            Object (), sizeof (struct MainLoop),
            "__constructor__", MainLoop_constructor,
            "__destructor__", MainLoop_destructor,
            "register", MainLoop_register,
            "run", MainLoop_run,
            "stop", MainLoop_stop,
            NULL
        );
    }

    return _MainLoop;
}

static void *MainLoop_constructor (void *_self, va_list *app)
{
    void *win = cast (Window (), va_arg (*app, void *));

    Class_constructor_m ctor = method (super (MainLoop ()), "__constructor__");
    struct MainLoop *self = ctor (_self, app);

    int i = 0;

    for (; i < SDL_NUMEVENTS; ++i)
    {
        SLIST_INIT (&(self->events[i]));
    }

    self->window = win;
    self->running = false;

    return self;
}

static void *MainLoop_destructor (void *_self)
{
    struct MainLoop *self = cast (MainLoop (), _self);

    int i = 0;

    for (; i < SDL_NUMEVENTS; ++i)
    {
        while (!SLIST_EMPTY (&(self->events[i])))
        {
            void *handler = SLIST_FIRST (&(self->events[i]));
            SLIST_REMOVE_HEAD (&(self->events[i]));
            unref (handler);
        }
    }

    return self;
}

static void MainLoop_register (void *_self, int evtype, void *_handler);
{
    struct MainLoop *self = cast (MainLoop (), _self);
    void *handler = ref (cast (EventHandler (), _handler));

    SLIST_INSERT_HEAD (&(self->events[evtype]), handler, next);
}

static void _MainLoop_do_run (void *_self, SDL_Event ev)
{
    struct MainLoop *self = cast (MainLoop (), _self);
    void *handler = NULL;

    SLIST_FOREACH (handler, &(self->events[ev.type]), next)
    {
        EventHandler_call_m call = method (classOf (handler), "call");

        if (call (handler, ev))
        {
            break;
        }
    }
}

static void MainLoop_run (void *_self, bool wait)
{
    struct MainLoop *self = cast (MainLoop (), _self);

    self->running = true;

    while (self->running)
    {
        SDL_Event ev;

        if (wait)
        {
            SDL_WaitEvent (&ev);
            _MainLoop_do_run (self, ev);
        }
        else
        {
            while (SDL_PollEvent (&ev) != 0)
            {
                _MainLoop_do_run (self, ev);
            }
        }
    }
}

static void MainLoop_stop (void *_self)
{
    struct MainLoop *self = cast (MainLoop (), _self);

    self->running = false;    
}
