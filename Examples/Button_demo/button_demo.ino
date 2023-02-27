const int led = 16;    // On board led 
const int button0 = 0; // button connect to GPIO 0
const int button1 = 9; // button connect to GPIO 9
const int button2 = 10;// button connect to GPIO 10

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button0, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() 
{
  int value1 = digitalRead(button0);
  int value2 = digitalRead(button1);
  int value3 = digitalRead(button2);
  if (value1 == LOW || value2 == LOW || value3 == LOW) //if any of button is pressed then led will glow
  {
   digitalWrite(led,LOW);
  }
  else
  {
   digitalWrite(led,HIGH);
  }
  Serial.print("button0 = ");
  Serial.println(value1);
  Serial.print("button1 = ");
  Serial.println(value2);
  Serial.print("button2 = ");
  Serial.println(value3);  
  delay(0.2);

  }
