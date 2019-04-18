//Joseph Zieg March 4 2019

#include "msa_utils.h"
#include "constants.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//TODO Implement functionality
bool generateConsensusSequence(std::vector<std::string> seqList, char *seq) {

}

//TODO Implement functionality
bool generateRestrictionStructure(std::vector<std::string> seqList, char *struc) {

}

format detectMSAValidFormat(char *path) {
    std::ifstream fp;
    std::string header; // char array for buffer dequeue
    size_t found; // flag for header verification.

    fp.open(path);
    if(!fp){
        return MSA_UNKNOWN;
    }
    std::getline(fp, header);
    found = header.find(">");
    if (found != std::string::npos) {
        return MSA_FASTA;
    }
    found = header.find("CLUSTAL");
    if (found != std::string::npos) {
        return MSA_CLUSTAL;
    }
    return MSA_UNKNOWN;
}

std::vector<std::string> readMSASequences(char *path, format type) {
    std::ifstream fp;
    std::string temp; // char array for buffer dequeue
    std::vector<std::string> seqList;

    switch (type) {
        case MSA_FASTA:
            seqList = readFASTASequences(path);
            break;
        default:
            printf("Something went wrong with reading the file.");
            break;
    }
    return seqList;
}

std::vector<std::string> readFASTASequences(char *path) {
    std::ifstream fp;
    std::string temp, seq; //char array for buffer dequeue
    std::vector<std::string> seqList;

    fp.open(path);
    if (!fp) {
        printf("File not found\n");
        exit(EXIT_FAILURE);
    }

    while (getline(fp, temp).good()) {
        // iterate through FASTA file, copy individual seq lines into single string,
        // add to arr as new sequence comes up.
        if (temp.empty() || temp[0] == '>') {
            if (!seq.empty()) {
                seqList.emplace_back(seq);
                seq.clear();
            }
        } else if (!temp.empty()) {
            seq += temp;
        }
    }
    if (!seq.empty()) {
        seqList.emplace_back(seq);
        seq.clear();
    }
    fp.close();

    return seqList;
}
