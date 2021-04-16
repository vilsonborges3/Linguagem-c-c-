const int sen1Pin =  1; 

void setup() {
  Serial.begin(115200);
  pinMode(sen1Pin, OUTPUT);
  
}

void loop(){
  int read = 0;
  float readInVolts = 0;
  float temp = 0;
  read = analogRead(sen1Pin);
  readInVolts = read*0.00488;
  temp = 99.987*readInVolts - 50.259;
  Serial.print('\n');
  Serial.print(read);
  Serial.print(" Bits, ");
  Serial.print(readInVolts);
  Serial.print("V, ");
  Serial.print(temp);
  Serial.print("oC.");
  Serial.print('\n');
  delay(1000);
  Serial.print('\n');
}

