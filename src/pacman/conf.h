/*
 *  conf.h
 *
 *  Copyright (c) 2006-2012 Pacman Development Team <pacman-dev@archlinux.org>
 *  Copyright (c) 2002-2006 by Judd Vinet <jvinet@zeroflux.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _PM_CONF_H
#define _PM_CONF_H

#include <alpm.h>

typedef struct __config_t {
	unsigned short op;
	unsigned short quiet;
	unsigned short verbose;
	unsigned short version;
	unsigned short help;
	unsigned short noconfirm;
	unsigned short noprogressbar;
	unsigned short logmask;
	unsigned short print;
	unsigned short checkspace;
	unsigned short usesyslog;
	double deltaratio;
	char *arch;
	char *print_format;
	/* unfortunately, we have to keep track of paths both here and in the library
	 * because they can come from both the command line or config file, and we
	 * need to ensure we get the order of preference right. */
	char *configfile;
	char *rootdir;
	char *dbpath;
	char *logfile;
	char *gpgdir;
	alpm_list_t *cachedirs;

	unsigned short op_q_isfile;
	unsigned short op_q_info;
	unsigned short op_q_list;
	unsigned short op_q_foreign;
	unsigned short op_q_unrequired;
	unsigned short op_q_deps;
	unsigned short op_q_explicit;
	unsigned short op_q_owns;
	unsigned short op_q_search;
	unsigned short op_q_changelog;
	unsigned short op_q_upgrade;
	unsigned short op_q_check;

	unsigned short op_s_clean;
	unsigned short op_s_downloadonly;
	unsigned short op_s_info;
	unsigned short op_s_sync;
	unsigned short op_s_search;
	unsigned short op_s_upgrade;

	unsigned short group;
	unsigned short noask;
	unsigned int ask;
	alpm_transflag_t flags;
	alpm_siglevel_t siglevel;

	/* conf file options */
	/* I Love Candy! */
	unsigned short chomp;
	/* format target pkg lists as table */
	unsigned short verbosepkglists;
	/* When downloading, display the amount downloaded, rate, ETA, and percent
	 * downloaded of the total download list */
	unsigned short totaldownload;
	/* select -Sc behavior */
	unsigned short cleanmethod;
	alpm_list_t *holdpkg;
	alpm_list_t *ignorepkg;
	alpm_list_t *ignoregrp;
	alpm_list_t *noupgrade;
	alpm_list_t *noextract;
	char *xfercommand;

	/* our connection to libalpm */
	alpm_handle_t *handle;

	alpm_list_t *explicit_adds;
	alpm_list_t *explicit_removes;
} config_t;

/* Operations */
enum {
	PM_OP_MAIN = 1,
	PM_OP_REMOVE,
	PM_OP_UPGRADE,
	PM_OP_QUERY,
	PM_OP_SYNC,
	PM_OP_DEPTEST,
	PM_OP_DATABASE
};

/* Long Operations */
enum {
	OP_NOCONFIRM = 1000,
	OP_CONFIG,
	OP_IGNORE,
	OP_DEBUG,
	OP_NOPROGRESSBAR,
	OP_NOSCRIPTLET,
	OP_ASK,
	OP_CACHEDIR,
	OP_ASDEPS,
	OP_LOGFILE,
	OP_IGNOREGROUP,
	OP_NEEDED,
	OP_ASEXPLICIT,
	OP_ARCH,
	OP_PRINTFORMAT,
	OP_GPGDIR,
	OP_DBONLY,
	OP_FORCE
};

/* clean method */
enum {
	PM_CLEAN_KEEPINST = 1,
	PM_CLEAN_KEEPCUR = (1 << 1)
};

/* global config variable */
extern config_t *config;

config_t *config_new(void);
int config_free(config_t *oldconfig);

int config_set_arch(const char *arch);
int parseconfig(const char *file);
#endif /* _PM_CONF_H */

/* vim: set ts=2 sw=2 noet: */
