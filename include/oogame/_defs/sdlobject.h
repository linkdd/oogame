/* _defs/sdlobject.h -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_DEF_SDLOBJECT_H
#define __OODUCK_DEF_SDLOBJECT_H

/* definitions */

#include <ooduck/_defs/object.h>

struct SDLObject
{
    struct Object _;

    SDL_Surface *s;
};

#endif /* __OODUCK_DEF_SDLOBJECT_H */
