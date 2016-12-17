#include <DCMotor.h> 
#define cny_ext_izq 5
#define cny_izq 2
#define cny_der 4
#define cny_ext_der 3
#define pin_ldr_der 0
#define pin_ldr_izq 1

//----
#define est_avanzar 0
#define int_izq 1
#define int_der 2

#define subest_int_izq 0
#define subest_int_der 1
#define subest_der_seg 2

//#define 
int cn_ext_izq, cn_izq, cn_der, cn_ext_der, ldr_der, ldr_izq;
int inter_der;
int inter_izq;
int estado = est_avanzar;
int subest;
DCMotor motor_der (M0_EN, M0_D0, M0_D1,false);
DCMotor motor_izq (M1_EN, M1_D0, M1_D1,false);

void calibrar(){
  cn_ext_izq = analogRead(cny_ext_izq);
  cn_izq = analogRead(cny_izq);
  cn_der = analogRead(cny_der);
  cn_ext_der = analogRead(cny_ext_der);
  ldr_der = analogRead(pin_ldr_der);
  ldr_izq = analogRead(pin_ldr_izq);
  Serial.print("Ext_izq: ");  
  Serial.println(cn_ext_izq);
  //Serial.print("izq: ");  Serial.println(cn_izq);
  //Serial.print("der: ");  Serial.println(cn_der);
  //Serial.print("Ext_der: ");  Serial.println(cn_ext_der);
  //delay(1500);

}

void setup(){
  Serial.begin(115200);
  //const int izq = analogRead(cny_ext_izq);
}
void loop(){
  while(estado == est_avanzar){

    calibrar();
    //motor_izq.setSpeed(32);
    //motor_der.setSpeed(40);
    /*if(cn_izq  > 115 && cn_der > 100 ){
     motor_izq.setSpeed(40);
     motor_der.setSpeed(40);
     delay(300);
     }*/
    if((cn_izq >= 115 || cn_der >= 100) && ldr_der > 850){
      inter_der++; 
      motor_izq.setSpeed(0);
      motor_der.setSpeed(0);
      delay(300);
      estado = int_der;

    }
    else if(cn_izq > 200 && cn_der > 166 && ldr_izq > 650){
      inter_izq++; 
      motor_izq.setSpeed(0);
      motor_der.setSpeed(0);
      //delay(300);
      estado = int_der;
      subest = subest_int_der;
    }
    if(cn_ext_izq >= 45 ){
      motor_izq.setSpeed(35);
      motor_der.setSpeed(-5);  
    }
    else if(cn_ext_der >= 45){
      motor_izq.setSpeed(-5);
      motor_der.setSpeed(30);
    }
    else{
      motor_izq.setSpeed(37);
      motor_der.setSpeed(37);
    }
  }
  while(estado == int_der){
    
    /*if(subest == subest_int_der){
      //calibrar();
      cn_ext_der = analogRead(cny_ext_der);
      motor_izq.setSpeed(-37);
      motor_der.setSpeed(-37);
      delay(1000);
      motor_izq.setSpeed(0);
      motor_der.setSpeed(0);
      delay(100);
      while(cn_ext_der < 45){
      cn_ext_der = analogRead(cny_ext_der);
      motor_izq.setSpeed(-37);
      motor_der.setSpeed(37);
      }
      subest = subest_der_seg;
    }*/
    if(subest == subest_der_seg){
      while(cn_ext_der >= 45){
      cn_ext_der = analogRead(cny_ext_der);
      motor_izq.setSpeed(-37);
      motor_der.setSpeed(0);
      }
      estado = est_avanzar;
    }
  }
}








