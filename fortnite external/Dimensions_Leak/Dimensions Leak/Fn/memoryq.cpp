#pragma once
#include "memoryq.h"
#include <lazyimporter.h>



Memory::Memory(int32_t pid, std::vector<std::string> moduleNames)
{
	LoadLibraryA("user32.dll");
	Setup();

	processId = pid;

	for (const auto& moduleName : moduleNames)
	{
		uint64_t baseAddress = NULL;
		if (GetModuleBaseAddressFromKernel(processId, moduleName.c_str(), &baseAddress))
			moduleBases[moduleName] = baseAddress;

	}

	GetProcessBaseAddressFromKernel(pid, &this->base);
}

bool Memory::Rpm(uint64_t address, void* buffer, size_t size)
{
	return ReadMemoryFromKernel(processId, address, buffer, size);
}

bool Memory::Wpm(uint64_t address, void* buffer, size_t size)
{
	return WriteMemoryFromKernel(processId, address, buffer, size);
}



BOOL Memory::Setup() {

	LoadLibraryA("user32.dll");
	LoadLibraryA("win32u.dll");
	LoadLibraryA("ntdll.dll");
	bool Isret = false;
	Isret = OpenDriver(L"\\\\.\\PEAuth");
	if (!Isret)
	{		
		return false;
	}
}


uint64_t Memory::Readp(int processId, uint64_t src, void* dest, uint32_t size)
{
	size_t read = NULL;
	Communication request = {};
	SecureZeroMemory(&request, sizeof(Communication));

	request.request = Request::OLDREAD;
	request.key = COMMUNICATION_KEY;
	request.address = src;
	request.output = dest;
	request.size = size;
	request.processID = processId;

	DWORD junk = 0;
	auto status = DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, &request, sizeof(Communication), &request, sizeof(Communication), &junk, (LPOVERLAPPED)NULL);
	if (!NT_SUCCESS(status)) {
		return false;
	}

	return  (uint64_t) status;
}
bool  Memory::ReadCustom(int processId, uintptr_t src, void* dest, size_t  size)
{
	size_t read = NULL;
	Communication request = {};
	SecureZeroMemory(&request, sizeof(Communication));
	
	request.request = Request::OLDREAD;
	request.key = COMMUNICATION_KEY;
	request.address = src;
	request.output = dest;
	request.size = size;
	request.processID = processId;

	DWORD junk = 0;
	auto status = DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, &request, sizeof(Communication), &request, sizeof(Communication), &junk, (LPOVERLAPPED)NULL);
	if (!NT_SUCCESS(status)) {
		return false;
	}
	return status;
}
bool Memory::GetProcessBaseAddressFromKernel(int processID, uint64_t* baseAddress)
{
	Communication request = {};
	SecureZeroMemory(&request, sizeof(Communication));
	request.request = Request::GETBASE;
	request.key = COMMUNICATION_KEY;
	request.processID = processID;
	request.buffer = 0;
DWORD junk = 0;
	auto status =DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, &request, sizeof(Communication), &request, sizeof(Communication), &junk, (LPOVERLAPPED)NULL);
	if (!NT_SUCCESS(status)) {
		return false;
	}
	
	*baseAddress = request.buffer;
	return (request.buffer != NULL);
}

bool Memory::GetModuleBaseAddressFromKernel(int processID, const char* moduleName, uint64_t* baseAddress)
{
	Communication request = {};
	SecureZeroMemory(&request, sizeof(Communication));
	request.request = Request::GETMODULEBASE;
	request.key = COMMUNICATION_KEY;
	request.processID = processID;
	request.moduleName = moduleName;
	request.buffer = 0;

	DWORD junk = 0;
	auto status = DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, &request, sizeof(Communication), &request, sizeof(Communication), &junk, (LPOVERLAPPED)NULL);
	if (!NT_SUCCESS(status)) {
		return false;
	}
	*baseAddress = request.buffer;
	return true;

	
	
}


bool Memory::ReadMemoryFromKernel(int processId, uint64_t address, void* buffer, size_t size)
{
	size_t read = NULL;
	Communication request = {};
	SecureZeroMemory(&request, sizeof(Communication));

	request.request = Request::READPROCESSMEMORY;
	request.key = COMMUNICATION_KEY;
	request.address = address;
	request.buffer = (uint64_t)buffer;
	request.size = size;
	request.processID = processId;
	request.read = read;


	DWORD junk = 0;
	auto status = DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, &request, sizeof(Communication), &request, sizeof(Communication), &junk, (LPOVERLAPPED)NULL);
	if (!NT_SUCCESS(status)) {
		return false;
	}
	
	return (buffer != NULL);
}

bool Memory::ReadMemoryFromKernel2(int processId, uint64_t address, void* buffer, size_t size)
{
	size_t read = NULL;
	Communication request = {};
	SecureZeroMemory(&request, sizeof(Communication));

	request.request = Request::READPROCESSMEMORY;
	request.key = COMMUNICATION_KEY;
	request.address = address;
	request.buffer = (uint64_t)buffer;
	request.size = size;
	request.processID = processId;
	request.read = read;
	
	DWORD junk = 0;
	auto status = DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, &request, sizeof(Communication), &request, sizeof(Communication), &junk, (LPOVERLAPPED)NULL);
	if (!NT_SUCCESS(status)) {
		return false;
	}
	
	return (buffer != NULL);
}

bool Memory::WriteMemoryFromKernel(int processId, uint64_t address, void* buffer, size_t size)
{
	size_t written = NULL;
	Communication request = {};
	SecureZeroMemory(&request, sizeof(Communication));

	request.request = Request::WRITEPROCESSMEMORY;
	request.key = COMMUNICATION_KEY;
	request.address = address;
	request.buffer = (uint64_t)buffer;
	request.size = size;
	request.processID = processId;
	request.read = written;

	DWORD junk = 0;
	auto status = DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, &request, sizeof(Communication), &request, sizeof(Communication), &junk, (LPOVERLAPPED)NULL);
	if (!NT_SUCCESS(status)) {
		return false;
	}

	return (buffer != NULL);
}

bool Memory::MoveMouse(int x, int y, unsigned short button_flags)
{
	size_t written = NULL;
	Communication request = {};
	SecureZeroMemory(&request, sizeof(Communication));

	request.request = Request::MOVEMOUSE;
	request.key = COMMUNICATION_KEY;
	request.x = x;
	request.y = y;
	request.button_flags = button_flags;


	DWORD junk = 0;
	auto status = DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, &request, sizeof(Communication), &request, sizeof(Communication), &junk, (LPOVERLAPPED)NULL);
	if (!NT_SUCCESS(status)) {
		return false;
	}

	return true;
}
bool Memory::OpenDriver(const wchar_t* DeviceName) {

	hDevice = iat(CreateFileW)(DeviceName, DWORD(0), FILE_SHARE_READ | FILE_SHARE_WRITE, LPSECURITY_ATTRIBUTES(nullptr), OPEN_EXISTING, DWORD(0), HANDLE(0));
	if (hDevice == INVALID_HANDLE_VALUE) {
		return false;
	}

	return true;
}