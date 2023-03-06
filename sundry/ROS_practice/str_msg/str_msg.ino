void setup() {
      Serial.begin(57600);
}

String message;
void loop() {
    if (Serial.available() > 0){
      message = Serial.readString();
      Serial.println(message);
    }
}
