/* _defs/window.h -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_DEF_WINDOW_H
#define __OODUCK_DEF_WINDOW_H

/* definitions */

#include <oogame/_defs/sdlobject.h>

struct Window
{
    struct SDLObject _;

    SDL_Window *win;
};

#endif /* __OODUCK_DEF_WINDOW_H */
