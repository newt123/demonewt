/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * compile.h - compile parsed jam statements
 *
 * 06/01/94 (seiwald) - new 'actions existing' does existing sources
 * 08/23/94 (seiwald) - Support for '+=' (append to variable)
 */

void compile_builtins();
void compile_foreach();
void compile_if();
void compile_include();
void compile_rule();
void compile_rules();
void compile_set();
void compile_setcomp();
void compile_setexec();
void compile_settings();
void compile_switch();

/* Flags for compile_set(), etc */

# define ASSIGN_SET	0x00	/* = assign variable */
# define ASSIGN_APPEND	0x01	/* += append variable */
# define ASSIGN_DEFAULT	0x02	/* set only if unset */

/* Flags for compile_setexec() */

# define EXEC_UPDATED	0x01	/* executes updated */
# define EXEC_TOGETHER	0x02	/* executes together */
# define EXEC_IGNORE	0x04	/* executes ignore */
# define EXEC_QUIETLY	0x08	/* executes quietly */
# define EXEC_PIECEMEAL	0x10	/* executes piecemeal */
# define EXEC_EXISTING	0x20	/* executes existing */

/* Conditions for compile_if() */

# define COND_NOT	0	/* ! cond */
# define COND_AND	1	/* cond && cond */
# define COND_OR	2	/* cond || cond */

# define COND_EXISTS	3	/* arg */
# define COND_EQUALS	4	/* arg = arg */
# define COND_NOTEQ	5	/* arg != arg */
# define COND_LESS	6	/* arg < arg  */
# define COND_LESSEQ	7	/* arg <= arg */
# define COND_MORE	8	/* arg > arg  */
# define COND_MOREEQ	9	/* arg >= arg */
