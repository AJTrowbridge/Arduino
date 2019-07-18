int SwitchControl1 = 7;
int SwitchControl2 = 6;
int inputPin = A0;
int LED = 13;
int incomingByte;
int const dataPoints = 100;
float dataS[dataPoints];
float dataR[dataPoints];


void setup() {
  Serial.begin(9600);
  pinMode(SwitchControl1, OUTPUT);
  pinMode(SwitchControl2, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){
    
    char command = Serial.read();
    
    switch(command){
      
      case 'S':
        digitalWrite(SwitchControl2, LOW);
        delay(500);
        digitalWrite(SwitchControl1, HIGH);
        //digitalWrite(LED, HIGH);
        for(int i = 0; i < dataPoints; i++){
          float value = analogRead(inputPin);
          float voltage = value * (1.0 / 1023.0);
          dataS[i] = voltage;
          delay(5);
        }
        digitalWrite(SwitchControl1, LOW);
        digitalWrite(SwitchControl2, LOW);
        delay(100);
        for(int i = 0; i < dataPoints; i++){
          Serial.println(dataS[i]);
        }
        Serial.println("\nOpen");
        break;
        
        
        
      case 'R':
        digitalWrite(SwitchControl1, LOW);
        delay(500);
        digitalWrite(SwitchControl2, HIGH);
        //digitalWrite(LED, LOW);
        for(int i = 0; i < dataPoints; i++){
          float value = analogRead(inputPin);
          float voltage = value * (1.0 / 1023.0);
          dataR[i] = voltage;
          delay(5);
        }
        digitalWrite(SwitchControl1, LOW);
        digitalWrite(SwitchControl2, LOW);
        delay(100);
        for(int i = 0; i < dataPoints; i++){
          Serial.println(dataR[i]);
        }
        Serial.println("\nClosed");
        break;

      default:
        digitalWrite(SwitchControl1, LOW);
        digitalWrite(SwitchControl2, LOW);
        break;
    }
  }
}
