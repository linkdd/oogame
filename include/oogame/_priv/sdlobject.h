/* _priv/sdlobject.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_SDLOBJECT_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *SDLObject_constructor (void *_self, va_list *app);
static void *SDLObject_destructor (void *_self);

static SDL_Surface *SDLObject_get_surface (const void *_self);
static void SDLObject_set_surface (void *_self, SDL_Surface *s);
