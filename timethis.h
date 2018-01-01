#if !defined(TIME_THIS_H)
#ifndef _WINDOWS_
#include <windows.h>
#endif

#define INITTIMER() LARGE_INTEGER TimeThisTimerFrequency, TimeThisTimerBefore, TimeThisTimerAfter, TimeThisTimerElapsed;\
					QueryPerformanceFrequency(&TimeThisTimerFrequency)

#define STARTTIMER() QueryPerformanceCounter(&TimeThisTimerBefore)

#define ENDTIMER() QueryPerformanceCounter(&TimeThisTimerAfter);\
	TimeThisTimerElapsed.QuadPart = TimeThisTimerAfter.QuadPart - TimeThisTimerBefore.QuadPart;\
	TimeThisTimerElapsed.QuadPart *= 1000000;\
	TimeThisTimerElapsed.QuadPart /= TimeThisTimerFrequency.QuadPart

#define TIMETAKEN(out) out = TimeThisTimerElapsed

#define ENDTIMERRESULT(out) ENDTIMER(); TIMETAKEN(out)

#define TIMETHISTIMING(function)\
	STARTTIMER();\
	function;\
	ENDTIMER();

#define TIMETHIS(function, out)\
	TIMETHISTIMING(function);\
	TIMETAKEN(out)

#define PRINTLASTTIMING(function, file, secfraction) if(file)\
	{\
		fprintf(file, "Time taken for `"#function"` was %f seconds.\n",\
				(double)TimeThisTimerElapsed.QuadPart / (1000000/secfraction));\
	}\

/* #define quicktimethis(function, file)\ */
/* 	if(TimeThisTimerFrequency.QuadPart == 0)\ */
/* 	{\ */
/* 		inittimer();\ */
/* 	}\ */
/* 	timethistiming(function);\ */
/* 	printlasttiming(function, file, 1)\ */

#define TIME_THIS_H
#endif
