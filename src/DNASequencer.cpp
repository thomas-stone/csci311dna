#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <functional>

#include "algorithms.h"
#include "sequence.h"

std::string getInput(std::string prompt);
void setDefaults();
void startInterface();
void presentOptions();
std::string readFromFile(std::string fileName);
std::vector<Sequence> readSequencesFromFile(std::string fileName);
Sequence find_most_similar(std::string sequence, std::vector<Sequence> tests, std::function<int(std::string, std::string)> algorithm);

std::string queryFileName;
std::string allSequencesFileName;

int main(int argc, char const *argv[])
{
    std::cout << "-----------------------------------------\n";
    std::cout << "CSCI311 DNA Sequencer!! \n";
    std::cout << "Hit [ENTER] for default provided values\n";

    queryFileName = getInput("Enter name of file with query sequence: ");
    allSequencesFileName = getInput("Enter name of file with all sequences: ");

    setDefaults();
    startInterface();

    return 0;
}

/**
 * Simple Helper function to get input
 */
std::string getInput(std::string prompt)
{
    std::string inputString;
    std::cout << prompt;
    std::getline(std::cin, inputString);

    return inputString;
}

/**
 * Set default values for file names if [ENTER] was pressed.
 */
void setDefaults(){
    if (queryFileName.length() == 0){
        queryFileName = "./files/DNA_query.txt";
    }
    if (allSequencesFileName.length() == 0){
        allSequencesFileName = "./files/DNA_sequences.txt";
    }
}

/**
 * Simple Interface to get everything started
 */
void startInterface()
{
    presentOptions();

    std::string sequence = readFromFile(queryFileName);
    std::vector<Sequence> tests = readSequencesFromFile(allSequencesFileName);

    std::function<int(std::string, std::string)> algorithm = longestCommonSubstring;

    std::string choice = getInput("Enter Algorithm to use: ");
    if (std::stoi(choice) == 1)
        algorithm = longestCommonSubstring;
    else if (std::stoi(choice) == 2)
        algorithm = longestCommonSubsequence;
    else if (std::stoi(choice) == 3)
        algorithm = editDistance;
    // else if (std::stoi(choice) == 4)
    //     algorithm = needlemanWunsch;

    Sequence mostSimilar = find_most_similar(sequence, tests, algorithm);

    std::cout << "\n\nThe most similar sequence is: " << mostSimilar.description << std::endl;
}

/**
 *  Present the options
 */
void presentOptions()
{
    std::cout << "Algorithms Available to test Similarity\n";
    std::cout << "(1) Longest Common Substring\n";
    std::cout << "(2) Longest Common Subsequence\n";
    std::cout << "(3) Edit distance\n";
    //std::cout << "(4) Needleman-Wunsch Algorithm\n\n";
}

/**
 * Read single line from file and return that line
 */
std::string readFromFile(std::string fileName)
{   
    std::string sequence = "";
    std::string line;
    std::ifstream inputFile(fileName);

    if (inputFile.is_open())
    {
        while (std::getline(inputFile, line))
        {
            sequence.append(line);
        }
        inputFile.close();
    }

    else
        std::cout << "Unable to open file";

    return sequence;
}

/**
 * Read all lines from sequence file and push sequence into a vector
 * of Sequence objects containing the description and sequence
 */
std::vector<Sequence> readSequencesFromFile(std::string fileName)
{
    std::vector<Sequence> sequences;
    std::string seq = "NULL";
    std::string description = "NULL";
    std::string line;
    std::ifstream inputFile(fileName);

    if (inputFile.is_open())
    {
        while (std::getline(inputFile, line))
        {
            if (line.length() > 0 && line.at(0) == '>')
            {
                description = line;
                seq = "";
                while (std::getline(inputFile, line) && line.length() > 0 && line.at(0) != '>'){
                    seq.append(line);
                }
                Sequence sequence = Sequence(description, seq);
                sequences.push_back(sequence);
            }
        }
        //sequences.erase(sequences.begin());
        inputFile.close();
    }

    else
        std::cout << "Unable to open file";

    return sequences;
}

Sequence find_most_similar(std::string sequence, std::vector<Sequence> tests, std::function<int(std::string, std::string)> algorithm){
    int bestScore = 0;
    int score;
    Sequence bestSeq;
    for (auto test : tests){
        score = algorithm(sequence, test.sequence);
        // std::cout << "\n\nTesting: " << test.description << "\n";
        // std::cout << "Using: " << sequence << "\n";
        if (score >= bestScore){
            bestScore = score;
            bestSeq = test;
        }
    }

    std::cout << "Best Score: " << bestScore;
    return bestSeq;
}