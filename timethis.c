#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ArgCount, char *Args[])
{
	LARGE_INTEGER Frequency, Before, After, Elapsed, ZeroTime;
	QueryPerformanceFrequency(&Frequency);

	QueryPerformanceCounter(&Before);
	system(" ");
	QueryPerformanceCounter(&After);
	ZeroTime.QuadPart = After.QuadPart - Before.QuadPart;

	ZeroTime.QuadPart *= 1000000;
	ZeroTime.QuadPart /= Frequency.QuadPart;
	double ZeroTimeD = (float)ZeroTime.QuadPart / 1000000;

	int ZeroCorrection = 320;

	if(ArgCount <= 1)
	{
		printf("Time when not testing anything (i.e. program error): %fs\n\n"
			   "If you intended to test a command, please type that after the name\n"
			   "of this program, or drag it onto the exe.\n", ZeroTimeD);
		return 0;
	}

	char ArgsString[1024] = {0};
	char *NextSeg = ArgsString;
	for(int ArgI = 1; ArgI < ArgCount; ++ArgI)
	{
		sprintf(NextSeg, "%s ", Args[ArgI]);
		NextSeg += strlen(Args[ArgI]) + 1;
	}
	*--NextSeg = '\0';
	QueryPerformanceCounter(&Before);
	system(ArgsString);
	QueryPerformanceCounter(&After);

	Elapsed.QuadPart = After.QuadPart - Before.QuadPart;

	Elapsed.QuadPart *= 1000000;
	Elapsed.QuadPart /= Frequency.QuadPart;
	Elapsed.QuadPart -= (ZeroTime.QuadPart - ZeroCorrection);
	double ElapsedD = (float)Elapsed.QuadPart / 1000000;

	/* printf("%lldus\n", Elapsed.QuadPart); */
	printf("Time elapsed: %.04fs\n", ElapsedD);

	return 0;
}
