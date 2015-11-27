#ifndef ENTRADA_H
	#define ENTRADA_H

	#define ARRAY_SIZE 90000000
	#define _COUNT_ 0

	extern int countK;
	extern int countS;
	extern int countI;
	extern int countB;
	extern int countC;
	extern int counts;
	extern int countb;
	extern int countc;

	extern char src[ARRAY_SIZE];

	//#define _DEBUG_ 
	#ifdef _DEBUG_
		#define DEBUG_PRINT(x) printf(x)
	#else
		#define DEBUG_PRINT(x)
	#endif
	
#endif
