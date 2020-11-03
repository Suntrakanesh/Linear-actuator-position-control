int pos1 = 13; //button_1 for 2WD
int pos2 = 12; //button_2 for open diff
int pos3 = 8; //button_3 for lock diff
int pot = A0;
int drive = 0;
int position = 0; //store position value of actuator's shaft
int in_1 = 8; // input to relay ( channel 1 ) , for forward movement of actuator's shaft
int in_2 = 7; // input to relay ( channel 2 ) , for backward movement of actuator's shaft
float threshold = --- ;  //middle position of shaft , need to find 
float value_1 = ---- ; //initial position of shaft , need to find
float value_2 = ---- ; //final position of shaft , need to find

void setup()
{
pinMode( pos1, INPUT );
pinMode( pos2, INPUT );
pinMode( pos3, INPUT );
pinMode( pot , INPUT );
pinMode( in_1, OUTPUT );
pinMode( in_2, OUTPUT );
}

void loop()
{

   if( pos1 == HIGH )
    {
       drive = 1 ;
    }
  else if( pos2 == HIGH )
    {
       drive = 2;
    }
  else if( pos3 == HIGH )
    {
       drive = 3;
    }
  position = analogRead(pot);
  
    switch(drive)
    {
       //Condition for 2WD
      case 1: while( position != value_1 )
                 {
                   digitalWrite( in_2 , HIGH );
                   digitalWrite( in_1, LOW );
                 }
                 break;
          
      // Condition for open diff          
      case 2: if( position > threshold )
                {
                   while( position != threshold )
                     {
                          digitalWrite( in_2 , HIGH );
                          digitalWrite( in_1, LOW );
                     }
                 }
              else
                 {
                     while( position != threshold )
                     {
                          digitalWrite( in_2 , LOW );
                          digitalWrite( in_1, HIGH );
                     }
                 } 
                 break;
        
       // Condition for locked diff
       case 3:  while( position != value_2 )
                   {
                      digitalWrite( in_2 , LOW );
                      digitalWrite( in_1, HIGH );
                   }   
                   break;
                   
       }
       
  }
                 
                 
                 
 
