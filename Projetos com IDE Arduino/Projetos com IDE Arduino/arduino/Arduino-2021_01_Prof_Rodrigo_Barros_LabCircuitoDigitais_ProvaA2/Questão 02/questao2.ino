
void setup() {
  pinMode(2, OUTPUT); 
  pinMode(13, OUTPUT); 
  Serial.begin(9600);
}

void loop(){
  float time, distancia;
  
  pinMode(7, OUTPUT); 
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  pinMode(7, INPUT); 
  time = pulseIn(7, HIGH);
  //distancia = ( tempo de retorno / (10000.0/343.0) )/ 2;
  distancia = (time/(10000.0/343.0) )/2;
  Serial.println(distancia,3);
  Serial.println("cm");
  Serial.print("\n");
  if(distancia < 50.0){
  	digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
  }
  if(distancia >= 50.0 && distancia < 150){
  	digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
  }
  if(distancia >= 150){
  	digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
}