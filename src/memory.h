#ifndef MEMORY_H
#define MEMORY_H

#define MAX_MEMORY 1<<22;

class Memory
{
public:
	Memory();
	~Memory();
	int read(int address);
	void write(int value, int address);
	bool getAccessed(int zone);
	bool* getAccessedList();
private:
	char* memoryList;
	bool* memoryAccessed;
};
#endif // !MEMORY_H
