/*
 * Copyright (c) 2011-*, (mt) MediaTemple <mediatemple.net>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CON-
 * SEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _INOTISPY_CONFIG_H_
#define _INOTISPY_CONFIG_H_

#include "zeromq.h"
#include "log.h"
#include "inotify.h"

#include <glib.h>

#define CONF_GROUP "global"
#define APPLICATION_NAME "inotispy"
#define INOTISPY_CONFIG_DIR @sysconfdir@
#define INOTISPY_CONFIG_FILE "inotispy.conf"

struct inotispy_config {

    /* zmq.h */
    char *zmq_uri;

    /* log.h */
    int log_level;
    char *log_file;
    gboolean log_syslog;

    /* inotify.h */
    int max_inotify_events;

    /* Toggle printing information to stderr */
    gboolean silent;
};

struct inotispy_config *CONFIG;

/* Read in config values from /etc/inotispy.conf.
 *
 * Takes:
 *  - boolean value toggeling silent mode.
 *
 * Returns:
 *  - 0 (zero) on success.
 *  - 1 on failure.
 */
int init_config(gboolean silent);

#endif /*_INOTISPY_CONFIG_H_*/
