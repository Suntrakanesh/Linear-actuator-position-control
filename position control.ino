
int in1 = 8; //input to relay ( channel 1 ) , for forward movement of actuator's shaft
int in2 = 7; //input to relay ( channel 2 ) , for backward movement of actuator's shaft
int engage = 13 ; // Button 1
int disengage = 12 ; // Button 2
int pot = A0 ; // reading position value from actuator's shaft
int position;

void setup()
{
pinMode( in1 , OUTPUT );
pinMode( engage , OUTPUT );
pinMode( disengage , OUTPUT );
pinMode( in2 , OUTPUT );
pinMode( A0 , INPUT );
Serial.begin(9600);
}

void loop()
{

if( engage == HIGH )
{
digitalWrite( in1 , HIGH );
position = analogRead(pot);
Serial.println("position value");
Serial.println(position);
}
else if( disengage == HIGH )
{
digitalWrite( in2 , HIGH );
position = analogRead(pot);
Serial.println("position value");
Serial.println(position);
}

}

