#include "Particle.h"
#include "MB85RC256V-FRAM-RK.h"

MB85RC256V fram(Wire, 0);

void runTest();

const unsigned long TEST_PERIOD_MS = 5000;
unsigned long lastTest = 0;

void setup() {
	Serial.begin(9600);

	fram.begin();
	// fram.erase();
}

void loop() {
	if (millis() - lastTest >= TEST_PERIOD_MS) {
		lastTest = millis();
		runTest();
	}
}
// This is just a list of 16 fish names from Wikipedia for testing
const char *fishNames[] = {"Aeneus corydoras", "African glass catfish", "African lungfish", "Aholehole",
		"Airbreathing catfish", "Airsac catfish", "Alaska blackfish", "Albacore",
		"Alewife", "Alfonsino", "Algae eater", "Alligatorfish",
		"Alligator gar", "American sole", "Amur pike", "Anchovy"};

typedef struct {
	int a;
	float b;
	bool c;
} SimpleStruct;


void runTest() {
	// Low-level
	uint32_t d1;
	fram.readData(0, (uint8_t *)&d1, sizeof(d1));
	Serial.printlnf("d1=%u", d1);

	d1++;
	fram.writeData(0, (const uint8_t *)&d1, sizeof(d1));

	// EEPROM-style API
	// Note that you can substitute EEPROM for the fram in the get and put calls and this code will
	// work identically with the EEPROM emulation on the Photon/Electron.
	int addr = 4;
	int intVal;

	// int
	{
		// You can get and put simple values like int, long, bool, etc. using get and put directly

		fram.get(addr, intVal);
		Serial.printlnf("addr=%d, intVal=%d, sizeof(int)=%d", addr, intVal, sizeof(int));

		intVal++;
		fram.put(addr, intVal);

		addr += sizeof(int);
	}
	// double
	{
		double doubleVal;

		// Same for float, double
		fram.get(addr, doubleVal);
		Serial.printlnf("addr=%d, doubleVal=%lf, sizeof(doubleVal)=%d", addr, doubleVal, sizeof(doubleVal));

		doubleVal += 0.1;
		fram.put(addr, doubleVal);

		addr += sizeof(doubleVal);
	}

	// Strings are a bit more of a pain because you have to know how much space you want to reserve.
	// In this example, we store a string of up to 15 characters, plus a null byte, in a 16 character buffer
	{
		const int STRING_BUF_SIZE = 16;
		char stringBuf[STRING_BUF_SIZE];

		fram.get(addr, stringBuf);
		stringBuf[sizeof(stringBuf) - 1] = 0; // make sure it's null terminated

		// Initialize a String object from the buffer
		String str(stringBuf);

		Serial.printlnf("addr=%d, str=%s, sizeof(stringBuf)=%d", addr, str.c_str(), sizeof(stringBuf));

		str = String(fishNames[intVal & 0xf]);
		Serial.printlnf("next fish name=%s", str.c_str());

		// getBytes handles truncating the string if it's longer than the buffer.
		str.getBytes((unsigned char *)stringBuf, sizeof(stringBuf));
		fram.put(addr, stringBuf);

		addr += sizeof(stringBuf);
	}

	// A simple structure
	{
		SimpleStruct data;

		// You can even store a small structure of values
		fram.get(addr, data);
		Serial.printlnf("addr=%d, a=%d b=%f c=%d, sizeof(data)=%d", addr, data.a, data.b, data.c, sizeof(data));

		data.a += 2;
		data.b += 0.02;
		data.c = !data.c;

		fram.put(addr, data);

		addr += sizeof(data);
	}
	Serial.println("--------");
}
