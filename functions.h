

void OpenUpperArm(){
  servoDispatch.moveTo(UPPER_ARM, 150, 1000, 1.0);  
}
void CloseUpperArm(){
  servoDispatch.moveTo(UPPER_ARM, 50, 500, 0.0);  
}
void OpenLowerArm(){
  servoDispatch.moveTo(LOWER_ARM, 150, 1000, 1.0);  
}
void CloseLowerArm(){
  servoDispatch.moveTo(LOWER_ARM, 50, 500, 0.0);  
}


void CloseClaw(){
  servoDispatch.moveTo(GRIPP_CLAW, 50, 500, 0.0); 
}

void OpenClaw(){
  servoDispatch.moveTo(GRIPP_CLAW, 50, 500, 1.0); 
}


void GrippLift(){
  servoDispatch.moveTo(GRIPP_LIFT, 50, 500, 1.0);
}

void GrippDown(){
  servoDispatch.moveTo(GRIPP_LIFT, 50, 500, 0.0);
}


void CPUArmLift(){

  servoDispatch.moveTo(CPUARM_LIFT, 50, 500, 1.0);
  DEBUG_PRINTLN("CPU ARM LIFT"); 
}

void CPUArmDown(){
  servoDispatch.moveTo(CPUARM_LIFT, 50, 500, 0.0);
  DEBUG_PRINTLN("CPU ARM DOWN"); 
}

void CPUArmON(){
  servoDispatch.moveTo(CPUARM_EXTEND, 50, 500, 1.0);
  
}
void CPUArmOFF(){
  servoDispatch.moveTo(CPUARM_EXTEND, 50, 500, 0.0);
}

void FireOut(){
  servoDispatch.moveToPulse(FIRE, 50, 50, 1300);
}

void FireIn() {
  //servoDispatch.moveTo(FIRE, 50, 50, 0.0);
  servoDispatch.moveToPulse(FIRE, 50, 50, 1800);
}

void FireStop(){
  servoDispatch.moveToPulse(FIRE, 50, 50, 1550); // Einzenelner Servo 1400
}

void Lock(){
      LOCK = true;  
}

void Unlock(){
      LOCK = false;
}


void resetSequence()
{
   if (LOCK == true) {return;}
    //servoSequencer.play(SeqPanelAllCloseLong, SizeOfArray(SeqPanelAllCloseLong), (GROUP_DOORS));
    servoDispatch.setServosEasingMethod(PANELS_MASK, Easing::CircularEaseIn);

        
    DelayCall::schedule([] {
   //SEQUENCE_PLAY_ONCE_VARSPEED_EASING(servoSequencer, SeqPanelAllCloseLong, PANELS_MASK, 50, 2000, Easing::CircularEaseIn, Easing::CircularEaseOut);
   
   servoSequencer.play(SeqPanelAllCloseLong, SizeOfArray(SeqPanelAllCloseLong), (PANELS_MASK));
    }, 3000);
    
    CloseUpperArm();
    CloseLowerArm();
    CloseClaw();
    GrippDown();
    CPUArmDown();
   // FireIn();
    //FireStop();
   dataPanel.setSequence(DataPanel::kDisabled);
   DEBUG_PRINTLN("reset.OK"); 
}

/*//BODY Action with Prefix #
 
DO ALL SE Marcduino Commands with : Prefix 


Panels:
#CL00  even :CL00
#CL01 - 05

#OP00  even :OP00
#OP01 - 05

Panels Flutter:

#OF00
#OF01 - 05

ARMS :

#OPUA   //Upper Arm
#OPLA   //Lower Arm

#CLUA   //Upper Arm
#CLLA   //Lower Arm

#LGA   //Lift Gripper Arm
#DGA   //Down Gripper Arm

#CC    //lose Claw
#OC    //open Claw

#CPUL  //CPU Arm Lift
#CPUD  //CPU Arm Down

#CPU1  //CPU Arm On
#CPU0  //CPU Arm Off


DRAWER:

#OPD0  //ALL Drawer open
#OPD1 - #OPD4

#CLD0  //All Drawer close
#CLD1  - #CLD4

GADGETS:

---Fire---
#F0    //Fire Stop  TEST
#FOUT  //Move Out   TEST
#FIN   //Move In    TEST

---Spray---

#SP1   //Spray On
#SP0   //Spray Off

----ANIMATION----

#GAON   //Open Door lift Arm and move Gripp
:SE00   //reset that move

#FION   // Open Door Move Fire out
#FIOFF  // Move Fire In and close Door
//Check position Input for Status//

#SPRAY  // Move Spary ON and Off

#SAON   // Open Door Move Arm and play On/off with Motor

SO     //Slider Out
SI     //Slider IN

lock   // Block Reset Function
unlock // UnBlock Reset Function

*/
