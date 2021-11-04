## CSCI 311 DNA Sequencing
### Thomas Stone, Ryan Mosenkis, Jake Etzler

### Summary
This project is an interface that will prompt for two files. The first is the file containing some unknown sequence. The next is the one containing a list of known sequences. It will then run through an algorithm of your choosing to find the most similar sequence.

### Instructions
1. Navigate to this directory in terminal `cd ~/path/to/here `
2. make the project: `make`
3. To run: `./bin/dnasequencer`

### File Structure
This project assumes that the query file is the sequence and nothing else. Ex. 

*QueryFile.txt*  
```
AGCGTACCTTAGCGTACCTTAGCGTACCTTAGACCTACCT
ATCTACAAGCTACAAGCTACACGTACCTTAGCGTACCTTA
```
It also assumes that the test file contains a series of sequences formatted by the **FASTA** file format. 
EX. 

*TestSequences.txt*
```
>Test 1
AGCTACAAGCTACAAGCTACA
>Test 2
CGTACCTTAGCGTACCTTAG
```

### Interface Features
For simplicity, we have added default options rather than having to enter the path to the file the same time. Simply hit `Enter` `Enter` to use the defaults. 