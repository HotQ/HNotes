#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ncurses.h"
#include "mysql.h"
#include <locale.h>

#include "hn_dbLogin.h"
#include "hn_mysqlOperation.h"
#include "hn_memoryManager.h"
#include "hn_duLinkList.h"
#include "hn_editor.h"
#define  initConfig()\
	start_color();\
	init_color(COLOR_BLACK, 0, 0, 0);\
	init_pair(1, COLOR_GREEN, COLOR_BLACK);\
	init_pair(2, COLOR_RED, COLOR_BLACK);\
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
