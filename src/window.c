/* window.c -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OOGAME_WINDOW_PRIV_H
#include <oogame/window.h>
#include <oogame/_defs/window.h>
#include <oogame/_priv/window.h>

static const void *_Window = NULL;

const void *Window (void)
{
    if (_Window == NULL)
    {
        _Window = new (
            Class (), "Window",
            SDLObject (), sizeof (struct Window),
            "__constructor__", Window_constructor,
            "__destructor__", Window_destructor,
            "blit", Window_blit,
            "update", Window_update,
            NULL
        );
    }

    return _Window;
}

static void *Window_constructor (void *_self, va_list *app)
{
    char *title = va_arg (*app, char *);
    int width = va_arg (*app, int);
    int height = va_arg (*app, int);

    Class_constructor_m ctor = method (super (Window ()), "__constructor__");
    struct Window *self = ctor (_self, app);
    SDLObject_set_surface_m sets = method (classOf (self), "set_surface");

    self->window = SDL_CreateWindow (
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width, height,
        SDL_WINDOW_SHOWN
    );

    if (self->window == NULL)
    {
        throwf (SDLException, "Cannot create window: %s", SDL_GetError ());
    }

    sets (self, SDL_GetWindowSurface (window));

    return self;
}

static void *Window_destructor (void *_self)
{
    struct Window *self = cast (Window (), _self);

    if (self->window != NULL)
    {
        SDLObject_set_surface_m sets = method (classOf (self), "set_surface");

        SDL_DestroyWindow (self->window);

        sets (self, NULL);
    }

    return self;
}

static void Window_blit (const void *_self, const void *_obj)
{
    SDLObject_get_surface_m wgets = method (classOf (_self), "get_surface");
    SDLObject_get_surface_m ogets = method (classOf (_obj), "get_surface");
    SDL_Surface *ws = wgets (_self);
    SDL_Surface *os = obets (_obj);

    SDL_BlitSurface (os, NULL, ws, NULL);
}

static void Window_update (const void *_self)
{
    struct Window *self = cast (Window (), _self);

    SDL_UpdateWindowSurface (self->window);
}
