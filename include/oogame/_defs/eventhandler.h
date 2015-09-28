/* _defs/eventhandler.h -- This file is part of oogame
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_DEF_EVENTHANDLER_H
#define __OODUCK_DEF_EVENTHANDLER_H

/* definitions */

#include <ooduck/_defs/object.h>

struct EventHandler
{
    struct Object _;

    EventHandler_cb handler;
    void *userdata;
};

#endif /* __OODUCK_DEF_EVENTHANDLER_H */
