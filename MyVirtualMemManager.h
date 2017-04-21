#include "virtualMemoryManagerInterface.hpp"
#include <iostream>

class MyVirtualMemManager : public virtualMemoryManagerInterface {
public:
	MyVirtualMemManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA);		// constructor
	~MyVirtualMemManager();		// destructor

	// other functions
	unsigned long long memoryAccess(unsigned long long address) override;
	void swap(unsigned int frameNumber, unsigned int pageNumber);
	unsigned long long& numberPageSwaps();
};