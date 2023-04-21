#include <gravity_soil_moisture_sensor.h>
#include <Servo.h>
#define LED 13  
Servo tap_servo;
int sensor_pin = 4, tap_servo_pin =5;
int sensor_signal;
//setup
void setup(){
   pinMode(LED, OUTPUT); 
  pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin); 
}
//loop
void loop(){
  sensor_signal = digitalRead(sensor_pin);
  if (sensor_signal ==0)
  {  digitalWrite(LED, HIGH);
  delay(1000);
//delay is there so as to give the warning before the bridge lifts up or goes down
    tap_servo.write(0);
  }
//Danger! The water level has exceeded the threshold(safe) height!
  else
  {   digitalWrite(LED, LOW);
  delay(1000);
//delay is there so as to give the warning before the bridge lifts up or goes down
    tap_servo.write(90);
    }}
