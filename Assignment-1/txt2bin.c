/*
 txt2bin.c
 
 MY NAME: Nick Miller
 MY PITT EMAIL: nam99@pitt.edu
 
 As you develop and test this file:
 
 use this command to compile: (you can name the executable whatever you like)
 gcc -W -Wall -Wextra -O2  txt2bin.c  -o txt2bin.exe
 
 use this command to execute:  (you will of course test on both input files)
 txt2bin.exe sine-1.bin
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )
{
    FILE* txtFile, *binFile;
    short int shortVal;
    int countLines = 0;
    
    
    if (argc<3)
    {
        printf("usage: %s  <infilename> <outfilename> (i.e. ./txt2bin.exe sine-1.txt sine-1.bin)\n", argv[0] );
        return EXIT_FAILURE;
    }
    
    txtFile = fopen( argv[1], "rt" );
    if (txtFile == NULL )
    {
        printf("Can't open %s for input. Program halting\n",argv[1] );
        return EXIT_FAILURE;
    }
    
    binFile = fopen( argv[2], "wb" );
    if (binFile == NULL )
    {
        printf("Can't open %s for output. Program halting\n",argv[2] );
        return EXIT_FAILURE;
    }
    
    /* YOUR CODE HERE
     
     read each value from the text file using fscanf as a short int and write it out to the binary file using fwrite
     */
//	short int f;    
    while(1){
        if(feof(txtFile)){
            break;
        }
	shortVal = 0;
        fscanf(txtFile, "%hi", &shortVal );
//        printf("\nInserting: %d", shortVal);
	
        fwrite(&shortVal, sizeof(shortVal), 1, binFile );
//	fwrite("\r\n", sizeof("\r\n"),1,binFile);
	countLines++;
	
	if(feof(txtFile)){
		break;
	}
    }
	
	int countLines2 = 0;    
    fclose( txtFile );
    fclose( binFile );
	FILE* fp;
	short int e;
	fp = fopen(argv[2],"rb");
	while(fread(&e,sizeof(e),1,fp)==1){
	   printf("%d\n",e);
	 countLines2++;
	}
//	printf("%d compared to %d", countLines, countLines2);
	fclose(fp);    
    return EXIT_SUCCESS;  // 0 value return means no errors
}
