int pulsePin = 2;//interrupt 
int readyPin = 13;//ledOnDoard
int pulses = 0;
int pulsesWallet =0;
unsigned long timeCount = 0;
int timeAllPulse =3000;
int money=0;

void setup() {
  pinMode(readyPin, INPUT);
  pinMode(pulsePin, INPUT_PULLUP);
  //pinMode(pulsePin, INPUT);//pulses from ICT
  Serial.begin(9600);
  attachInterrupt(0,countPulses,FALLING);
  Serial.println("Ready...");
}

void loop() {
  Serial.println(pulses);
  //начали вкладывать купюры и с момента вкладки прошло 3 сек
if (pulses == 5 && (millis()-timeCount)>=timeAllPulse ){
  pulsesWallet =+ pulses;
  //pulses = 0;
    money = pulsesWallet*10;
  Serial.print("Money = ");
  Serial.println(money);
}
else   //idle
  //blinkLead();  //мигаем ждём
  delay(500);
  Serial.println("Nothing ...");
}
//firstCommithttps://github.com/nilsJavaNoob/kupyro.git
////
//obrab interrs
void countPulses(){
 detachInterrupt(0);//запр прерыв0
 pulses++;//edit 
 if(pulses==1){//first pulse?
    timeCount= millis();//check time
 attachInterrupt(0,countPulses,FALLING);
  }
}
void blinkLead(){
  digitalWrite(readyPin, HIGH);
  //ledState = digitalRead()
  Serial.println("LedOn");
  delay(300);               // wait for a second
  digitalWrite(readyPin, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("LedOff");
  delay(300);
}
