
#include <Servo.h>

/* Servo Definitions */
Servo myservo1;
Servo myservo2;
Servo myservo3;

/* Parameter Intilialization */
int a1=120, a2=120, a3=120, timelag=10 , servoangstep=10;

void setup() {
  Serial.begin(115200);
  
  /* Servo pin Mapping and Initialization */
  myservo1.attach(9);
  myservo1.write(a1);

  myservo2.attach(10);
  myservo2.write(a2);

  myservo3.attach(11);
  myservo3.write(a3);
    
}


void loop() {

  if (Serial.available())
  {   
    /* NodeMCU USART Recieve Commands and Store in a Character Variable */
    char c=Serial.read();

    /* NodeMCU USART Recieved Command Response Categorization*/
    /* ////////////////////////////////////////////
       //  q            w            e           //
       //  servo1up     servo2up     servo3      //    
       //  a            s            d           //
       //  servo1down   servo2down   servo3down  //
       //////////////////////////////////////////// */
    switch (c)
    {
    //up1
    case 'q' :
    delay(timelag);
    a1+=servoangstep;
    myservo1.write(a1);
    break; 

    //down1
    case 'a' :
    delay(timelag);
    a1-=servoangstep;
    myservo1.write(a1);
    break;

    //up2
    case 'w' :
    delay(timelag);
    a2+=servoangstep;
    myservo2.write(a2);
    break;

    //down2
    case 's' :
    delay(timelag);
    a2-=servoangstep;
    myservo2.write(a2);
    break;

    //up3
    case 'e' :
    delay(timelag);
    a3+=servoangstep;
    myservo3.write(a3);
    break;

    //down3
    case 'd' :
    delay(timelag);
    a3-=servoangstep;
    myservo3.write(a3);
    break;
    }

    /* Send Angular Position Data via USART to NodeMCU */
    Serial.print("@");Serial.print(a1);Serial.println("$");
    Serial.print("@");Serial.print(a2);Serial.println("$");
    Serial.print("@");Serial.print(a3);Serial.println("$");
       
  }
}

  


