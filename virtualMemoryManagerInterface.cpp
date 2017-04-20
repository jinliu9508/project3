/*
	CMPSC 473
	Project 3
	Team: Ghunley Zhang, Jinwei Liu

*/

#include "virtualMemoryManagerInterface.hpp"
#include <iostream>

virtualMemoryManagerInterface::virtualMemoryManagerInterface(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) 
	: policy(p), N(pS), numFrames(nF), virtualAddressSpaceSize(vA) {

}

void virtualMemoryManagerInterface::swap(unsigned int frameNumber, unsigned int pageNumber) {

}
