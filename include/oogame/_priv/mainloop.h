/* _priv/mainloop.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_MAINLOOP_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *MainLoop_constructor (void *_self, va_list *app);
static void *MainLoop_destructor (void *_self);

static void MainLoop_register (void *_self, int evtype, void *_handler);
static void MainLoop_run (void *_self);
static void MainLoop_stop (void *_self);
