//********************************************************************************
// USB keyboard ESP32 Test by Nathalis. 
//********************************************************************************
#include <PS2KeyAdvanced.h>

/* Define pins used for data and clock from keyboard (check connection schematic)  */
#define DATAPIN 19
#define IRQPIN  18

uint16_t c;

PS2KeyAdvanced keyboard;

void setup( )
{
   Serial.begin( 9600 );
   Serial.println( "USB Keyboard Test:" );
  
   // Configure the keyboard library
   keyboard.begin(DATAPIN,IRQPIN);
   keyboard.echo();              // ping keyboard to see if there
   delay(3);
   c = keyboard.read();
   if ((c & 0xFF)==PS2_KEY_ECHO || (c & 0xFF)==PS2_KEY_BAT)  Serial.println("Keyboard OK..");    // Response was Echo or power up
   else if ((c & 0xFF)==0) Serial.println("Keyboard Not Found");
   else {
      Serial.print( "Invalid Code received of " );
      Serial.println( c, HEX );
   }
}


void loop( )
{
   if ( keyboard.available()) {
      // read the next key
      c = keyboard.read( );
      if ( ( c & 0xFF ) > 0 ) Serial.println( c , HEX );
      delay(3);
   }
}
