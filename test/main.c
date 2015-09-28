/* main.c -- This file is an example of oogame usage
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <oogame/oogame.h>
#include <oogame/mainloop.h>

bool do_exit (void *evhandler, SDL_Event ev, void *mainloop)
{
    MainLoop_stop_m stop = method (classOf (mainloop), "stop");
    stop (mainloop);

    (void) evhandler;
    (void) ev;
}

int main (int argc, char **argv[])
{
    MainLoop_register_m evregister;
    MainLoop_run_m run;

    void *win = NULL;
    void *loop = NULL;
    void *exithandler = NULL;

    oogame_init ();

    win = new (Window (), "OOGame example", 640, 480);

    loop = new (MainLoop (), win);
    evregister = method (classOf (loop), "register");
    run = method (classOf (loop), "run");

    exithandler = new (EventHandler (), do_exit, loop);
    evregister (loop, SDL_QUIT, exithandler);
    unref (exithandler);

    run (loop);

    delete (loop);
    delete (win);

    return 0;
}
