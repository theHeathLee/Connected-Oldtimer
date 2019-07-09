/*
	FerroI2C Library
	==========================

	Connects Fujitsu Ferroelectric RAM (MB85RS range) to your
	Arduino to add up to 256KB of fast, non-volatile storage.

	For information on how to install and use the library,
	read "FerroI2C user guide.md".


	Created on 18 April 2014
	By Ray Benitez
	Last modified on 29 September 2014
	By Ray Benitez
	Change history in "README.md"

	This software is licensed by Ray Benitez under the MIT License.

	git@hackscribble.com | http://www.hackscribble.com | http://www.twitter.com/hackscribble

	Modified to support Particle Photon and Ring_FramArray class added by Mawrey 5 May 2017
	Modified for I2C October 2018
*/

// #ifndef FERRO_I2C_H
// #define FERRO_I2C_H_H

#ifndef FramI2C_h
#define FramI2C_h

#include "application.h"


// MB85RC part numbers

enum framPartNumber
{
//	MB85RC16 = 0,		// 2KB
	MB85RC64 = 0,		// 8KB
	MB85RC128A,			// 16KB older model
	MB85RC128B,			// 16KB newer model
	MB85RC256A,			// 32KB older model
	MB85RC256B,			// 32KB newer model
	MB85RC256V,			// 32KB
	MB85RC512T,			// 64KB
//	MB85RC1MT,			// 128KB
	numberOfPartNumbers
};


// Result codes

enum framResult
{
	framOK = 0,
	framBadStartAddress,
	framBadNumberOfBytes,
	framBadFinishAddress,
	framArrayElementTooBig,
	framBadArrayIndex,
	framBadArrayStartAddress,
	framBadResponse,
	framPartNumberMismatch,
	framUnknownError = 99
};


class FramI2C
{
private:

	framPartNumber _partNumber;
//	byte framI2CAddress = 0x50; // Put this in globals as it is part of IoTNode jumpers
byte framI2CAddress = 0x50; // Put this in globals
	// Set maximum size of buffer used to write to and read from FRAM
	// Do not exceed 0x80 (128) to prevent problems with maximum size structs in FramArray
	static const byte _maxBufferSize = 0x80;

	// Used in constructor to set size of usable FRAM memory, reserving some bytes as a control block
	unsigned long _topAddressForPartNumber[numberOfPartNumbers];
//	framAddressLength _addressLengthForPartNumber[numberOfPartNumbers];
//	framAddressLength _addressLength;
//	byte _densityCode[numberOfPartNumbers];
	unsigned long _baseAddress;
	unsigned long _bottomAddress;
	unsigned long _topAddress;
	unsigned long _numberOfBuffers;

	// FRAM current next byte to allocate
	unsigned long _nextFreeByte;

//	void _readMemory(unsigned long address, uint8_t numberOfBytes, uint8_t *buffer);
//	void _writeMemory(unsigned long address, uint8_t numberOfBytes, uint8_t *buffer);

public:

	FramI2C(framPartNumber partNumber = MB85RC128A);
	framResult begin();
	framPartNumber getPartNumber();
	byte getMaxBufferSize();
	unsigned long getBottomAddress();
	unsigned long getTopAddress();
	byte getControlBlockSize();
	void writeControlBlock(byte *buffer);
	void readControlBlock(byte *buffer);
	framResult read(unsigned long startAddress, unsigned int numberOfBytes, byte *buffer);
	framResult write(unsigned long startAddress, unsigned int numberOfBytes, byte *buffer);
	unsigned long allocateMemory(unsigned long numberOfBytes, framResult& result);
	framResult format();

	void _readMemory(unsigned long address, uint8_t numberOfBytes, uint8_t *buffer);
	void _writeMemory(unsigned long address, unsigned int numberOfBytes, uint8_t *buffer);

};


class FramI2CArray
{
private:

	unsigned long _numberOfElements;
	byte _sizeOfElement;
	unsigned long _startAddress;
	FramI2C& _f;

public:

	FramI2CArray(FramI2C& f, unsigned long numberOfElements, byte sizeOfElement, framResult &result);
	void readElement(unsigned long index, byte *buffer, framResult &result);
	void writeElement(unsigned long index, byte *buffer, framResult &result);
	unsigned long getStartAddress();

};

// Ring buffer class added by Mawrey

class Ring_FramArray
{
private:


	unsigned long _numberOfElements;
	byte _sizeOfElement;
	unsigned long _startAddress;
	FramI2C& _f;
	unsigned long _tailAddress;
	unsigned long _headAddress;
	unsigned long getStartAddress();
	unsigned long myModulo(unsigned long a, unsigned long b);


public:

	Ring_FramArray(FramI2C& f, unsigned long numberOfElements, byte sizeOfElement, framResult &result);

	bool popFirstElement(byte *buffer);
	bool popLastElement(byte *buffer);
	void pushElement(byte *buffer);
	bool peekFirstElement(byte *buffer);
	bool peekLastElement(byte *buffer);
	void clearArray();
	bool isEmpty();
	bool isFull();

// Call this using xxxx.getIndices(unsigned long &startadd, unsigned long &endadd);
	void getIndices(unsigned long *startAdd, unsigned long *endAdd);
	bool setIndices(unsigned long startAddress, unsigned long endAddress);

};

#endif
