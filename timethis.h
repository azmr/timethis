#ifndef _WINDOWS_
#include <windows.h>
#endif

#define inittimer() LARGE_INTEGER TimeThisTimerFrequency, TimeThisTimerBefore, TimeThisTimerAfter, TimeThisTimerElapsed;\
					TimeThisTimerFrequency.QuadPart = 0;\

#define timethistiming(function)\
	QueryPerformanceCounter(&TimeThisTimerBefore);\
	function;\
	QueryPerformanceCounter(&TimeThisTimerAfter);\
	TimeThisTimerElapsed.QuadPart = TimeThisTimerAfter.QuadPart - TimeThisTimerBefore.QuadPart;\
	TimeThisTimerElapsed.QuadPart *= 1000000;\
	TimeThisTimerElapsed.QuadPart /= TimeThisTimerFrequency.QuadPart\

#define timethis(function, out)\
	timethistiming(function);\
	out = TimeThisTimerElapsed\

#define printlasttiming(function, file, secfraction) if(file)\
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


