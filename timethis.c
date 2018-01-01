#define _CRT_SECURE_NO_WARNINGS
#include "timethis.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ArgCount, char *Args[])
{
	INITTIMER();
	LARGE_INTEGER ZeroTime;
	TIMETHIS(system(" "), ZeroTime);
	double ZeroTimeD = (double)ZeroTime.QuadPart / 1000000;

	int ZeroCorrection = 320;

	if(ArgCount <= 1)
	{
		printf("Time when not testing anything (i.e. program error): %fs\n\n"
			   "If you intended to test a command, please type that after the name\n"
			   "of this program, or drag it onto the exe.\n", ZeroTimeD);
		return 0;
	};

	char ArgsString[1024] = {0};
	char *NextSeg = ArgsString;
	for(int ArgI = 1; ArgI < ArgCount; ++ArgI)
	{
		sprintf(NextSeg, "%s ", Args[ArgI]);
		NextSeg += strlen(Args[ArgI]) + 1;
	}
	// NOTE: removes trailing space
	*--NextSeg = '\0';

	LARGE_INTEGER Elapsed;
	TIMETHIS(int Result = system(ArgsString), Elapsed);
	Elapsed.QuadPart -= (ZeroTime.QuadPart - ZeroCorrection);
	double ElapsedD = (double)Elapsed.QuadPart / 1000000;

	printf("Time elapsed: %.04fs\n", ElapsedD);

	return Result;
}
