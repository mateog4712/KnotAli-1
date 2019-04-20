#ifndef HFOLD_CONSENSUS_SEQUENCE_H
#define HFOLD_CONSENSUS_SEQUENCE_H

#include <stdlib.h>
#include <vector>
/**
 * Joseph Zieg Mar 4 2019
 * Helper functions for converting MSA input files to consensus sequence and base restrictions.
 *
 * TODO: May want to restructure validation functions to take in pointers for variables instead of returning a pointer.
 */

enum format {
    MSA_UNKNOWN = 0, MSA_CLUSTAL = 1, MSA_FASTA = 2
};

/**
 * Generates a consensus sequence from the specified input file, using the metric of highest nucleotide frequency above
 * background frequency. Writes the generated sequence using 'ACGU' chars to the corresponding variable.
 * Returns true/false depending on success.
 * @param seqList The vector of sequences to generate consensus from.
 * @param seq The variable to write the sequence to.
 * @return
 */
bool generateConsensusSequence(std::vector<std::string> seqList, char *seq);

/**
 * TODO: Implement functionality.
 * Generates a restriction sequence for HFold using a Shannon entropy for each column.
 * Writes the generated sequence using '(_' chars to the corresponding variable.
 * Returns true/false depending on success.
 * @param seqList The vector of sequences to generate consensus from.
 * @param struc The variable to write the structure to.
 * @return
 */
bool generateRestrictionStructure(std::vector<std::string> seqList, char *struc);

/**
 * Reads FASTA type MSA files. Does not check for actual FASTA format, checks done previously in detectMSAValidFormat.
 *
 * Should not be called outside readMSASequences.
 *
 * @param path The directory location of the file.
 * @return A char array of the RNA sequences.
 */
std::vector<std::string> readFASTASequences(char *path);

/**
 * Reads CLUSTALw type MSA files. Does not check for actual FASTA format, checks done previously in detectMSAValidFormat.
 *
 * Should not be called outside readMSASequences.
 *
 * @param path The directory location of the file.
 * @return A char array of the RNA sequences.
 */
std::vector<std::string> readCLUSTALwSequences(char *path);

/**
 * Master function for determining file type and reading an MSA file into a sequence list. Takes the determined
 * file type from hfold_validation and reads into a sequence list for use in generating a consensus sequence.
 *
 * @param path The directory location of the file.
 * @param type The MSA file type, currently only CLUSTALw or FASTA.
 * @return The
 */
std::vector<std::string> readMSASequences(char *path, format type);

/**
 * Detects if specified filepath contains a valid and accepted MSA file header.
 *
 * @param path The directory location of the file.
 * @return MSA format enum depending on file type, MSA_UNKNOWN if not found and or incorrect format of file.
 */
format detectMSAValidFormat(char *path);

#endif //HFOLD_CONSENSUS_SEQUENCE_H
