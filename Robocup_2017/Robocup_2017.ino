#include <DCMotor.h> 
#define cny_ext_izq 4
#define cny_izq 3
#define cny_der 2
#define cny_ext_der 1
#define ldr_der 0
#define ldr_izq 5
DCMotor motor_izq (M0_EN, M0_D0, M0_D1);
DCMotor motor_der (M1_EN, M1_D0, M1_D1);
void setup(){
  Serial.begin(9600);
  //const int izq = analogRead(cny_ext_izq);
}
void loop(){
  int cn_ext_izq = analogRead(cny_ext_izq);
  int cn_izq = analogRead(cny_izq);
  int cn_der = analogRead(cny_der);
  int cn_ext_der = analogRead(cny_ext_der);
  Serial.print("Ext_izq: ");  Serial.print(cn_ext_izq);
  Serial.print("izq: \t");  Serial.print(cn_izq);
  Serial.print("der: \t");  Serial.print(cn_der);
  Serial.print("Ext_der: \t");  Serial.println(cn_ext_der);
  delay(300);
  
  
}

