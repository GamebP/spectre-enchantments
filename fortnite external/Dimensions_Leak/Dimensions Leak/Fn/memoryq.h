#pragma once
#include <windows.h>
#include <iostream>
#include <winternl.h>
#include <vector>
#include <map>
#include <string>
class Memory
{
public:
	Memory(int32_t pid, std::vector<std::string> ModuleNames = {});
	HANDLE hDevice = INVALID_HANDLE_VALUE;
	template<typename T>
	T Rpm(uint64_t address);
	bool Rpm(uint64_t address, void* buffer, size_t size);
	bool ReadMemoryFromKernel2(int processId, uint64_t address, void* buffer, size_t size);
	
	template<typename T>
	void Wpm(uint64_t address, T value);
	bool Wpm(uint64_t address, void* buffer, size_t size);
	bool MoveMouse(int x, int y, unsigned short button_flags);
	uint64_t Readp(int processId, uint64_t src, void* dest, uint32_t size);
	bool  ReadCustom(int processId, uintptr_t src, void* dest, size_t  size);
	bool OpenDriver(const wchar_t* DeviceName);
	std::map<std::string, uint64_t> moduleBases;

	uint64_t base = 0;
private:
	/*
	* Communication
	*/
#define COMMUNICATION_KEY 0x2212
	int32_t processId = 0;

	enum Request {
		GETBASE = 0,
		GETMODULEBASE = 1,
		READPROCESSMEMORY = 2,
		WRITEPROCESSMEMORY = 3,
		SIGSCAN = 4,
		MOVEMOUSE = 5,
		OLDREAD = 6
	};
	struct Communication {

		uint64_t key;
		Request request;

		int processID;

		uint64_t address;
		const char* moduleName;

		uint64_t buffer;
		size_t size;

		void* output;

		int x;
		int y;
		unsigned short button_flags;

		union
		{
			size_t written;
			size_t read;
		};
	};


	BOOL Setup();
	bool GetProcessBaseAddressFromKernel(int processID, uint64_t* baseAddress);
	bool GetModuleBaseAddressFromKernel(int processID, const char* moduleName, uint64_t* baseAddress);
	bool ReadMemoryFromKernel(int processId, uint64_t address, void* buffer, size_t size);
	bool WriteMemoryFromKernel(int processId, uint64_t address, void* buffer, size_t size);
}; extern Memory* pMem;

template<typename T>
inline T Memory::Rpm(uint64_t address)
{
	T buffer;
	Rpm(address, &buffer, sizeof(T));
	return buffer;
}

template<typename T>
inline void Memory::Wpm(uint64_t address, T value)
{
	Wpm(address, &value, sizeof(T));
}
