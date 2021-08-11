int gnd=12;
int gnd1=4;
int led=13;
int led1=8;
int sensor=2;
int state=LOW;
int val=0;  
int const trigPin = 9;
int const echoPin = 10;
int const buzzPin = 11;

void setup()
{
pinMode(12,OUTPUT);
digitalWrite(12,LOW);

pinMode(4,OUTPUT);
digitalWrite(4,LOW);

pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
  
pinMode(trigPin, OUTPUT); // trig pin will have pulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
  }



void loop(){
    val=digitalRead(2);
    
        if(val==HIGH)
    {
      digitalWrite(13,LOW);
      digitalWrite(11,LOW);
         delay(200);
        if(state==HIGH)
        {state=LOW;}
    }
    
    else
    {
    digitalWrite(13,HIGH);
      digitalWrite(11,HIGH);
    delay(100);

   if(state==HIGH)
   {state=HIGH;}
    }

 // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
int duration, distance;
// Output pulse with 1ms width on trigPin
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
// Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
// if distance less than 0.5 meter and more than 0 (0 or less means over range)
if (distance <= 30 && distance >= 0) 
{
// Buzz

digitalWrite(8, HIGH);
digitalWrite(buzzPin, HIGH);

}
else 
{
// Don't buzz
digitalWrite(8, LOW);

digitalWrite(buzzPin, LOW);

}
// Waiting 60 ms won't hurt any one
delay(100);
    }
