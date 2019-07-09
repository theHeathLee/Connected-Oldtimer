
#include "Particle.h"
#include "MB85RC256V-FRAM-RK.h"


MB85RC256V::MB85RC256V(TwoWire &wire, int addr) :
	wire(wire), addr(addr) {
}

MB85RC256V::~MB85RC256V() {
}

void MB85RC256V::begin() {
	wire.begin();
}

bool MB85RC256V::erase() {

	size_t framAddr = 0;
	size_t totalLen = MEMORY_SIZE;

	uint8_t zero[32];
	memset(zero, 0, sizeof(zero));

	while(totalLen > 0) {
		bool result = writeData(framAddr, zero, sizeof(zero));
		if (!result) {
			return false;
		}

		totalLen -= sizeof(zero);
		framAddr += sizeof(zero);
	}
	return true;
}


bool MB85RC256V::readData(size_t framAddr, uint8_t *data, size_t dataLen) {
	bool result = true;

	while(dataLen > 0) {
		wire.beginTransmission(addr | DEVICE_ADDR);
		wire.write(framAddr >> 8);
		wire.write(framAddr);
		int stat = wire.endTransmission(false);
		if (stat != 0) {
			//Serial.printlnf("read set address failed %d", stat);
			result = false;
			break;
		}

		size_t bytesToRead = dataLen;
		if (bytesToRead > 32) {
			bytesToRead = 32;
		}

		wire.requestFrom(addr | DEVICE_ADDR, bytesToRead, true);

		if (Wire.available() < (int) bytesToRead) {
			result = false;
			break;
		}

		for(size_t ii = 0; ii < bytesToRead; ii++) {
		    *data++ = Wire.read();    // receive a byte as character
		    framAddr++;
		    dataLen--;
		}
	}
	return result;
}


bool MB85RC256V::writeData(size_t framAddr, const uint8_t *data, size_t dataLen) {
	bool result = true;

	while(dataLen > 0) {
		wire.beginTransmission(addr | DEVICE_ADDR);
		wire.write(framAddr >> 8);
		wire.write(framAddr);

		for(size_t ii = 0; ii < 30 && dataLen > 0; ii++) {
			wire.write(*data);
			framAddr++;
			data++;
			dataLen--;
		}

		int stat = wire.endTransmission(true);
		if (stat != 0) {
			//Serial.printlnf("write failed %d", stat);
			result = false;
			break;
		}
	}
	return result;
}
