/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * mkjambase.c - turn Jambase into a big C structure
 *
 * Usage: mkjambase Jambase jambase.c
 *
 * Results look like this:
 *
 *	 char *jambase[] = {
 *	 "...\n",
 *	 ...
 *	 0 };
 *
 * Handles \'s and "'s specially; knows to delete blank and comment lines.
 *
 */

# include <stdio.h>

main( argc, argv )
int argc;
char **argv;
{
	char buf[ 1024 ];
	FILE *fin;
	FILE *fout;

	if( argc != 3 )
	{
	    fprintf( stderr, "usage: %s Jambase jambase.c\n", argv[0] );
	    return -1;
	}

	if( !( fin = fopen( argv[1], "r" ) ) )
	{
	    perror( argv[1] );
	    return -1;
	}

	if( !( fout = fopen( argv[2], "w" ) ) )
	{
	    perror( argv[2] );
	    return -1;
	}

	fprintf( fout, "/* Generated by mkjambase from Jambase */\n" );
	fprintf( fout, "char *jambase[] = {\n" );

	while( fgets( buf, sizeof( buf ), fin ) )
	{
	    char *p = buf;

	    /* Strip leading whitespace. */

	    while( *p == ' ' || *p == '\t' || *p == '\n' )
		p++;

	    /* Drop comments and empty lines. */

	    if( *p == '#' || !*p )
		continue;

	    /* Copy */

	    putc( '"', fout );

	    for( ; *p && *p != '\n'; p++ )
		switch( *p )
	    {
	    case '\\':	putc( '\\', fout ); putc( '\\', fout ); break;
	    case '"': putc( '\\', fout ); putc( '"', fout ); break;
	    default: putc( *p, fout ); break;
	    }

	    fprintf( fout, "\\n\",\n" );
	}
	    
	fprintf( fout, "0 };\n" );

	return 0;
}
