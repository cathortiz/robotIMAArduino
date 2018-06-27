// Robot IMA impreso en 3D
// con aplicación arduino
// versión 1.0

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
String hacer = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Hola! Estoy listo para arrancar");

  // encender motores
  motor1.setSpeed(150);
  motor2.setSpeed(150);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {
  uint8_t i;

  if (Serial.available()) {
    hacer = Serial.readStringUntil('\n');

    if (hacer.length()==3) {
      if (hacer == "x+;") {
        Serial.print("\nAvanzando");
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        for (i=0; i<255; i++) {
          motor1.setSpeed(i);
          motor2.setSpeed(i);
          delay(10);
        }
      } else if (hacer == "x-;") {
        Serial.print("\nRetrocediendo");
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        for (i=0; i<255; i++) {
          motor1.setSpeed(i);
          motor2.setSpeed(i);
          delay(10);
        }
      } else if (hacer == "y+;") {
        Serial.print("\nGirando a la Derecha");
        motor1.run(BACKWARD);
        motor2.run(FORWARD);
        for (i=0; i<255; i++) {
          motor1.setSpeed(i);
          motor2.setSpeed(i);
          delay(10);
        }
      } else if (hacer == "y-;") {
        Serial.print("\nGirando a la Izquierda");
        motor2.run(BACKWARD);
        motor1.run(FORWARD);
        for (i=0; i<255; i++) {
          motor1.setSpeed(i);
          motor2.setSpeed(i);
          delay(10);
        } 
      } else if (hacer == "--;"){
        Serial.print("\nParar");
        for (i=255; i!=0; i--) {
          motor1.setSpeed(i);
          motor2.setSpeed(i);
          delay(10);
        }
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        delay(1000);
      }
    } else {
      Serial.print("\nError de lectura");
      Serial.print("\nParar");
        for (i=255; i!=0; i--) {
          motor1.setSpeed(i);
          motor2.setSpeed(i);
          delay(10);
        }
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        delay(1000);
    }
  }
}
