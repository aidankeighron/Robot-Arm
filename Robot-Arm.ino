#include <Servo.h>

Servo turret;             
Servo gripper;             
Servo vertical;             
Servo horizontal;             

// Joystick
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
    turret.attach(6);  
    gripper.attach(9);  
    vertical.attach(10);  
    horizontal.attach(11);  
    turret.write(0);      
    gripper.write(0);      
    vertical.write(0);      
    horizontal.write(0); 

    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);   
    Serial.begin(9600);  
}

void loop() {   
    bool claw = digitalRead(SW_pin) == 1;            
    float x = analogRead(X_pin);     
    float y = analogRead(Y_pin);
    float theta = analogRead(2);
    x = (x/1000.0)*90.0;
    y = ((y/1000.0)*40.0)+60.0;
    theta = (theta/1000.0)*180.0;
    vertical.write(x);
    horizontal.write(y);
    gripper.write(claw?-10:80);
    turret.write(theta);
    Serial.print("Switch:  ");
    Serial.print(digitalRead(SW_pin));
    Serial.print("\n");
    Serial.print("X-axis: ");
    Serial.print(x);
    Serial.print("\n");
    Serial.print("Y-axis: ");
    Serial.println(y);
    Serial.print("Theta: ");
    Serial.println(theta);
    Serial.print("\n");
    delay(50);
}