/*
CMPSC 473
Project 3
Team: Ghunley Zhang, Jinwei Liu

*/

#include "memoryManager.h"
#include <iostream>

memoryManager::memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA)
	: virtualMemoryManagerInterface(p, pS, nF, vA){

	isFramesFull = false;

	// initialize the table with -1 (empty)
	for (unsigned int i = 0; i < numFrames; i++){
		Frame f;
		f.framePosition = i;
		f.address = -1;
		frames.push_back(f);
	}
	
};

memoryManager::~memoryManager(){
	isFramesFull = false;
	frames.clear();
}

unsigned long long memoryManager::memoryAccess(unsigned long long address) {
	// the table is not fully used yet, compulsory miss and push
	auto frame_i = frames.begin();
	if (!isFramesFull) {
		while (frame_i != frames.end()) {
			if (frame_i->address == -1) {
				// place the page in frames
				frame_i->address = address;
				order.push_back((unsigned int)frame_i->framePosition);		// store the position
				cout << "\t**" << address << " is stored at frame " << frame_i->framePosition << endl;
				return frame_i->framePosition;
			}
			frame_i++;
		}
	}
	
	// no compulsory miss
	isFramesFull = true;		// do not need to check compulsory miss
	// find if the address is already in memory
	auto pos = order.begin();
	while (pos != order.end()) {
		if (frames[*pos].address == address)
			break;
		pos++;
	}
	
	if (pos != order.end()) {
		// hit, do not need to swap
		// update least recent used since this frame has just been referenced
		unsigned int framePos = *pos;
		cout << "\t**" << address << " hits, stored at frame " << framePos << endl;

		if (policy == LRU) {
			unsigned int orderPos;
			// find position in order that store *pos
			for (unsigned int i = 0; i < numFrames; i++){
				if (order[i] == framePos) {
					orderPos = i;
					break;
				}
			}
			// erase and push it to the last
			order.erase(order.begin() + orderPos);
			order.push_back(framePos);
		}


		return framePos;
	}
	else {
		// miss, swap
		unsigned int posToBeSwapped = order.front();
		cout << "\t**" << address << " misses, swap to frame " << posToBeSwapped << endl;
		swap(order.front(), address);

		order.erase(order.begin());
		order.push_back(posToBeSwapped);

		/*
		// print order
		for (unsigned int i = 0; i < numFrames; i++){
			cout << order[i] << " ";
		}
		cout << endl;
		*/
		return posToBeSwapped;
	}
	
}


void memoryManager::swap(unsigned int frameNumber, unsigned int pageNumber) {
	frames[frameNumber].address = pageNumber;
	numSwaps++;
	cout << "\t\tnumswap: " << numSwaps << "\n";
}
unsigned long long& memoryManager::numberPageSwaps() {
	return numSwaps;
}
