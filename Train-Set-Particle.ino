// ------------
// Train Set Particle
// ------------
// Authors Chris & Anthony Briggs
//-------------


int rbgBlueLed = D2;
int rgbGreenLed = D1;
int rgbRedLed = D0;

int led1 = D5; 

int led2 = D6;

int reedSwitch1 = D3;

int reedSwitch2 = D4;

int switch1 = D7;

int count = 0;
int countRS1 = 0;
int countRS2 = 0;
int countS1 = 0;
int countMax = 50; 

void setup() {

  pinMode(rbgBlueLed, OUTPUT);
  pinMode(rgbGreenLed, OUTPUT);
  pinMode(rgbRedLed, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(reedSwitch1, INPUT);
  pinMode(reedSwitch2, INPUT);
  pinMode(switch1, INPUT);
}

void loop() {
    if(countRS1 == 0)
    {
        if(digitalRead(reedSwitch1) == LOW)
        {
            digitalWrite(led1, HIGH);
            countRS1++;
        } 
        else 
        {
            digitalWrite(led1, LOW);
        }
    }
    else
    {
        if (countRS1 > countMax)
        {
             countRS1 = 0;
        }
        else
        {
         countRS1 ++;
        }
    }
    
    if(countRS2 == 0)
    {
        if(digitalRead(reedSwitch2) == LOW)
        {
            digitalWrite(led2, HIGH);
            countRS2++;
        }
        else
        {
            digitalWrite(led2, LOW);
        }
    }
    else
    {
        if (countRS2 > countMax)
        {
            countRS2 = 0;
        }
        else
        {
            countRS2 ++;
        }
    }

    if(countS1 == 0)
    {
        if(digitalRead(switch1)==LOW)
        {
         
            switch(count)
            {
                case 0:
                analogWrite(rbgBlueLed, 255);
                analogWrite(rgbGreenLed, 0);
                analogWrite(rgbRedLed, 0);
                count++;
                countS1 = countS1 +5 ;
                break;
                
                case 1: 
                analogWrite(rbgBlueLed, 0);
                analogWrite(rgbGreenLed, 255);
                analogWrite(rgbRedLed, 0);
                count++;
                countS1 = countS1 +5 ;
                break;
                
                case 2: 
                analogWrite(rbgBlueLed, 255);
                analogWrite(rgbGreenLed, 0);
                analogWrite(rgbRedLed, 255);
                count++;
                countS1 = countS1 +5 ;
                break;
                
                case 3: 
                analogWrite(rbgBlueLed, 0);
                analogWrite(rgbGreenLed, 0);
                analogWrite(rgbRedLed, 255);
                count++;
                countS1 = countS1 +5 ;
                break;
                
                default:
                analogWrite(rbgBlueLed, 255);
                analogWrite(rgbGreenLed, 255);
                analogWrite(rgbRedLed, 255);
                count = 0;
                countS1 = countS1 +5 ;
                break;
            }
        }
        else
        {
         digitalWrite(rbgBlueLed, LOW);
        digitalWrite(rgbGreenLed, LOW);
        digitalWrite(rgbRedLed, LOW); 
        }
    }
    else
    {
        if (countS1 > countMax)
        {
            countS1 = 0;
        }
        else
        {
            countS1 ++;
        }
    }

  delay(100);

}

