/* _priv/eventhandler.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_EVENTHANDLER_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *EventHandler_constructor (void *_self, va_list *app);
static void *EventHandler_destructor (void *_self);

static bool EventHandler_call (void *_self, SDL_Event ev);
