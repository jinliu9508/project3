#include "virtualMemoryManagerInterface.hpp"
#include <vector>

typedef struct {
	unsigned int framePosition;
	unsigned long long address;
} Frame;

class memoryManager : public virtualMemoryManagerInterface {
public:
	memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA)
		: virtualMemoryManagerInterface(p, pS, nF, vA){};		// constructor
	~memoryManager();		// destructor

	vector<Frame> frames;		// store virtual memory addresses
	vector<unsigned int> order;
	unsigned long long pageSize;
	bool isFramesFull;

	// other functions
	unsigned long long memoryAccess(unsigned long long address) override;
	void swap(unsigned int frameNumber, unsigned int pageNumber);
	unsigned long long& numberPageSwaps();
};