int SW1_U = 9;
int SW1_D = 8;
int SW2_U = 10;
int SW2_D = 11;
int SW3_U = 7;
int SW3_D = 6;

int MOSFET1 = 2;
int MOSFET2 = 3;
int MOSFET3 = 4;
int MOSFET4 = 5;

int BTN = 13;

void setup() {
	Serial.begin(9600);
	pinMode(SW1_U, INPUT);
	pinMode(SW1_D, INPUT);
	pinMode(SW2_U, INPUT);
	pinMode(SW2_D, INPUT);
	pinMode(SW3_U, INPUT);
	pinMode(SW3_D, INPUT);

	pinMode(BTN, INPUT);

	pinMode(MOSFET1, OUTPUT);
	pinMode(MOSFET2, OUTPUT);
//  pinMode(MOSFET3, OUTPUT);
//  pinMode(MOSFET4, OUTPUT);

	digitalWrite(MOSFET1, LOW);
	digitalWrite(MOSFET2, LOW);
//  digitalWrite(MOSFET3, LOW);
//  digitalWrite(MOSFET4, LOW);
}

int SW1_U_V = 5;
int SW1_D_V = 5;
int SW2_U_V = 5;
int SW2_D_V = 5;
int SW3_U_V = 5;
int SW3_D_V = 5;

void loop() {
	int btnRead = digitalRead(BTN);

	if(btnRead == HIGH)
	{
		readSwitches();
		Serial.println("Sequence complete. Standy by");
		delay(3000);
		Serial.println("Ready");
	}
}

void readSwitches()
{
	int x = digitalRead(SW1_U);
 
	if(5 == SW1_U_V || SW1_U_V != x)
	{
		SW1_U_V = x;
		Serial.print("SW1_U = ");
		Serial.println(x);
	}
//  else
//  {
//		Serial.println("SW1_U Val");
//		Serial.println(x);
//  }

	x = digitalRead(SW1_D);

	if(5 == SW1_D_V || SW1_D_V != x)
	{
		SW1_D_V = x;
		Serial.print("SW1_D = ");
		Serial.println(x);
	}

	x = digitalRead(SW2_U);

	if(5 == SW2_U_V || SW2_U_V != x)
	{
		SW2_U_V = x;
		Serial.print("SW2_U = ");
		Serial.println(x);
	}

	x = digitalRead(SW2_D);

	if(5 == SW2_D_V || SW2_D_V != x)
	{
		SW2_D_V = x;
		Serial.print("SW2_D = ");
		Serial.println(x);
	}

	x = digitalRead(SW3_U);

	if(5 == SW3_U_V || SW3_U_V != x)
	{
		SW3_U_V = x;
		Serial.print("SW3_U = ");
		Serial.println(x);
	}

	x = digitalRead(SW3_D);

	if(5 == SW3_D_V || SW3_D_V != x)
	{
		SW3_D_V = x;
		Serial.print("SW3_D = ");
		Serial.println(x);
	}
	
	int sw3V = SW3_U_V == 1 ? 1 : SW3_D_V == 1 ? 3 : 2;
	int sw2V = SW2_U_V == 1 ? 1 : SW2_D_V == 1 ? 3 : 2;
	int sw1V = SW1_U_V == 1 ? 1 : SW1_D_V == 1 ? 3 : 2;

	Serial.print("sw1V = "); Serial.println(sw1V);
	Serial.print("sw2V = "); Serial.println(sw2V);
	Serial.print("sw3V = "); Serial.println(sw3V);
	
	
	if(sw3V == 1 && sw2V == 1 && sw1V == 1)
	{
		sequenceOne();
	}
	
	
	if(sw3V == 1 && sw2V == 1 && sw1V == 2)
	{
		sequenceTwo();
	}
	
	
	if(sw3V == 1 && sw2V == 1 && sw1V == 3)
	{
		sequenceThree();
	}
	
	
	if(sw3V == 1 && sw2V == 2 && sw1V == 1)
	{
		sequenceFour();
	}
	
	
	if(sw3V == 1 && sw2V == 2 && sw1V == 2)
	{
		sequenceFive();
	}
	
	
	if(sw3V == 1 && sw2V == 2 && sw1V == 3)
	{
		sequenceSix();
	}
	
	
	if(sw3V == 1 && sw2V == 3 && sw1V == 1)
	{
		sequenceSeven();
	}
	
	
	if(sw3V == 1 && sw2V == 3 && sw1V == 2)
	{
		sequenceEight();
	}
	
	
	if(sw3V == 1 && sw2V == 3 && sw1V == 3)
	{
		sequenceNine();
	}
	
	
	if(sw3V == 2 && sw2V == 1 && sw1V == 1)
	{
		sequenceTen();
	}
	
	
	if(sw3V == 2 && sw2V == 1 && sw1V == 2)
	{
		sequenceEleven();
	}
	
	
	if(sw3V == 2 && sw2V == 1 && sw1V == 3)
	{
		sequenceTwelve();
	}
	
	
	if(sw3V == 2 && sw2V == 2 && sw1V == 1)
	{
		sequenceThirteen();
	}
	
	
	if(sw3V == 2 && sw2V == 2 && sw1V == 2)
	{
		sequenceFourteen();
	}
	
	
	if(sw3V == 2 && sw2V == 2 && sw1V == 3)
	{
		sequenceFifteen();
	}
	
	
	if(sw3V == 2 && sw2V == 3 && sw1V == 1)
	{
		sequenceSixteen();
	}
	
	
	if(sw3V == 2 && sw2V == 3 && sw1V == 2)
	{
		sequenceSeventeen();
	}
	
	
	if(sw3V == 2 && sw2V == 3 && sw1V == 3)
	{
		sequenceEighteen();
	}
	
	
	if(sw3V == 3 && sw2V == 1 && sw1V == 1)
	{
		sequenceNineteen();
	}
	
	
	if(sw3V == 3 && sw2V == 1 && sw1V == 2)
	{
		sequenceTwenty();
	}
	
	
	if(sw3V == 3 && sw2V == 1 && sw1V == 3)
	{
		sequenceTwentyOne();
	}
	
	
	if(sw3V == 3 && sw2V == 2 && sw1V == 1)
	{
		sequenceTwentyTwo();
	}
	
	
	if(sw3V == 3 && sw2V == 2 && sw1V == 2)
	{
		sequenceTwentyThree();
	}
	
	
	if(sw3V == 3 && sw2V == 2 && sw1V == 3)
	{
		sequenceTwentyFour();
	}
	
	
	if(sw3V == 3 && sw2V == 3 && sw1V == 1)
	{
		sequenceTwentyFive();
	}
	
	
	if(sw3V == 3 && sw2V == 3 && sw1V == 2)
	{
		sequenceTwentySix();
	}
	
	
	if(sw3V == 3 && sw2V == 3 && sw1V == 3)
	{
		sequenceTwentySeven();
	}

}

void left(int del)
{
	left(del, 100);
}

void left(int del, int secDel)
{
	
	digitalWrite(MOSFET1, HIGH);
	delay(del);
	digitalWrite(MOSFET1, LOW);
	delay(secDel);
}

void right(int del)
{
	right(del, 100);
}

void right(int del, int secDel)
{
	digitalWrite(MOSFET2, HIGH);
	delay(del);
	digitalWrite(MOSFET2, LOW);
	delay(secDel);
}

void both(int del)
{
	both(del, 100);
}

void both(int del, int secDel)
{
	digitalWrite(MOSFET1, HIGH);
	digitalWrite(MOSFET2, HIGH);
	delay(del);
	digitalWrite(MOSFET1, LOW);
	digitalWrite(MOSFET2, LOW);
	delay(secDel);
}



void sequenceOne()
{
	for(int i = 0; i < 5; i++)
	{
		both(1000, 200);
		both(500, 150);
		both(250, 100);
		both(150, 50);
		both(100, 25);
		both(15, 15);
		both(15, 15);
	}
}

void sequenceTwo()
{
	for(int i = 0; i < 5; i++)
	{
		left(125);
		right(125);
	}
}

void sequenceThree()
{
	for(int i = 0; i < 10; i++)
	{
		both(500);
		both(500);
	}
}

void sequenceFour()
{
	for(int i = 0; i < 10; i++)
	{
		both(125);
		both(125);
	}
}

void sequenceFive()
{
	for(int i = 0; i < 4; i++)
	{
		left(500);
		left(500);
		right(500);
		right(500);
	}
	
}

void sequenceSix()
{
	for(int i = 0; i < 10; i++)
	{
		left(500);
		left(500);
		right(500);
	}
}

void sequenceSeven()
{
	for(int i = 0; i < 10; i++)
	{
		left(500);
		right(500);
		right(500);
	}
}

void sequenceEight()
{
	for(int i = 0; i < 10; i++)
	{
		left(500);
		right(500);
		both(500);
	}
}

void sequenceNine()
{
	for(int i = 0; i < 10; i++)
	{
		both(500);
		left(500);
		both(500);
		right(500);
	}
}

void sequenceTen()
{
	for(int i = 0; i < 10; i++)
	{
		both(500);
		left(500);
		right(500);
	}
}

void sequenceEleven()
{
	left(2000);
}

void sequenceTwelve()
{
	right(2000);
}

void sequenceThirteen()
{
	for(int i = 0; i < 5; i++)
	{
		left(500);
		left(500);
		right(500);
		right(500);
	}
}

void sequenceFourteen()
{
	for(int i = 0; i < 5; i++)
	{
		left(500);
		left(25);
		left(25);
		right(500);
		right(25);
		right(25);
	}
}

void sequenceFifteen()
{
	for(int i = 0; i < 4; i++)
	{
		left(1000);
		right(1000);
	}
}

void sequenceSixteen()
{
	for(int i = 0; i < 10; i++)
	{
		left(500);
		left(500);
		right(500);
	}
}

void sequenceSeventeen()
{
	for(int i = 0; i < 10; i++)
	{
		both(250);
	}
}

void sequenceEighteen()
{
	for(int i = 0; i < 5; i++)
	{
		both(1000);
	}
}

void sequenceNineteen()
{
	for(int i = 0; i < 10; i++)
	{
		left(500);
		left(250);
		right(500);
		right(250);
	}
}

void sequenceTwenty()
{
	for(int i = 0; i < 4; i++)
	{
		both(1500);
	}
}

void sequenceTwentyOne()
{
	for(int i = 0; i < 4; i++)
	{
		left(250);
		both(250);
		right(250);
	}
}
void sequenceTwentyTwo()
{
	for(int i = 0; i < 4; i++)
	{
		both(1250);
	}
}

void sequenceTwentyThree()
{
	for(int i = 0; i < 10; i++)
	{
		left(125);
		right(125);
	}
}


void sequenceTwentyFour()
{
	for(int i = 0; i < 4; i++)
	{
		left(750);
	}
}

void sequenceTwentyFive()
{
	for(int i = 0; i < 4; i++)
	{
		right(750);
	}
}

void sequenceTwentySix()
{
	for(int i = 0; i < 4; i++)
	{
		right(1500);
	}
}

void sequenceTwentySeven()
{
	for(int i = 0; i < 4; i++)
	{
		left(15, 30);
		right(15, 30);
		both(15, 30);
		both(15, 30);
		right(15, 30);
		left(15, 30);
	}
}

void testSequence()
{
//  both(1000);
//  delay(500);
//  both(500);
//  delay(500);
//  both(250);
//  delay(500);
//  both(125);
//  delay(500);
//  both(500);
//  delay(500);

	for(int i = 0; i < 4;i++)
	{
		left(500);
		left(500);
		right(400);
		right(400);
		both(300);
		both(300);
		right(200);
		left(200);
		left(100);
		right(100);
		both(75);
		both(50);
		left(25);
		right(25);
		Serial.println("Temp");
	}
}


