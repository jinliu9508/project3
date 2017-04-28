#include "memoryManager.h"


int main()
{
	memoryManager test_FIFO(FIFO, 4, 4, 8);
	memoryManager test_LRU(LRU, 4, 4, 8);

	//FIFO
	cout << "FIFO result\n";
	test_FIFO.memoryAccess(0);	
	test_FIFO.memoryAccess(2);
	test_FIFO.memoryAccess(1);
	test_FIFO.memoryAccess(6);
	test_FIFO.memoryAccess(4);
	test_FIFO.memoryAccess(0);
	test_FIFO.memoryAccess(1);	
	test_FIFO.memoryAccess(0);
	test_FIFO.memoryAccess(3);
	test_FIFO.memoryAccess(1);
	test_FIFO.memoryAccess(2);
	test_FIFO.memoryAccess(1);

	// LRU
	cout << "\n\nLRU result\n";
	test_LRU.memoryAccess(0);
	test_LRU.memoryAccess(2);
	test_LRU.memoryAccess(1);
	test_LRU.memoryAccess(6);
	test_LRU.memoryAccess(4);
	test_LRU.memoryAccess(0);
	test_LRU.memoryAccess(1);
	test_LRU.memoryAccess(0);
	test_LRU.memoryAccess(3);
	test_LRU.memoryAccess(1);
	test_LRU.memoryAccess(2);
	test_LRU.memoryAccess(1);

	return 0;
}
