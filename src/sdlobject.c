/* sdlobject.c -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OOGAME_SPRITE_PRIV_H
#include <oogame/sdlobject.h>
#include <oogame/_defs/sdlobject.h>
#include <oogame/_priv/sdlobject.h>

static const void *_SDLObject = NULL;

const void *SDLObject (void)
{
    if (_SDLObject == NULL)
    {
        _SDLObject = new (
            Class (), "SDLObject",
            Object (), sizeof (struct SDLObject),
            "__constructor__", SDLObject_constructor,
            "__desstructor__", SDLObject_desstructor,
            "get_surface", SDLObject_get_surface,
            "set_surface", SDLObject_set_surface,
            NULL
        );
    }

    return _SDLObject;
}

static void *SDLObject_constructor (void *_self, va_list *app)
{
    Class_constructor_m ctor = method (super (SDLObject ()), "__constructor__");
    struct SDLObject *self = ctor (_self, app);

    self->s = NULL;

    return self;
}

static void *SDLObject_desstructor (void *_self)
{
    struct SDLObject *self = cast (SDLObject (), _self);

    if (self->s != NULL)
    {
        SDL_FreeSurface (self->s);
    }

    return self;
}

static SDL_Surface *SDLObject_get_surface (const void *_self)
{
    const struct SDLObject *self = cast (SDLObject (), _self);
    return self->s;
}

static void SDLObject_set_surface (void *_self, SDL_Surface *s)
{
    struct SDLObject *self = cast (SDLObject (), _self);
    self->s = s;
}
