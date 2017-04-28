#include "memoryManager.h"


int main()
{
	
	memoryManager FIFO(FIFO, 1, 4, 8);
	memoryManager LRU(LRU, 4, 4, 8);

	unsigned long long returnValue1[12];
	unsigned long long returnValue2[12];

	//FIFO
	cout << "FIFO result\n";
	returnValue1[0] = FIFO.memoryAccess(0);
	returnValue1[1] = FIFO.memoryAccess(2);
	returnValue1[2] = FIFO.memoryAccess(1);
	returnValue1[3] = FIFO.memoryAccess(6);
	returnValue1[4] = FIFO.memoryAccess(4);
	returnValue1[5] = FIFO.memoryAccess(0);
	returnValue1[6] = FIFO.memoryAccess(1);
	returnValue1[7] = FIFO.memoryAccess(0);
	returnValue1[8] = FIFO.memoryAccess(3);
	returnValue1[9] = FIFO.memoryAccess(1);
	returnValue1[10] = FIFO.memoryAccess(2);
	returnValue1[11] = FIFO.memoryAccess(1);

	cout << "\tReturn values for FIFO:\n";
	for (int i = 0; i < 12; i++) {
		cout << returnValue1[i] << " ";
	}
	cout << "\n\tnumber of swap: " << FIFO.numberPageSwaps() << "\n\n";

	// LRU
	cout << "\n\nLRU result\n";
	returnValue2[0] = LRU.memoryAccess(0);
	returnValue2[1] = LRU.memoryAccess(2);
	returnValue2[2] = LRU.memoryAccess(1);
	returnValue2[3] = LRU.memoryAccess(6);
	returnValue2[4] = LRU.memoryAccess(4);
	returnValue2[5] = LRU.memoryAccess(0);
	returnValue2[6] = LRU.memoryAccess(1);
	returnValue2[7] = LRU.memoryAccess(0);
	returnValue2[8] = LRU.memoryAccess(3);
	returnValue2[9] = LRU.memoryAccess(1);
	returnValue2[10] = LRU.memoryAccess(2);
	returnValue2[11] = LRU.memoryAccess(1);
	
	cout << "\tReturn values for LRU:\n";
	for (int i = 0; i < 12; i++) {
		cout << returnValue2[i] << " ";
	}
	cout << "\n\tnumber of swap: " << LRU.numberPageSwaps() << "\n\n";

	return 0;
}
