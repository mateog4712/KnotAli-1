//Joseph Zieg March 4 2019

#include "msa_utils.h"
#include <libgen.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

//TODO Implement functionality
bool generateConsensusSequence(char* path, char* seq1){
    return false;
}

//TODO Implement functionality
bool generateMSARestrictionSequence(char* path, char* struc1){
    return false;
}

bool checkCLUSTALFormat(char* path){
    FILE* fp;
    char* header;
    char clustal[7];
    header = (char*) malloc(sizeof(char) * 100);
    strcpy(clustal, "CLUSTAL");

    fp = fopen(path, "r");
    if(!fp){
        printf("File not found\n");
        return false;
    }
    fscanf(fp,"%s\n", header);
    fclose(fp);
    //reads header information to determine CLUSTAL format
    if(strstr(header, clustal)){
        return true;
    }
    return false;
}
