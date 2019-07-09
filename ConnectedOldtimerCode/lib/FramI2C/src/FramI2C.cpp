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
*/

// Modified for I2C and Particle by Robert Mawrey

#include "application.h"
#include "FramI2C.h"

FramI2C::FramI2C(framPartNumber partNumber): _partNumber(partNumber) // Add in I2C address later
{
//	_topAddressForPartNumber[MB85RC16]		= 0x0007FFUL;
	_topAddressForPartNumber[MB85RC64]		= 0x001FFFUL;
	_topAddressForPartNumber[MB85RC128A]	= 0x003FFFUL;
	_topAddressForPartNumber[MB85RC128B]	= 0x003FFFUL;
	_topAddressForPartNumber[MB85RC256A]	= 0x007FFFUL;
	_topAddressForPartNumber[MB85RC256B]	= 0x007FFFUL;
	_topAddressForPartNumber[MB85RC256V]	= 0x007FFFUL;
	_topAddressForPartNumber[MB85RC512T]	= 0x00FFFFUL;
//	_topAddressForPartNumber[MB85RC1MT]		= 0x01FFFFUL;

	_baseAddress = 0x000000;
	_bottomAddress = _baseAddress + _maxBufferSize;
	_topAddress = _topAddressForPartNumber[_partNumber];
//	_addressLength = _addressLengthForPartNumber[_partNumber];
	_numberOfBuffers = (_topAddress - _bottomAddress + 1) / _maxBufferSize;
	_nextFreeByte = _bottomAddress;
}


//
// PLATFORM SPECIFIC, LOW LEVEL METHODS
//

void FramI2C::_readMemory(unsigned long address, uint8_t numberOfBytes, uint8_t *buffer)
{
//	Serial.print('.');
	uint16_t framAddr = (uint16_t)address;
	// Address only correct for 64 through 512 kbit devices
	Wire.beginTransmission(framI2CAddress);

	Wire.write(framAddr >> 8);
	Wire.write(framAddr & 0xFF);

	Wire.endTransmission();

uint8_t *buf = buffer;

// Maximum request size of 32 bytes (30?)
	Wire.requestFrom(framI2CAddress, (uint8_t)numberOfBytes);
		for (byte i=0; i < numberOfBytes; i++) {
			 buffer[i] = Wire.read();
		}
	Wire.endTransmission();

// Serial.println();
// for (byte i=0; i < numberOfBytes; i++) {
// 	Serial.print(buffer[i]);
// 	Serial.print(',');
// }
// 	Serial.println();
}


void FramI2C::_writeMemory(unsigned long address, unsigned int numberOfBytes, uint8_t *buffer)
{
//Serial.print('+');
	uint16_t framAddr = (uint16_t)address;
	// Address only correct for 64 through 512 kbit devices
//Serial.println(framI2CAddress);
	Wire.beginTransmission(framI2CAddress);
	Wire.write(framAddr >> 8);
	Wire.write(framAddr & 0xFF);
// Wire.write(framAddr);
	//Wire.endTransmission();

	//Wire.requestFrom(framI2CAddress, (uint8_t)numberOfBytes);
	for (unsigned int i=0; i < numberOfBytes; i++) {
		Wire.write(buffer[i]);
	}
Wire.endTransmission();
/*	for (byte i=0; i < numberOfBytes; i++) {
	Serial.print(buffer[i]);
}*/
}



//
// PLATFORM INDEPENDENT, HIGH LEVEL METHODS
//

framResult FramI2C::begin()
{
  // Initialize the I2C bus if not already enabled
  if (!Wire.isEnabled()) {
      Wire.begin();
  }
  Wire.beginTransmission(framI2CAddress);
  byte response = Wire.endTransmission();
// Serial.println(response);
  if (response == 0)
  {
	  return framOK;
  }
  else
  {
	  return framBadResponse;
  }
}


framPartNumber FramI2C::getPartNumber()
{
	return _partNumber;
}


byte FramI2C::getMaxBufferSize()
{
	return _maxBufferSize;
}


unsigned long FramI2C::getBottomAddress()
{
	return _bottomAddress;
}


unsigned long FramI2C::getTopAddress()
{
	return _topAddress;
}


byte FramI2C::getControlBlockSize()
{
	return _maxBufferSize;
}


void FramI2C::writeControlBlock(uint8_t *buffer)
{
	// _writeMemory(_baseAddress, _maxBufferSize, buffer);
  write((unsigned long) _baseAddress, (unsigned int) _maxBufferSize, buffer);
}


void FramI2C::readControlBlock(uint8_t *buffer)
{
	// _readMemory(_baseAddress, _maxBufferSize, buffer);
  read((unsigned long) _baseAddress, (unsigned int) _maxBufferSize, buffer);
}


framResult FramI2C::read(unsigned long startAddress, unsigned int numberOfBytes, byte *buffer)
{
	// Copies numberOfBytes bytes from FRAM (starting at startAddress) into buffer (starting at 0)
	// Returns result code

	// Validations:
	//		_bottomAddress <= startAddress <= _topAddress
	//		0 < numberOfBytes <= maxBuffer
	//		startAddress + numberOfBytes <= _topAddress

	if ((startAddress < _bottomAddress) || (startAddress > _topAddress))
	{
		return framBadStartAddress;
	}
	if ((numberOfBytes > _maxBufferSize) || (numberOfBytes == 0))
	{
		return framBadNumberOfBytes;
	}
	if ((startAddress + numberOfBytes - 1) > _topAddress)
	{
		return framBadFinishAddress;
	}
// Read in 32 byte blocks due to wire requestFrom() limit
  const uint8_t blockSize = 32;
  byte* buf = buffer;
  unsigned long address = startAddress;

  while (numberOfBytes >= blockSize)
  {
		_readMemory(address, blockSize, buf);
	  address += blockSize;
		buf += blockSize;
	  numberOfBytes -= blockSize;
  }
  if (numberOfBytes > 0)
  {
    _readMemory(address, numberOfBytes, buf);
  }
	return framOK;
}


framResult FramI2C::write(unsigned long startAddress, unsigned int numberOfBytes, byte *buffer)
{
	// Copies numberOfBytes bytes from buffer (starting at 0) into FRAM (starting at startAddress)
	// Returns result code

	// Validations:
	//		_bottomAddress <= startAddress <= _topAddress
	//		0 < numberOfBytes <= maxBuffer
	//		startAddress + numberOfBytes - 1 <= _topAddress

	if ((startAddress < _bottomAddress) || (startAddress > _topAddress))
	{
		return framBadStartAddress;
	}
	if ((numberOfBytes > _maxBufferSize) || (numberOfBytes == 0))
	{
		return framBadNumberOfBytes;
	}
	if ((startAddress + numberOfBytes - 1) > _topAddress)
	{
		return framBadFinishAddress;
	}

	// _writeMemory(startAddress, numberOfBytes, buffer);

	// Write in 32 byte blocks due to wire limit
	  const uint8_t blockSize = 32;
	  byte* buf = buffer;
	  unsigned long address = startAddress;

	  while (numberOfBytes >= blockSize)
	  {
			_writeMemory(address, blockSize, buf);
		  address += blockSize;
			buf += blockSize;
		  numberOfBytes -= blockSize;
	  }
	  if (numberOfBytes > 0)
	  {
	    _writeMemory(address, numberOfBytes, buf);
	  }

	return framOK;
}


unsigned long FramI2C::allocateMemory(unsigned long numberOfBytes, framResult& result)
{
	if ((_nextFreeByte + numberOfBytes) < _topAddress)
	{
		uint16_t base = _nextFreeByte;
		_nextFreeByte += numberOfBytes;
		result = framOK;
		return base;
	}
	else
	{
		result = framBadFinishAddress;
		return 0;
	}
}


framResult FramI2C::format()
{
	// Fills FRAM with 0 but does NOT overwrite control block
	// Returns result code from framWrite function, or framOK if format is successful

	byte buffer[_maxBufferSize];

	for (byte i = 0; i < _maxBufferSize; i++)
	{
		buffer[i] = 0;
	}

	framResult result = framOK;
	unsigned long i = _bottomAddress;
	while ((i < _topAddress) && (result == framOK))
	{
		result = write(i, _maxBufferSize, buffer);
		i += _maxBufferSize;
	}
	return result;
}


FramI2CArray::FramI2CArray(FramI2C& f, unsigned long numberOfElements, byte sizeOfElement, framResult &result): _f(f), _numberOfElements(numberOfElements), _sizeOfElement(sizeOfElement)
{
	// Creates array in FRAM
	// Calculates and allocates required memory
	// Returns result code

	// Validations:
	//		_sizeOfElement <= _bufferSize

	if (_sizeOfElement < _f.getMaxBufferSize())
	{
		_startAddress = _f.allocateMemory(_numberOfElements * _sizeOfElement, result);
	}
	else
	{
		result = framArrayElementTooBig;
		_startAddress = 0;
	}

}


void FramI2CArray::readElement(unsigned long index, byte *buffer, framResult &result)
{
	// Reads element from array in FRAM
	// Returns result code

	// Validations:
	//		_startAddress > 0 (otherwise array has probably not been created)
	//		index < _numberOfElements

	if (_startAddress == 0)
	{
		result = framBadArrayStartAddress;
	}
	else if (index >= _numberOfElements)
	{
		result = framBadArrayIndex;
	}
	else
	{
		result = _f.read(_startAddress + (index * _sizeOfElement), _sizeOfElement, buffer);
	}
}


void FramI2CArray::writeElement(unsigned long index, byte *buffer, framResult &result)
{
	// Writes element to array in FRAM
	// Returns result code

	// Validations:
	//		_startAddress > 0 (otherwise array has probably not been created)
	//		index < _numberOfElements

	if (_startAddress == 0)
	{
		result = framBadArrayStartAddress;
	}
	else if (index >= _numberOfElements)
	{
		result = framBadArrayIndex;
	}
	else
	{
		result = _f.write(_startAddress + (index * _sizeOfElement), _sizeOfElement, buffer);
	}
}


unsigned long FramI2CArray::getStartAddress()
{
	return _startAddress;
}

// Ring_FramArray added by Mawrey

// Function to wrap around (find the mod of) for the circular buffer
unsigned long Ring_FramArray::myModulo(unsigned long a, unsigned long b)
{
	int x;
	x = (int)a % (int)b;
	if (x>=0)
	{
		return (unsigned long)x;
	}
	else
	{
		return (unsigned long)(x+b);
	}
}

Ring_FramArray::Ring_FramArray(FramI2C& f, unsigned long numberOfElements, byte sizeOfElement, framResult &result): _f(f), _numberOfElements(numberOfElements), _sizeOfElement(sizeOfElement)
{
	if (_sizeOfElement < _f.getMaxBufferSize())
	{
		_startAddress = _f.allocateMemory(_numberOfElements * _sizeOfElement, result);
		_tailAddress = 0;
		_headAddress = 0;
	}
	else
	{
		result = framArrayElementTooBig;
		_startAddress = 0;
		_tailAddress = 0;
		_headAddress = 0;
	}

}

unsigned long Ring_FramArray::getStartAddress()
{
	return _startAddress;
}

bool Ring_FramArray::popFirstElement(byte *buffer)
{
	if (!isEmpty())
	{
//		_tailAddress = myModulo(_tailAddress,_numberOfElements);
		_f.read(_startAddress + (_tailAddress * _sizeOfElement), _sizeOfElement, buffer);
		_tailAddress++;
		_tailAddress = myModulo(_tailAddress,_numberOfElements);
		return true;
	}
	else
	{
		return false;
	}
}


bool Ring_FramArray::popLastElement(byte *buffer)
{
	if (!isEmpty())
	{
//		_tailAddress = myModulo(_tailAddress,_numberOfElements);
		_f.read(_startAddress + (myModulo(_headAddress-1,_numberOfElements) * _sizeOfElement), _sizeOfElement, buffer);
		_headAddress--;
		_headAddress = myModulo(_headAddress,_numberOfElements);
		return true;
	}
	else
	{
		return false;
	}
}

// Write new element to ring and overwrite if full
void Ring_FramArray::pushElement(byte *buffer)
{
	if (!isFull())
	{
//Serial.println("Not full "+String(_tailAddress)+":"+String(_headAddress));
		_f.write(_startAddress + (_headAddress * _sizeOfElement), _sizeOfElement, buffer);
		_headAddress++;
		_headAddress = myModulo(_headAddress,_numberOfElements);
	}
	else
	{
//Serial.println("Full "+String(_tailAddress)+":"+String(_headAddress));
		_f.write(_startAddress + (_headAddress * _sizeOfElement), _sizeOfElement, buffer);
		_headAddress++;
		_tailAddress++;
		_tailAddress = myModulo(_tailAddress,_numberOfElements);
		_headAddress = myModulo(_headAddress,_numberOfElements);
	}

}


bool Ring_FramArray::peekFirstElement(byte *buffer)
{
	if (!isEmpty())
	{
//		_tailAddress = myModulo(_tailAddress,_numberOfElements);
		_f.read(_startAddress + (_tailAddress * _sizeOfElement), _sizeOfElement, buffer);
		//_tailAddress++;
		//_tailAddress = myModulo(_tailAddress,_numberOfElements);
		return true;
	}
	else
	{
		return false;
	}
}

bool Ring_FramArray::peekLastElement(byte *buffer)
{
	if (!isEmpty())
	{

		_f.read(_startAddress + (myModulo(_headAddress-1,_numberOfElements) * _sizeOfElement), _sizeOfElement, buffer);

		return true;
	}
	else
	{
		return false;
	}
}

void Ring_FramArray::clearArray()
{
	// Fills the array with 0

	byte buffer[_sizeOfElement];

	for (byte i = 0; i < _sizeOfElement; i++)
	{
		buffer[i] = 0;
	}

Serial.println();
	framResult result;
	unsigned long i = 0;
	while (i < _numberOfElements)
	{
		result = _f.write(_startAddress + (i * _sizeOfElement), _sizeOfElement, (uint8_t*)&buffer);
		i++;
	}
Serial.println();

}

bool Ring_FramArray::isEmpty()
{
//Serial1.println(String(_tailAddress)+":"+String(_headAddress)+" ");
	if (_tailAddress == _headAddress)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Ring_FramArray::isFull()
{
	unsigned long inc = myModulo(_headAddress+1,_numberOfElements);
	if (inc == _tailAddress)
	{
		return true;
	}
	else
	{
		return false;
	}
}

;
void Ring_FramArray::getIndices(unsigned long *startAdd, unsigned long *endAdd)
{
	*startAdd = _tailAddress;
	*endAdd = _headAddress;
}

bool Ring_FramArray::setIndices(unsigned long startAddress, unsigned long endAddress)
{
	if (((startAddress>=0)&&(startAddress<_numberOfElements)) && ((endAddress>=0)&&(endAddress<_numberOfElements)))
	{
		_tailAddress = startAddress;
		_headAddress = endAddress;
		return true;
	}
	else
	{
		return false;
	}
}
