#include "sequence.h"

Sequence::Sequence(std::string desc, std::string seq){
    description = desc;
    sequence = seq;
}
Sequence::Sequence(){
    description = "NULL";
    sequence = "NULL";
}
