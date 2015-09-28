/* window.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_WINDOW_H
#define __OODUCK_WINDOW_H

#include <oogame/sdlobject.h>

const void *Window (void);

typedef void (*Window_blit_m) (const void *, const void *);
typedef void (*Window_update_m) (const void *);

#endif /* __OODUCK_WINDOW_H */