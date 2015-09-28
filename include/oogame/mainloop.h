/* mainloop.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_MAINLOOP_H
#define __OODUCK_MAINLOOP_H

#include <oogame/window.h>
#include <oogame/eventhandler.h>

const void *MainLoop (void);

typedef void (*MainLoop_register_m) (void *, int, void *);
typedef void (*MainLoop_run_m) (void *);
typedef void (*MainLoop_stop_m) (void *);

#endif /* __OODUCK_MAINLOOP_H */