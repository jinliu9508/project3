/*
CMPSC 473
Project 3
Team: Ghunley Zhang, Jinwei Liu

*/

#include "MyVirtualMemManager.h"
#include <iostream>

MyVirtualMemManager::MyVirtualMemManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA)
	: virtualMemoryManagerInterface(p, pS, nF, vA){

}