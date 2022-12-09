/*
	If you find any mistakes in this file
	please let me know, so I can fix them and reupload
	fixed version for everyone.
*/

#include "SimulatedOS.h"


int main()
{
  SimulatedOS osSim{1, 300, 100};

  osSim.NewProcess(10); // 1
  osSim.NewProcess(20); // 2
  osSim.NewProcess(4); // 3

  osSim.DiskReadRequested(0, "Hw.txt");
  osSim.PrintCPU();
  osSim.PrintReadyQueue();
  osSim.PrintDisk(0);
  osSim.PrintDiskQueue(0);
  std::cout << std::endl;

  osSim.DiskReadRequested(0, "TestHW.txt");
  osSim.PrintCPU();
  osSim.PrintReadyQueue();
  osSim.PrintDisk(0);
  osSim.PrintDiskQueue(0);
std::cout << std::endl;
  osSim.DiskReadRequested(0, "Testing.txt");
  osSim.PrintCPU();
  osSim.PrintReadyQueue();
  osSim.PrintDisk(0);
  osSim.PrintDiskQueue(0);
std::cout << std::endl;
  osSim.DiskJobCompleted(0);
  osSim.PrintCPU();
  osSim.PrintReadyQueue();
  osSim.PrintDisk(0);
  osSim.PrintDiskQueue(0);
std::cout << std::endl;
  osSim.DiskJobCompleted(0);
  osSim.PrintCPU();
  osSim.PrintReadyQueue();
  osSim.PrintDisk(0);
  osSim.PrintDiskQueue(0);
std::cout << std::endl;
  osSim.DiskJobCompleted(0);
  osSim.PrintCPU();
  osSim.PrintReadyQueue();
  osSim.PrintDisk(0);
  osSim.PrintDiskQueue(0);
  osSim.PrintReadyQueue();
std::cout << std::endl;
  osSim.DiskJobCompleted(0);
  osSim.Exit();
  osSim.PrintCPU();
  osSim.PrintReadyQueue();
  osSim.PrintDisk(0);
  osSim.PrintDiskQueue(0);

//   osSim.PrintRAM();

//   osSim.NewProcess(40);
//   osSim.PrintRAM();

//   osSim.NewProcess(20);
//   osSim.PrintRAM();

//   osSim.Exit();
//   osSim.PrintRAM();

//   osSim.FetchFrom(4000);
//   osSim.PrintRAM();

//   osSim.Exit();
//   osSim.PrintRAM();

//   osSim.FetchFrom(400);
//   osSim.FetchFrom(300);
//   osSim.PrintRAM();

//   osSim.DiskReadRequested(0, "test.txt");
//   osSim.NewProcess(5);
//   osSim.PrintRAM();
//   osSim.NewProcess(5);
//   osSim.NewProcess(5);
//   osSim.PrintRAM();

//   osSim.DiskJobCompleted(0);
//   osSim.PrintRAM();
//   return 0;
}