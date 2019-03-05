#ifndef HFOLD_CONSENSUS_SEQUENCE_H
#define HFOLD_CONSENSUS_SEQUENCE_H
//Joseph Zieg Mar 4 2019
//Helper functions for converting MSA input files to consensus sequence and base restrictions.

//Generates a consensus sequence from the specified input file, using the metric of highest nucleotide frequency above
//background frequency.
//Writes the generated sequence using 'ACGU' chars to the corresponding variable.
//Returns true/false depending on success.
bool generateConsensusSequence(char* path, char* seq1);

//Generates a restriction sequence for HFold using a Shannon entropy for each column.
//Writes the generated sequence using '._' chars to the corresponding variable.
//Returns true/false depending on success.
bool generateMSARestrictionSequence(char* path, char* struc1);

//Checks if specified filepath contains a valid CLUSTAL format header
//Returns true/false depending on file not found and correct format of file.
bool checkCLUSTALFormat(char* path);
#endif //HFOLD_CONSENSUS_SEQUENCE_H
