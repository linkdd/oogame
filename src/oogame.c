/* oogame.c -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <ooduck/object.h>
#include <oogame/oogame.h>

E4C_DEFINE_EXCEPTION (SDLException, "Internal SDL error", RuntimeException);

static void oogame_deinit (void)
{
    SDL_Quit ();
}

void oogame_init (void)
{
    ooduck_init ();

    if (SDL_Init (SDL_INIT_VIDEO) < 0)
    {
        throwf (SDLException, "Cannot initialize SDL: %s", SDL_GetError ());
    }

    atexit (oogame_deinit);
}
