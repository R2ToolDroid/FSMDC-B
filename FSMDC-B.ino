//#define USE_DEBUG 
//#define USE_SERVO_DEBUG
//#define USE_VERBOSE_SERVO_DEBUG
#include "ReelTwo.h"
#include "core/Animation.h"
#include "core/DelayCall.h"
#include "ServoDispatchPCA9685.h"
#include "ServoSequencer.h"
#include "core/Marcduino.h"
#include "body/DataPanel.h"
#include "body/ChargeBayIndicator.h"
/*  NANO on Board
#define CBI_DATAIN_PIN 8 ////A1  //8
#define CBI_CLOCK_PIN  9 ////A2 //9
#define CBI_LOAD_PIN   10 ////A3  //10
*/
//  Test
#define CBI_DATAIN_PIN A1  //8
#define CBI_CLOCK_PIN  A2 //9
#define CBI_LOAD_PIN   A3  //10


#define COMMAND_SERIAL Serial1 //   Serial1 for LIVE   Serial  for USB Command

#define GROUP_DOORS      0x000F

#define DOOR_LEFT       0
#define DOOR_DATAPANEL  1
#define DOOR_CHARGEBAY  2
#define DOOR_MINI       3
#define DOOR_RIGHT      4
#define UPPER_ARM       5
#define LOWER_ARM       6
#define GRIPP_LIFT      7
#define GRIPP_CLAW      8
#define CPUARM_EXTEND   9
#define CPUARM_LIFT     10

#define DRAWER_1     11
#define DRAWER_2     12
#define DRAWER_3     13
#define DRAWER_4     14
#define FIRE         15
#define SPRAY        19


#define PANEL_GROUP_1      (1L<<14)
#define PANEL_GROUP_2      (1L<<15)
#define PANEL_GROUP_3      (1L<<16)
#define PANEL_GROUP_4      (1L<<17)
#define PANEL_GROUP_5      (1L<<18)

#define BIG_DOOR_GROUP     (1L<<19)
#define DRAWER_GROUP       (1L<<20)
#define DRAWER_GROUP_1     (1L<<21)
#define DRAWER_GROUP_2     (1L<<22)
#define DRAWER_GROUP_3     (1L<<23)
#define DRAWER_GROUP_4     (1L<<24)

#define PANELS_MASK        (DRAWER_GROUP|GROUP_DOORS)

const ServoSettings servoSettings[] PROGMEM = {
    //* PIN, closed 0, Open 1, GRoupe//
    
    { 1,  2000,  1200, GROUP_DOORS|PANEL_GROUP_1|BIG_DOOR_GROUP },  /* 0: DOOR_LEFT */
    { 2,  2100,  1000, GROUP_DOORS|PANEL_GROUP_2},  /* 1: DOOR_DATAPANEL */
    { 3,  600, 2000, GROUP_DOORS|PANEL_GROUP_3},  /* 2: DOOR_CHARGEBAY  */
    { 4,  2000, 1100, GROUP_DOORS|PANEL_GROUP_4},   /* 3: DOOR_MINI */
    { 5,  1000, 2100, GROUP_DOORS|PANEL_GROUP_5|BIG_DOOR_GROUP },    /* 4: DOOR_RIGHT */
    { 6,  600, 2500, 0 },             /* 5: UPPER_ARM */
    { 7,  600, 2500, 0 },             /* 6: LOWER_ARM */
    { 8,  800, 2050, 0 },            /* 7: GRIPP_LIFT */
    { 9,  1000, 1400, 0 },            /* 8: GRIPP_CLAW */
    { 10, 1100, 900, 0 },            /* 9: CPUARM_EXTEND */
    { 11, 800, 2050, 0 },            /* 10:CPUARM_LIFT */
    { 12, 2100, 1000, DRAWER_GROUP|DRAWER_GROUP_1 }, /* 11:DRAWER_1 */
    { 13, 2100, 1000, DRAWER_GROUP|DRAWER_GROUP_2 }, /* 12:DRAWER_2 */ 
    { 14, 2100, 1000, DRAWER_GROUP|DRAWER_GROUP_3 }, /*|13:DRAWER_3 */ 
    { 15, 1900, 1000, DRAWER_GROUP|DRAWER_GROUP_4 }, /* 14:DRAWER_4 */ 
    { 16, 1000, 2000, 0 }, /* 15:FIRE */  
    { 17, 1500, 1000, 0 }, /* 16:SPRAY */

    
};


static const ServoSequence SeqPanelAllOpenLong PROGMEM =
{
    { 2000,   B11111111, B11111111, B11111111, B11111111 },
};

static const ServoSequence SeqPanelAllCloseLong PROGMEM =
{
    { 2000,   B00000000, B00000000, B00000000, B00000000 },
};

LedControlMAX7221<2> ledChain(CBI_DATAIN_PIN, CBI_CLOCK_PIN, CBI_LOAD_PIN);

ChargeBayIndicator chargeBayIndicator(ledChain);
DataPanel dataPanel(ledChain);

ServoDispatchPCA9685<SizeOfArray(servoSettings)> servoDispatch(servoSettings);
ServoSequencer servoSequencer(servoDispatch);
AnimationPlayer player(servoSequencer);
MarcduinoSerial<> marcduinoSerial(COMMAND_SERIAL, player);


int ledState = LOW;   

byte LOCK = false;   //Lock all Doorfunktions

#include "functions.h"

////////////////
#include "MarcduinoPanel.h"

////////////////

#include "MarcduinoSequence.h"


MARCDUINO_ACTION(FlutterPanelTest, test, ({

  dataPanel.setSequence(DataPanel::kFlicker);
   
  chargeBayIndicator.setSequence(ChargeBayIndicator::kCharging );
}))

/*
 Data Panel
 kNormal = 0, kDisabled = 1, kFlicker = 2

  Charge Bay
0 kNormal   

1 kDisabled   
2 kFlicker  
3 kNaboo  
4 kCharging   
5 kBlink  
6 kHeart  
7 kVCCOnly 
*/


// Marcduino command starting with '*RT' followed by Reeltwo command
MARCDUINO_ACTION(DirectCommand, *RT, ({
    // Direct ReelTwo command
    CommandEvent::process(Marcduino::getCommand());
}))


void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    REELTWO_READY();
    Wire.begin();
    
    //Serial.begin(115200);  //delete for Nano 328
    
    COMMAND_SERIAL.begin(9600);
    SetupEvent::ready();
    //Serial.print("ready..");
    resetSequence();
    
    DEBUG_PRINTLN("ready.."); 
    
    dataPanel.setSequence(DataPanel::kDisabled);
    chargeBayIndicator.setSequence(ChargeBayIndicator::kDisabled);
    
    //dataPanel.setSequence(DataPanel::kNormal);
    //chargeBayIndicator.setSequence(ChargeBayIndicator::kNormal);
    
    //SEQUENCE_PLAY_ONCE(servoSequencer, sMySeqPanelAllOpen, GROUP_DOORS);
    //servoDispatch.moveServosTo(GROUP_DOORS, 150, 100, 1.0); // completely open
    //servoDispatch.moveToPulse(FIRE, 150, 100, 800); // Einzenelner Servo
    //SEQUENCE_PLAY_ONCE_VARSPEED_EASING(servoSequencer, SeqPanelMarchingAnts, GROUP_DOORS, 500, 1000, Easing::CircularEaseIn, Easing::BounceEaseOut);
}


 
void loop()
{
    AnimatedEvent::process();
}
