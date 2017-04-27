/*
CMPSC 473
Project 3
Team: Ghunley Zhang, Jinwei Liu

*/

#include "memoryManager.h"
#include <iostream>

memoryManager::memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA)
	: virtualMemoryManagerInterface(p, pS, nF, vA){

	pageSize = pow(2, N);
	isFramesFull = false;

	// initialize the table with -1 (empty)
	for (int i = 0; i < numFrames; i++){
		Frame f;
		f.framePosition = i;
		f.address = -1;
		frames.push_back(f);
	}
	
};

unsigned long long memoryManager::memoryAccess(unsigned long long address) {
	bool placed = 0;			// signal to check whether a page is placed

	// the table is not fully used yet, compulsory miss and push
	if (!isFramesFull) {
		auto frame_i = frames.begin();
		while (frame_i != frames.end()) {
			if (frame_i->address == -1) {
				// place the page in frames
				frame_i->address = address;
				order.push_back(frame_i->framePosition);		// store the position
				placed = 0;										// successfully placed
			}
		}
	}
	

	
}

void memoryManager::swap(unsigned int frameNumber, unsigned int pageNumber) {
	// swap the first-in 
	if (policy == FIFO) {

	}

	// swap the least-recent-used
	else if (policy == LRU) {

	}
}