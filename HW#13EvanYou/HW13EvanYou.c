// HW #13: Evan You 
// Not using a void pointer.
// More efficient CollectData() function.
//Using HW12.2 Solution
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FLUSH while (getchar()!='\n')
double dRand(void);
int Setup(int *pnChan, int *pnPt);
int CollectData(int nChan, int nPt, double Data[][nPt]);
int WriteBinary(int nChan, int nPt, double Data[][nPt], const char * pfname);
int ReadBinary(int nChan, int nPt, double Data[][nPt], const char * pfname);
int AvgData(int nChan, int nPt, double Data[][nPt], double Avg[]); 
int Results(int nChan, double Avg[]);

int main(void) {
	int nChan, nPt; 
	long MemSize;
	puts("HW #13:  Evan You\n");
   
	srand((unsigned int) time(0));  // Initialize random number generate.
	rand(); rand(); rand();         // Optional, discards a few random numbers.
   
	// Measurement loop, exit when Setup() returns -1 or a nonzero value.   
	while (Setup(&nChan,&nPt)==0) {
   	MemSize = sizeof(double)*nChan*nPt;
   	double (*pData)[nPt] = (double (*)[nPt]) malloc(MemSize);  // Type cast the pointer returned
   	if (pData==NULL)
   		puts("\nNot enough memory available, please select fewer\n"
   			"channels and/or fewer data points.");
   	else { // Memory okay, continue with process.
   		CollectData(nChan,nPt,pData);
   		printf("Number of Channels: %d\n",nChan);
   		printf("Number of points per channel: %d\n",nPt);
   		printf("Memory allocated for data the data: %ld bytes\n",MemSize);
   		printf("Data memory address: %p\n\n",pData);
			free(pData);
		}
	}
	return 0;
}

// Generate a random number between 0 and 10.
double dRand(void) {
	return rand()*(10.0/RAND_MAX);
}

// Prompt user for number of channels and data points.
int Setup(int *pnChan, int *pnPt) {
	char prompt[] = "Select number of data points:\n  2) 2048   4) 4096  8) 8192  q) Quit";
	int ch;
	*pnPt = 0;  // Initialize argument to zero.
	do {
		fputs("Enter number of input channels [2-10] (0 to quit): ",stdout);
		while (scanf("%d",pnChan)==0){
			FLUSH;
			puts("Invalid input, please enter number of channels [2-10]. (0 to quit)");
		}
	} while ((*pnChan<2 || *pnChan>10) && (*pnChan!=0));
	
	FLUSH;
	if (*pnChan>1) {
		do {
			puts(prompt);
			if ((ch=getchar())!='\n') FLUSH;
			switch (ch) {
				case '2': 	*pnPt = 2048;
								break;
				case '4':	*pnPt = 4096;
						   	break;
				case '8':	*pnPt = 8192; // Do not need a break here.
				case 'q':	break; // Skip default and exit do while
				default: 	puts("Invalid selection.");
			}
		} while (*pnPt==0 && ch!='q');
	}
	return ((*pnChan>1) && (*pnPt>0)) ? 0: -1;
}

// Assign random values by incrementing a pointer.
int CollectData(int nChan, int nPt, double Data[][nPt]) {
	double *pi = (double *) Data;
	double *piEnd = pi + nChan*nPt;
	while (pi < piEnd)
		*pi++ = dRand();   
	return 0;
}

//Writes data to file 
int WriteBinary(int nChan, int nPt, double Data[][nPt], const char * pfname)
{
    

    return 0;
}

//Reads data to file
int ReadBinary(int nChan, int nPt, double Data[][nPt], const char * pfname)
{

    return 0;
}

//
int AvgData(int nChan, int nPt, double Data[][nPt], double Avg[])
{
    return 0;
}



//	HW #11a:  Ken Pottebaum
//	
//	Enter number of input channels [2-10] (0 to quit): 4
//	Select number of data points:
//	  2) 2048   4) 4096  8) 8192  q) Quit
//	4
//	Number of Channels: 4
//	Number of points per channel: 4096
//	Memory allocated for data the data: 131072 bytes
//	Data memory address: 0000000000630080
//	
//	Enter number of input channels [2-10] (0 to quit): 2
//	Select number of data points:
//	  2) 2048   4) 4096  8) 8192  q) Quit
//	8
//	Number of Channels: 2
//	Number of points per channel: 8192
//	Memory allocated for data the data: 131072 bytes
//	Data memory address: 0000000000630080
//	
//	Enter number of input channels [2-10] (0 to quit): 0
//	
//	--------------------------------
//	Process exited after 27.49 seconds with return value 0
//	Press any key to continue . . .
