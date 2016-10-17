/*
 Name:		cod_sera_test_edit.ino
 Created:	17-Oct-16 3:33:34 PM
 Author:	angry
*/

#include <Arduino.h>



const int ENA = 7;
const int IN1 = 6;
const int IN2 = 5;
const int ENB = 8;
const int IN4 = 9;
const int IN3 = 10;
const int ledPin = 13;

void setup()
{
	pinMode(ENA, OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(ENB, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);

	//delay is used to control the speed, the lower the faster.
	//reverse(step,delay);
	//  reverse(80,20);
	//forward(step,delay);
	//  forward(80,20);
}

void loop()
{
}

bool writeNibble(byte b1, byte b2, byte b3, byte b4)
{
	if ((0 <= b1 <= 1) &&
		(0 <= b1 <= 1) &&
		(0 <= b1 <= 1) &&
		(0 <= b1 <= 1))
	{
		digitalWrite(IN1, b1);
		digitalWrite(IN2, b2);
		digitalWrite(IN3, b3);
		digitalWrite(IN4, b4);
		return true;
	}
	return false;
}

void reverse(int i, int j) {

	// set both motors ON
	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);

	while (1) {
		writeNibble(0, 1, 0, 1);
		delay(j);
		i--;
		if (i < 1) break;

		writeNibble(0, 1, 1, 0);
		delay(j);
		i--;
		if (i < 1) break;
		
		writeNibble(1, 0, 1, 0);
		delay(j);
		i--;
		if (i < 1) break;

		writeNibble(1, 0, 0, 1);
		delay(j);
		i--;
		if (i < 1) break;
	}

	// set both motors OFF
	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);

}  // end reverse()

void forward(int i, int j) {

	// Set both motors ON
	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);

	while (1) {
		digitalWrite(IN1, 0);
		digitalWrite(IN2, 1);
		digitalWrite(IN3, 0);
		digitalWrite(IN4, 1);
		delay(j);
		i--;
		if (i < 1) break;

		digitalWrite(IN1, 1);
		digitalWrite(IN2, 0);
		digitalWrite(IN3, 0);
		digitalWrite(IN4, 1);
		delay(j);
		i--;
		if (i < 1) break;

		digitalWrite(IN1, 1);
		digitalWrite(IN2, 0);
		digitalWrite(IN3, 1);
		digitalWrite(IN4, 0);
		delay(j);
		i--;
		if (i < 1) break;

		digitalWrite(IN1, 0);
		digitalWrite(IN2, 1);
		digitalWrite(IN3, 1);
		digitalWrite(IN4, 0);
		delay(j);
		i--;
		if (i < 1) break;
	}

	// set both motors OFF
	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);

}  // end forward()