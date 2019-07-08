// This #include statement was automatically added by the Particle IDE.
#include "FramI2C.h"

/*

	test
	====

	Example sketch for Hackscribble_Ferro Library.

	For information on how to install and use the library,
	read "Hackscribble_Ferro user guide.md".


	Created on 18 April 2014
	By Ray Benitez
	Last modified on 22 September 2014
	By Ray Benitez
	Change history in "README.md"

	This software is licensed by Ray Benitez under the MIT License.

	git@hackscribble.com | http://www.hackscribble.com | http://www.twitter.com/hackscribble

*/

// Modified for I2C by Robert Mawrey - see library for I2C address

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Prerequisites for Hackscribble_Ferro
//////////////////////////////////////////////////////////////////////////////////////////////////////





#define PART_NUMBER MB85RC256V
#define PART_NAME	"MB85RC256V"


void setup()
{

	Serial.begin(115200);
	delay(5000);
	Serial.println(F("\n\n\n\n\nFRAM TESTS"));
	Serial.println(F("========================\n"));

	// Hackscribble_Fram library uses standard Arduino SPI pin definitions:  MOSI, MISO, SCK.
	// Next statement creates an instance of Fram using the standard Arduino SS pin and
	// default FRAM part number, MB85RS128A.
	// Hackscribble_Fram myFram;

	// You specify a different FRAM part number like this ...
	FramI2C myFram(PART_NUMBER);



	// FRAM TESTS
	// TEST 1

	Serial.println(F("\nTest: check for correct response from FRAM"));
	Serial.print(F("Expected result: FRAM response OK; part number = "));
	Serial.println(PART_NAME);
	Serial.println(F("Result ..."));

	framResult res = myFram.begin();

	if ( res == framBadResponse)
	{
		Serial.println(F("FRAM response not OK"));
	}
	else
	{
		Serial.println(F("FRAM response OK"));
		Serial.println();

		framResult myResult = framUnknownError;
		unsigned int myBufferSize = myFram.getMaxBufferSize();
		unsigned long myBottom = myFram.getBottomAddress();
		unsigned long myTop = myFram.getTopAddress();


		// TEST 2

		byte framBuffer[myBufferSize];

		for (byte i = 0; i < myBufferSize; i++)
		{
			framBuffer[i] = 0;
		}

		Serial.println(F("\nTest: write zero-filled buffer to all available space in FRAM"));
		Serial.println(F("Expected result: incrementing start address for each write; all result codes = 0"));
		Serial.println(F("Result ..."));
		for (unsigned long i = myBottom; i < myTop; i += myBufferSize)
		{
			//Serial.print(i, HEX);
			//Serial.print(F(" "));

            char b[10];
            sprintf(b,"%06X ",i);
            Serial.print(b);
			Serial.print(myFram.write(i, myBufferSize, framBuffer));
			Serial.print(F("  "));
			if ((i %1024) == 0)
			{
				Serial.println();
			}
		}
		Serial.println();


		// TEST 3

		const byte nRead = 20;

		Serial.println(F("\nTest: read subset of data back from FRAM"));
		Serial.println(F("Expected result: result code = 0; each value = 0"));
		Serial.println(F("Result ..."));
		// Read nRead bytes from an arbitrary address in FRAM to buffer
		Serial.println(myFram.read(5150, nRead, framBuffer));

		for (byte i = 0; i < nRead; i++)
		{
			Serial.print(framBuffer[i]);
			Serial.print(F("  "));
		}
		Serial.println();


		// TEST 4

		for (byte i = 0; i < myBufferSize; i++)
		{
			framBuffer[i] = (42 + i);
		}

		Serial.println(F("\nTest: fill buffer with test data"));
		Serial.println(F("Expected result: incrementing data starting at 42"));
		Serial.println(F("Result ..."));

		for (byte i = 0; i < myBufferSize; i++)
		{
			Serial.print(framBuffer[i]);
			Serial.print(F("  "));
		}
		Serial.println();


		// TEST 5

		Serial.println(F("\nTest: write buffer to FRAM"));
		Serial.println(F("Expected result: result code = 0"));
		Serial.println(F("Result ..."));
		// Write 60 bytes from buffer to an arbitrary address in FRAM
		Serial.println(myFram.write(5100, 60, framBuffer));

 		for (byte i = 0; i < myBufferSize; i++)
		{
			framBuffer[i] = 0;
		}


		// TEST 6

		Serial.println(F("\nTest: read subset of data back from FRAM"));
		Serial.println(F("Expected result: result code = 0; twenty incrementing values starting at 72"));
		Serial.println(F("Result ..."));
		Serial.println(myFram.read(5130, nRead, framBuffer));

		for (byte i = 0; i < nRead; i++)
		{
			Serial.print(framBuffer[i]);
			Serial.print(F("  "));
		}
		Serial.println();


		// FRAM CONTROL BLOCK TESTS
		// TEST 7

		byte myControlBufferSize = myFram.getControlBlockSize();
		byte framControlBuffer[myControlBufferSize];

		for (byte i = 0; i < myControlBufferSize; i++)
		{
			framControlBuffer[i] = 123;
		}
		myFram.writeControlBlock(framControlBuffer);

		for (byte i = 0; i < myControlBufferSize; i++)
		{
			framControlBuffer[i] = 255;
		}
		myFram.readControlBlock(framControlBuffer);

		Serial.println(F("\nTest: read test data from control block"));
		Serial.println(F("Expected result: each value = 123"));
		Serial.println(F("Result ..."));
		for (byte i = 0; i < myControlBufferSize; i++)
		{
			Serial.print(framControlBuffer[i]);
			Serial.print(F("  "));
		}
		Serial.println();


		// TEST 8

		for (byte i = 0; i < myControlBufferSize; i++)
		{
			framControlBuffer[i] = 43;
		}
		myFram.writeControlBlock(framControlBuffer);

		for (byte i = 0; i < myControlBufferSize; i++)
		{
			framControlBuffer[i] = 255;
		}

		myFram.readControlBlock(framControlBuffer);
		Serial.println(F("\nTest: read test data from control block"));
		Serial.println(F("Expected result: each value = 43"));
		Serial.println(F("Result ..."));
		for (byte i = 0; i < myControlBufferSize; i++)
		{
			Serial.print(framControlBuffer[i]);
			Serial.print(F("  "));
		}
		Serial.println();


		// FRAM ARRAY TESTS
		// TEST 9

		struct testStruct
		{
			unsigned long frequency;
			unsigned int v1;
			unsigned int v2;
		};

		myResult = framUnknownError;
		unsigned long address1 = myFram.getControlBlockSize();

		Serial.println(F("\nTest: create a FramArray of struct"));
		Serial.print(F("Expected result: result code = 0; start address of array = "));
		Serial.println(address1);
		Serial.println(F("Result ..."));
		FramI2CArray myArray(myFram, 20, sizeof(testStruct), myResult);
		Serial.println(myResult);
		Serial.println(myArray.getStartAddress());
		unsigned long address2 = address1 + (20 * sizeof(testStruct));


		// TEST 10

		Serial.println(F("\nTest: create a FramArray of float"));
		Serial.print(F("Expected result: result code = 0; start address of array = "));
		Serial.println(address2);
		Serial.println(F("Result ..."));
		FramI2CArray anotherArray(myFram, 200, sizeof(float), myResult);
		Serial.println(myResult);
		Serial.println(anotherArray.getStartAddress());
		unsigned long address3 = address2 + (200 * sizeof(float));


		// TEST 11
		// Create this dummy array to check the size of the previous float array
		Serial.println(F("\nTest: create a FramArray of int"));
		Serial.print(F("Expected result: start address of array = "));
		Serial.println(address3);
		Serial.println(F("Result ..."));
		FramI2CArray dummyArray(myFram, 300, sizeof(int), myResult);
		Serial.println(dummyArray.getStartAddress());


		// TEST 12
		// Write arbitrary test data to struct array
		testStruct myStruct = {14123456, 1234, 4320};
		testStruct newStruct = {0, 0, 0};

		Serial.println(F("\nTest: write struct with test data to array"));
		Serial.println(F("Expected result: 14123456, 1234, 4320; result code = 0"));
		Serial.println(F("Result ..."));
		Serial.print(myStruct.frequency);
		Serial.print(F("\t"));
		Serial.print(myStruct.v1);
		Serial.print(F("\t"));
		Serial.println(myStruct.v2);
		myArray.writeElement(12, (byte*)&myStruct, myResult);
		Serial.println(myResult);


		// TEST 13

		Serial.println(F("\nTest: read test data from array into a new struct"));
		Serial.println(F("Expected result: result code = 0; 14123456, 1234, 4320"));
		Serial.println(F("Result ..."));
		myArray.readElement(12, (byte*)&newStruct, myResult);
		Serial.println(myResult);
		Serial.print(newStruct.frequency);
		Serial.print(F("\t"));
		Serial.print(newStruct.v1);
		Serial.print(F("\t"));
		Serial.println(newStruct.v2);


		// TEST 14
		// Write arbitrary test data to float array
		float myFloat = 3.14;
		float newFloat = 0.0;

		Serial.println(F("\nTest: write float with test data to array"));
		Serial.println(F("Expected result: 3.14; result code = 0"));
		Serial.println(F("Result ..."));
		Serial.println(myFloat);
		anotherArray.writeElement(12, (uint8_t*)&myFloat, myResult);
		Serial.println(myResult);


		// TEST 15
		Serial.println(F("\nTest: read test data from array into a new struct"));
		Serial.println(F("Expected result: result code = 0; 3.14"));
		Serial.println(F("Result ..."));
		anotherArray.readElement(12, (uint8_t*)&newFloat, myResult);
		Serial.println(myResult);
		Serial.println(newFloat);


		// TEST 16
		// Write arbitrary test data to int array
		int16_t myInt = -123;
		int16_t newInt = 0;

		Serial.println(F("\nTest: write int with test data to array"));
		Serial.println(F("Expected result: -123; result code = 0"));
		Serial.println(F("Result ..."));
		Serial.println(myInt);
		dummyArray.writeElement(212, (uint8_t*)&myInt, myResult);
		Serial.println(myResult);


		// TEST 17
		Serial.println(F("\nTest: read test data from array into a new int"));
		Serial.println(F("Expected result: result code = 0; -123"));
		Serial.println(F("Result ..."));
		dummyArray.readElement(212, (uint8_t*)&newInt, myResult);
		Serial.println(myResult);
		Serial.println(newInt);


		// FRAM FORMAT TESTS
		// TEST 18

		myResult = framUnknownError;

		Serial.println(F("\nTest: format the FRAM and read subset of data"));
		Serial.println(F("Expected result: result codes = 0 and 0; each value = 0"));
		Serial.println(F("Result ..."));
		Serial.println(myFram.format());
		Serial.println(myFram.read(5130, nRead, framBuffer));

		for (byte i = 0; i < nRead; i++)
		{
			Serial.print(framBuffer[i]);
			Serial.print(F("  "));
		}
		Serial.println();


		// TEST 19
		// Control block should not have been erased by format
		myFram.readControlBlock(framControlBuffer);
		Serial.println(F("\nTest: read test data from control block"));
		Serial.println(F("Expected result: each value = 43"));
		Serial.println(F("Result ..."));
		for (byte i = 0; i < myControlBufferSize; i++)
		{
			Serial.print(framControlBuffer[i]);
			Serial.print(F("  "));
		}
		Serial.println();


		Serial.println(F("\n\n\nEND OF TESTS"));
		Serial.println(F("============\n"));

	}

}


void loop()
{


}
