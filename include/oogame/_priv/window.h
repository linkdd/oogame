/* _priv/window.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_WINDOW_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *Window_constructor (void *_self, va_list *app);
static void *Window_destructor (void *_self);

static void Window_blit (const void *_self, const void *_obj);
static void Window_update (const void *_self);
