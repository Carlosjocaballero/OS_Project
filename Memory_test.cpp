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
  // CPU: 1
  osSim.PrintReadyQueue();
  // Ready-Queue: 3
  osSim.PrintDisk(0);
  // Disk 0: PID 2, "Hw.txt"
  osSim.PrintDiskQueue(0);
  // Disk 0 I/O queue: Empty
  std::cout << std::endl;

  osSim.DiskReadRequested(0, "TestHW.txt");
  osSim.PrintCPU();
  // CPU: 3
  osSim.PrintReadyQueue();
  // Ready-Queue: idle
  osSim.PrintDisk(0);
  // Disk 0: PID 2, "Hw.txt"
  osSim.PrintDiskQueue(0);
  // Disk 0 I/O queue: 1

std::cout << std::endl;
  osSim.DiskReadRequested(0, "Testing.txt");
  osSim.PrintCPU();
  // CPU: idle
  osSim.PrintReadyQueue();
  // Ready-Queue: idle
  osSim.PrintDisk(0);
  // Disk 0: PID 2, "Hw.txt"
  osSim.PrintDiskQueue(0);
  // Disk 0 I/O queue: 1 3

std::cout << std::endl;
  osSim.DiskJobCompleted(0);
  osSim.PrintCPU();
  // CPU: 2
  osSim.PrintReadyQueue();
  // Ready-Queue: idle
  osSim.PrintDisk(0);
  // Disk 0: PID 1, "TestHW.txt"
  osSim.PrintDiskQueue(0);
  // Disk 0 I/O Queue: 3

std::cout << std::endl;
  osSim.DiskJobCompleted(0);
  osSim.PrintCPU();
  // CPU: 2
  osSim.PrintReadyQueue();
  // Ready-Queue: 1
  osSim.PrintDisk(0);
  // Disk 0: PID 3, "Testing.txt"
  osSim.PrintDiskQueue(0);
  // Disk 0 I/O Queue: Empty

std::cout << std::endl;
  osSim.DiskJobCompleted(0);
  osSim.PrintCPU();
  // CPU: 2
  osSim.PrintReadyQueue();
  // Ready-Queue: 1 3
  osSim.PrintDisk(0);
  // Disk 0: idle
  osSim.PrintDiskQueue(0);
  // Disk 0 I/O Queue: empty

std::cout << std::endl;
  osSim.DiskJobCompleted(0);
  // Instruction ignored. Request disk is idle and has no queue
  osSim.Exit();
  osSim.PrintCPU();
  // CPU: 1
  osSim.PrintReadyQueue();
  // Ready-Queue: 3
  osSim.PrintDisk(0);
  // Disk 0: idle
  osSim.PrintDiskQueue(0);
  // Disk I/O queue: Empty

  osSim.PrintRAM();
  /*
  Frame Page PID
  0     0    1
  1     -1   -1
  2     0    3
  */


  osSim.NewProcess(40);
  osSim.PrintRAM();
  /*
  Frame Page PID
```
  */

  osSim.NewProcess(20);
  osSim.PrintRAM();

  osSim.Exit();
  osSim.PrintRAM();

  osSim.FetchFrom(4000);
  osSim.PrintRAM();

  osSim.Exit();
  osSim.PrintRAM();

  osSim.FetchFrom(400);
  osSim.FetchFrom(300);
  osSim.PrintRAM();

  osSim.DiskReadRequested(0, "test.txt");
  osSim.NewProcess(5);
  osSim.PrintRAM();
  osSim.NewProcess(5);
  osSim.NewProcess(5);
  osSim.PrintRAM();

  osSim.DiskJobCompleted(0);
  osSim.PrintRAM();
  std::cout << "end" << std::endl;
  return 0;
}