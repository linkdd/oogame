/* oogame.h -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OOGAME_H
#define __OOGAME_H

#include <ooduck/object.h>

#include <SDL.h>

E4C_DECLARE_EXCEPTION (SDLException);

void oogame_init (void);

#endif /* __OOGAME_H */