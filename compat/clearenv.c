/*
 * clearenv.c - clearenv() replacement
 * $Id: clearenv.c 1237 2006-04-14 06:39:20Z remi $
 */

/***********************************************************************
 *  Copyright © 2004-2006 Rémi Denis-Courmont.                         *
 *  This program is free software; you can redistribute and/or modify  *
 *  it under the terms of the GNU General Public License as published  *
 *  by the Free Software Foundation; version 2 of the license.         *
 *                                                                     *
 *  This program is distributed in the hope that it will be useful,    *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.               *
 *  See the GNU General Public License for more details.               *
 *                                                                     *
 *  You should have received a copy of the GNU General Public License  *
 *  along with this program; if not, you can get it from:              *
 *  http://www.gnu.org/copyleft/gpl.html                               *
 ***********************************************************************/

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include <stddef.h>

#ifdef __APPLE__
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#else
extern char **environ;
#endif

int clearenv (void)
{
	environ = NULL;
	return 0;
}