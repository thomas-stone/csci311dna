#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>

/**
 * Simple Class to represent a DNA Sequence
 */
class Sequence {
    public:
        Sequence();
        Sequence(std::string desc, std::string seq);
        std::string description;
        std::string sequence; 
};

#endif // SEQUENCE_H