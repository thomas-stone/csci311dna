#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>

/**
 * Longest Common Substring
 * identify the longest substring that is common to both s and t.  
 * The sequence with the longest substring in common will be most similar.
 * 
 * @param s the string to compare
 * @param t the string to test for similarity
 * 
 * @return int representing the length of longest common substring
 * */
int longestCommonSubstring(std::string s, std::string t);


/**
 * LCS - Longest-Common Subsequence
 * as presented in the dynamic programming unit. This is a generalization of  
 * the  Longest  Common  Substring,  where  you  now  allow  non-contiguous  
 * matches between both sequences tomaximize the number of matches. The sequence has the 
 * longest length match will be the most similar.
 * @param s the string to compare
 * @param t the string to test for similarity
 * 
 * @return int representing the length of longest common subsequence
 **/
int longestCommonSubsequence(std::string s, std::string t);

/**
 *  Edit distance
 *  this is another interesting approach used in practice (and also widely 
 *  used in the field ofcom-putational linguistics).  Given two sequences,
 *  s and t, how many ”edit operations” are required to transform one sequence 
 *  into the other?  The set of edit operations you would consider are 
 *  insertion, deletion and substitution. See https://en.wikipedia.org/wiki/Edit_distance
 *  for more information
 * 
 * @param s the string to compare
 * @param t the string to test for similarity
 * 
 * @return int representing the number of "edit" operations
 **/
int editDistance(std::string s, std::string t);

/**
 * Needleman-Wunsch Algorithm 
 * this is a classic bottom-up dynamic programming solution that is still 
 * use inbioinformatics tools today for aligning two sequences.  The following 
 * has a good description of the recurrence and subsequent algorithm
 * https://en.wikipedia.org/wiki/Needleman/OT1/textendash_Wunsch_algorithm
 * 
 * @param s the string to compare
 * @param t the string to test for similarity
 * 
 * @return 
 **/
int needlemanWunsch(std::string s, std::string t);

#endif // ALGORITHMS_H