/* sdlobject.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_SDLOBJECT_H
#define __OODUCK_SDLOBJECT_H

#include <oogame/oogame.h>

const void *SDLObject (void);

typedef SDL_Surface * (*SDLObject_get_surface_m) (const void *);
typedef void (*SDLObject_set_surface_m) (void *, SDL_Surface *);

#endif /* __OODUCK_SDLOBJECT_H */