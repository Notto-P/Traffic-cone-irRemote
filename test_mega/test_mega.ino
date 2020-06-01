#include <IRremote.h>

int RECV_PIN = 11;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;

int lled1 = 40;
int lled2 = 42;
int lled3 = 44;
int lled4 = 46;
int lled5 = 48;
int lled6 = 50;
int lled7 = 52;



int key = 0;

unsigned long currentMillis   = 0;
unsigned long previousMillis  = 0;

bool LED_status;
bool LLED_status;

int LED_count;
int LLED_count;
long interval   = 200;

#define code1      16753245 // Button 1
#define code2      16736925 // Button 2
#define code3      16769565 // Button 3
#define code4      16720605 // Button 4,5
#define code6      16761405 // Button 6
#define code7      16769055 // Button 7
#define code8      16754775 // Button 8
#define code9      16748655 // Button 9
#define code0      16750695 // Button 0
#define codeOK     16726215 // OK button
#define codeSharp  16756815 // # button
#define codeStar   16738455 // * button
#define codeUp     16718055 // up button
#define codedown   16730805 // down button
#define codeLeft   16716015 // up button
#define codeRight  16734885 // down button

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Setup");
  

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  pinMode(lled1, OUTPUT);
  pinMode(lled2, OUTPUT);
  pinMode(lled3, OUTPUT);
  pinMode(lled4, OUTPUT);
  pinMode(lled5, OUTPUT);
  pinMode(lled6, OUTPUT);
  pinMode(lled7, OUTPUT);


  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);

  digitalWrite(lled1, LOW);
  digitalWrite(lled2, LOW);
  digitalWrite(lled3, LOW);
  digitalWrite(lled4, LOW);
  digitalWrite(lled5, LOW);
  digitalWrite(lled6, LOW);
  digitalWrite(lled7, LOW);
  

  
  key = 0;
  LED_status = LOW ;
  LLED_status = LOW ;
  LED_count = 0;
  LLED_count = 0;
  interval = 300;
  Serial.print("key = ");
  Serial.println(key);


}


void(* resetFunc) (void) = 0;//declare reset function at address 0
                             //resetFunc(); //call reset 
                             
void loop() 
{  
outloop:
  if (irrecv.decode(&results)) 
  {
    Serial.print("code: ");
    Serial.println(results.value);

    
  
       if (results.value == code0)   // Off all LED
        {                                
          Serial.println("LED OFF ALL");
          LED_OFF_ALL ();
          key = 0;
        }

        if (results.value == codeOK) // Reset Arduino
        { 
          resetFunc();
        }

        if (results.value == code2)   // On all LED
        {                                
          Serial.println("LED ON ALL");
          LED_ON_ALL ();
          key = 2;
        }

        if (results.value == codeUp)   // speed
        {                                
          Serial.println("speed");
          interval = interval + 200;
          if(interval >= 1000)
          {
            interval = 300;
          }
        }

        if (results.value == codeLeft)   // both LED blink 
        {                                
          Serial.println("both LED blink");
          key = 22;
          LED_OFF();
          LLED_OFF();
        }

        if (results.value == codeRight)   // both LED run
        {                                
          Serial.println("both LED run");
          LED_OFF();
          LLED_OFF();
          key = 33;
        }

//---------------------------------------------------------------------------------
        if (results.value == code1)   // LED On
        {                                
          Serial.println("LED ON");
          LLED_OFF();
          LED_ON ();
          key = 1;
        }

        if (results.value == codeStar)   // LED Off
        {                                
          Serial.println("LED OFF");
          LLED_OFF();
          LED_OFF ();
          key = 11;
        }

        if (results.value == code4)   // LED blink
        {                                
          Serial.println("LED blink");
          LLED_OFF();
          key = 4;
        }

        if (results.value == code7)   // LED run
        {                                
          Serial.println("LED run");
          LLED_OFF();
          key = 7;
        }
//---------------------------------------------------------------------------------

        if (results.value == code3)   // LLED On
        {                                
          Serial.println("LED ON");
          LED_OFF();
          LLED_ON ();
          key = 3;
        } 

        if (results.value == codeSharp)   // LLED Off
        {                                
          Serial.println("LLED OFF");
          LED_OFF();
          LLED_OFF ();
          key = 12;
        }

        if (results.value == code6)   // LLED blink
        {                                
          Serial.println("LLED blink");
          LED_OFF();
          key = 6;
        }

        if (results.value == code9)   // LLED blink
        {                                
          Serial.println("LLED Run");
          LED_OFF();
          key = 9;
        }

         
    
    delay(100);
    irrecv.resume(); // Receive the next value
    
  }


  if (key == 22)
     {
         currentMillis = millis();
         if(currentMillis - previousMillis > interval)
         {
           previousMillis = currentMillis;
           if (LED_status == LOW)
           {
             Serial.println("on on");
             LED_ON ();
             LLED_ON ();
           }
           else
           {
             Serial.println("off off");
             LED_OFF ();
             LLED_OFF ();
           }
         }
     }

  if (key == 4)
     {
         currentMillis = millis();
         if(currentMillis - previousMillis > interval)
         {
           previousMillis = currentMillis;
           if (LED_status == LOW)
           {
             Serial.println("on");
             LED_ON ();
           }
           else
           {
             Serial.println("off");
             LED_OFF ();
           }
         }
     }

     if (key == 6)
     {
         currentMillis = millis();
         if(currentMillis - previousMillis > interval)
         {
           previousMillis = currentMillis;
           if (LLED_status == LOW)
           {
             Serial.println("on");
             LLED_ON ();
           }
           else
           {
             Serial.println("off");
             LLED_OFF ();
           }
         }
     }


     if (key == 33)
     {
         currentMillis = millis();
         if(currentMillis - previousMillis > interval)
         {
           previousMillis = currentMillis;
           if (LED_count == 0)
           {
             LED_1 ();
             LLED_1 ();
             goto outloop;
           }
           if (LED_count == 1)
           {
             LED_2 ();
             LLED_2 ();
             goto outloop;
           }
           if (LED_count == 2)
           {
             LED_3 ();
             LLED_3 ();
             goto outloop;
           }
           if (LED_count == 3)
           {
             LED_4 ();
             LLED_4 ();
             goto outloop;
           }
           if (LED_count == 4)
           {
             LED_5 ();
             LLED_5 ();
             goto outloop;
           }
           if (LED_count == 5)
           {
             LED_6 ();
             LLED_6 ();
             goto outloop;
           }
           if (LED_count == 6)
           {
             LED_7 ();
             LLED_7 ();
             goto outloop;
           }
           if (LED_count == 7)
           {
             LED_1 ();
             LLED_1 ();
             goto outloop;
           }
           
         }
     }
     
     if (key == 7)
     {
         currentMillis = millis();
         if(currentMillis - previousMillis > interval)
         {
           previousMillis = currentMillis;
           if (LED_count == 0)
           {
             LED_1 ();
             goto outloop;
           }
           if (LED_count == 1)
           {
             LED_2 ();
             goto outloop;
           }
           if (LED_count == 2)
           {
             LED_3 ();
             goto outloop;
           }
           if (LED_count == 3)
           {
             LED_4 ();
             goto outloop;
           }
           if (LED_count == 4)
           {
             LED_5 ();
             goto outloop;
           }
           if (LED_count == 5)
           {
             LED_6 ();
             goto outloop;
           }
           if (LED_count == 6)
           {
             LED_7 ();
             goto outloop;
           }
           if (LED_count == 7)
           {
             LED_1 ();
             goto outloop;
           }
           
         }
     }


     if (key == 9)
     {
         currentMillis = millis();
         if(currentMillis - previousMillis > interval)
         {
           previousMillis = currentMillis;
           if (LLED_count == 0)
           {
             LLED_1 ();
             goto outloop;
           }
           if (LLED_count == 1)
           {
             LLED_2 ();
             goto outloop;
           }
           if (LLED_count == 2)
           {
             LLED_3 ();
             goto outloop;
           }
           if (LLED_count == 3)
           {
             LLED_4 ();
             goto outloop;
           }
           if (LLED_count == 4)
           {
             LLED_5 ();
             goto outloop;
           }
           if (LLED_count == 5)
           {
             LLED_6 ();
             goto outloop;
           }
           if (LLED_count == 6)
           {
             LLED_7 ();
             goto outloop;
           }
           if (LLED_count == 7)
           {
             LLED_1 ();
             goto outloop;
           }
           
         }
     }



}



void LED_OFF_ALL ()
{
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
      digitalWrite(led6, 0);
      digitalWrite(led7, 0);

      digitalWrite(lled1, 0);
      digitalWrite(lled2, 0);
      digitalWrite(lled3, 0);
      digitalWrite(lled4, 0);
      digitalWrite(lled5, 0);
      digitalWrite(lled6, 0);
      digitalWrite(lled7, 0);

      LED_status = LOW ;
      LLED_status = LOW ;
      LED_count = 0;
      LLED_count = 0;
}

void LED_ON_ALL ()
{
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 1);
      digitalWrite(led6, 1);
      digitalWrite(led7, 1);

      digitalWrite(lled1, 1);
      digitalWrite(lled2, 1);
      digitalWrite(lled3, 1);
      digitalWrite(lled4, 1);
      digitalWrite(lled5, 1);
      digitalWrite(lled6, 1);
      digitalWrite(lled7, 1);

      LED_status = HIGH ;
      LLED_status = HIGH ;
      LED_count = 0;
      LLED_count = 0;
}


void LED_OFF ()
{
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
      digitalWrite(led6, 0);
      digitalWrite(led7, 0);

      LED_status = LOW ;
      LED_count = 0;
}

void LLED_OFF ()
{
      digitalWrite(lled1, 0);
      digitalWrite(lled2, 0);
      digitalWrite(lled3, 0);
      digitalWrite(lled4, 0);
      digitalWrite(lled5, 0);
      digitalWrite(lled6, 0);
      digitalWrite(lled7, 0);

      LLED_status = LOW ;
      LLED_count = 0;
}

void LED_ON ()
{
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 1);
      digitalWrite(led6, 1);
      digitalWrite(led7, 1);

      LED_status = HIGH ;
      LED_count = 0;
}

void LLED_ON ()
{
      digitalWrite(lled1, 1);
      digitalWrite(lled2, 1);
      digitalWrite(lled3, 1);
      digitalWrite(lled4, 1);
      digitalWrite(lled5, 1);
      digitalWrite(lled6, 1);
      digitalWrite(lled7, 1);

      LLED_status = HIGH ;
      LLED_count = 0;
}

void LED_1 ()
{
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
      digitalWrite(led6, 0);
      digitalWrite(led7, 0);
      
      LED_count = 1;
      Serial.println("1");
}


void LLED_1 ()
{
      digitalWrite(lled1, 1);
      digitalWrite(lled2, 0);
      digitalWrite(lled3, 0);
      digitalWrite(lled4, 0);
      digitalWrite(lled5, 0);
      digitalWrite(lled6, 0);
      digitalWrite(lled7, 0);

      LLED_count = 1;
      Serial.println("L1");
}



void LED_2 ()
{
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
      digitalWrite(led6, 0);
      digitalWrite(led7, 0);

      LED_count = 2;
      Serial.println("12");
}

void LLED_2 ()
{
      digitalWrite(lled1, 1);
      digitalWrite(lled2, 1);
      digitalWrite(lled3, 0);
      digitalWrite(lled4, 0);
      digitalWrite(lled5, 0);
      digitalWrite(lled6, 0);
      digitalWrite(lled7, 0);

      LLED_count = 2;
      Serial.println("L12");
}


void LED_3 ()
{
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
      digitalWrite(led6, 0);
      digitalWrite(led7, 0);

      LED_count = 3;
      Serial.println("123");
}

void LLED_3 ()
{
      digitalWrite(lled1, 1);
      digitalWrite(lled2, 1);
      digitalWrite(lled3, 1);
      digitalWrite(lled4, 0);
      digitalWrite(lled5, 0);
      digitalWrite(lled6, 0);
      digitalWrite(lled7, 0);

      LLED_count = 3;
      Serial.println("L123");
}

void LED_4 ()
{
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 0);
      digitalWrite(led6, 0);
      digitalWrite(led7, 0);

      LED_count = 4;
      Serial.println("1234");
}

void LLED_4 ()
{
      digitalWrite(lled1, 1);
      digitalWrite(lled2, 1);
      digitalWrite(lled3, 1);
      digitalWrite(lled4, 1);
      digitalWrite(lled5, 0);
      digitalWrite(lled6, 0);
      digitalWrite(lled7, 0);

      LLED_count = 4;
      Serial.println("L1234");
}

void LED_5 ()
{
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 1);
      digitalWrite(led6, 0);
      digitalWrite(led7, 0);

      LED_count = 5;
      Serial.println("12345");
}

void LLED_5 ()
{
      digitalWrite(lled1, 1);
      digitalWrite(lled2, 1);
      digitalWrite(lled3, 1);
      digitalWrite(lled4, 1);
      digitalWrite(lled5, 1);
      digitalWrite(lled6, 0);
      digitalWrite(lled7, 0);

      LLED_count = 5;
      Serial.println("L12345");
}


void LED_6 ()
{
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 1);
      digitalWrite(led6, 1);
      digitalWrite(led7, 0);

      LED_count = 6;
      Serial.println("123456");
}

void LLED_6 ()
{
      digitalWrite(lled1, 1);
      digitalWrite(lled2, 1);
      digitalWrite(lled3, 1);
      digitalWrite(lled4, 1);
      digitalWrite(lled5, 1);
      digitalWrite(lled6, 1);
      digitalWrite(lled7, 0);

      LLED_count = 6;
      Serial.println("L123456");
}

void LED_7 ()
{
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 1);
      digitalWrite(led6, 1);
      digitalWrite(led7, 1);

      LED_count = 7;
      Serial.println("1234567");
}

void LLED_7 ()
{
      digitalWrite(lled1, 1);
      digitalWrite(lled2, 1);
      digitalWrite(lled3, 1);
      digitalWrite(lled4, 1);
      digitalWrite(lled5, 1);
      digitalWrite(lled6, 1);
      digitalWrite(lled7, 1);

      LLED_count = 7;
      Serial.println("L1234567");
}
