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
	char * fileName = "binary.xxx";
	puts("HW #13:  Evan You\n");
   
	srand((unsigned int) time(0));  // Initialize random number generate.
	rand(); rand(); rand();         // Optional, discards a few random numbers.
   
	// Measurement loop, exit when Setup() returns -1 or a nonzero value.   
	while (Setup(&nChan,&nPt)==0) {
   	MemSize = sizeof(double)*nChan*nPt;
	double AvgArr[nPt];
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
		WriteBinary(nChan,nPt,pData, fileName);
		double (*binArray)[nPt] = (double (*)[nPt]) malloc(MemSize);
		if (binArray==NULL) //check to see memory is available  
		{
			fputs("Memory was unable to be allocated to second array. Data will overwrite previous array.\n", stdout);
			ReadBinary(nChan, nPt, pData, fileName);
			AvgData(nChan, nPt, pData, AvgArr);
			Results(nChan, AvgArr);
		}
		else
		{
			ReadBinary(nChan,nPt, binArray, fileName);
			AvgData(nChan, nPt, binArray, AvgArr);
			Results(nChan, AvgArr);
			free(binArray);
		}

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
int CollectData(int nChan, int nPt, double Data[][nPt]) 
{
	double *pi = (double *) Data;
	double *piEnd = pi + nChan*nPt;
	while (pi < piEnd)
		*pi++ = dRand();   
	return 0;
}

//Writes data to file 
int WriteBinary(int nChan, int nPt, double Data[][nPt], const char * pfname)
{
    FILE * fp;
	fp = fopen(pfname, "wb"); //write binary 
	if(fp) //check if file was opened 
	{
		//Write into file
		fwrite(&nChan, sizeof(int), 1, fp);
		fwrite(&nPt, sizeof(int), 1, fp);
		fwrite(Data, sizeof(double) * nChan * nPt, 1, fp);
		fclose(fp); //close file 
	}
	else // if file == NULL
	{
		fputs("Unable to open file.\n", stdout);
		exit(EXIT_FAILURE);
	}
    return 0;
}

//Reads data to file
int ReadBinary(int nChan, int nPt, double Data[][nPt], const char * pfname)
{
    FILE * fp;
	int ch, pts, i,j;
	fp = fopen(pfname, "rb"); //read binary
	if(fp)
	{
		ch = getc(fp); // gets channel from file 
		fseek(fp, 4L, SEEK_SET); //move by sizeof(int)
		fread(&pts, sizeof(pts), 1, fp); // stores points 
		if (nChan== ch && pts == nPt) puts("Success in reading nChan and nPt\n"); //check if file is same as current 
		else printf("fail. nChan: %d\n points: %d \n",ch, pts);
		fread(Data, sizeof(double) * nChan * nPt, 1, fp);
		fclose(fp); //close file 
	}
	else
	{
		fputs("Unable to open file.\n", stdout);
		exit(EXIT_FAILURE);
	}
    return 0;
}

//stores average of each channel in data into avg array
int AvgData(int nChan, int nPt, double Data[][nPt], double Avg[])
{
	int r,c;
	double sum = 0;
	for (r=0; r<nChan; r++)
	{
		sum = 0; //reset sum after every pas
		for (c=0; c<nPt; c++)
		{
			sum += Data[r][c];
		}
		printf("Sum: %f\n",sum);
		Avg[r] = (sum / ((double) nPt)); //store into avg array
	}
    return 0;
}

//print result of avg array
int Results(int nChan, double Avg[])
{
	for (int i=0; i<nChan; i++)
		printf("Channel #%d Avg:%2.4f\n", i, Avg[i]);
	return 0;
}


