#ifndef BE_MACHINE_H_
#define BE_MACHINE_H_

#include "global.h"

#ifndef ERUNTIME
object start_backend(object x);
#endif

#ifdef EWINDOWS
extern HINSTANCE *open_dll_list;
extern int open_dll_size;
extern int open_dll_count;
#endif

extern int c_routine_next;         /* index of next available element */
extern int c_routine_size;         /* number of c_routine structs allocated */
extern struct arg_info *c_routine; /* array of c_routine structs */

extern char TempBuff[TEMP_SIZE]; /* buffer for error messages */

extern struct videoconfig config;
extern struct videoconfigEx configEx;

extern int allow_break;
extern int control_c_count;

extern unsigned current_fg_color;
extern unsigned current_bg_color;

extern char *crash_msg;
extern long *crash_list;       // list of routines to call when there's a crash
extern int crash_routines;    // number of routines
extern int crash_size;        // space allocated for crash_list

extern long *profile_sample;
extern volatile long sample_next;

extern int first_mouse;

extern int line_max; /* current number of text lines on screen */
extern int col_max;  /* current number of text columns on screen */

#ifdef EUNIX
int consize_ioctl;	/* 1 if line_max or col_max came from ioctl */
#endif

void EndGraphics();
void InitGraphics();
object SetTColor(object x);
object SetBColor(object x);

object machine(object opcode, object x);
void noecho(int wait);
void blank_lines(int line, int n);
void RestoreConfig();
char *name_ext(char *s);
void echo_wait();
object memory_copy(object d, object s, object n);
object memory_set(object d, object v, object n);
unsigned long get_pos_int(char *where, object x);

void NewConfig(int raise_console);
double current_time();
void Machine_Handler(int sig_no);

object Wrap(object x);

IFILE long_iopen(char *name, char *mode);

#endif