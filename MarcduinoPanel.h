//////////////// ALLCOMANDS FOR DIRECT PANEL SERVO USING
//////////////// Start with Marcduino Comands and Extend by CBD and Custom 

MARCDUINO_ACTION(CloseAllPanels, #CL00, ({
    //Marcduino::processCommand(player, "@4S3");
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, GROUP_DOORS);
    resetSequence();
    DEBUG_PRINTLN("CLOSE ALL"); 
}))

MARCDUINO_ACTION(CloseAllPanelsMD, :CL00, ({
    //Marcduino::processCommand(player, "@4S3");
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, GROUP_DOORS);
    resetSequence();
    DEBUG_PRINTLN("CLOSE ALL"); 
}))

////////////////

MARCDUINO_ACTION(OpenAllPanels, #OP00, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpenLong, GROUP_DOORS);
    dataPanel.setSequence(DataPanel::kNormal);
    chargeBayIndicator.setSequence(ChargeBayIndicator::kNormal);
   DEBUG_PRINTLN("OPEN ALL"); 
}))

MARCDUINO_ACTION(OpenAllPanelsMD, :OP00, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpenLong, GROUP_DOORS);
    dataPanel.setSequence(DataPanel::kNormal);
    chargeBayIndicator.setSequence(ChargeBayIndicator::kNormal);
    
   DEBUG_PRINTLN("OPEN ALL"); 
}))

////////////////

MARCDUINO_ACTION(FlutterAllPanels, #OF00, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, GROUP_DOORS, 10, 50);
    //dataPanel.setSequence(DataPanel::kNormal);
    //chargeBayIndicator.setSequence(ChargeBayIndicator::kNormal);

    DO_COMMAND_AND_WAIT(F(
      // Charge Bay Indicator flicker for 6s
        "CB20008\n"
        // Data Panel flicker for 6s
        "DP20008\n"        
    ),8000)
    
     DO_RESET({
        dataPanel.setSequence(DataPanel::kDisabled);
        chargeBayIndicator.setSequence(ChargeBayIndicator::kDisabled); 
    })
    
    
}))

////////////////

MARCDUINO_ACTION(OpenPanelGroup1, #OP01, ({
   // SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, 0);
    // servoDispatch.setServoEasingMethod(GROUP_DOORS, Easing::CircularEaseIn);
     servoDispatch.setServoEasingMethod(DOOR_LEFT, Easing::CircularEaseIn);
    servoDispatch.moveTo(DOOR_LEFT, 150, 500, 1.0); // completely open
    
}))

////////////////

MARCDUINO_ACTION(OpenPanelGroup2, #OP02, ({
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, DOOR_DATAPANEL);
    servoDispatch.setServoEasingMethod(DOOR_DATAPANEL, Easing::CircularEaseIn);
    dataPanel.setSequence(DataPanel::kNormal);
    servoDispatch.moveTo(DOOR_DATAPANEL, 150, 500, 1.0); // completely open
}))

////////////////

MARCDUINO_ACTION(OpenPanelGroup3, #OP03, ({
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, DOOR_CHARGEBAY);
    chargeBayIndicator.setSequence(ChargeBayIndicator::kNormal);
    servoDispatch.setServoEasingMethod(DOOR_CHARGEBAY, Easing::CircularEaseIn);
    servoDispatch.moveTo(DOOR_CHARGEBAY, 150, 500, 1.0); // completely open
}))

////////////////

MARCDUINO_ACTION(OpenPanelGroup4, #OP04, ({
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, DOOR_MINI);
    servoDispatch.setServoEasingMethod(DOOR_MINI, Easing::CircularEaseIn);
    servoDispatch.moveTo(DOOR_MINI, 150, 500, 1.0); // completely open
}))

////////////////

MARCDUINO_ACTION(OpenPanelGroup5, #OP05, ({
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, DOOR_RIGHT);
    servoDispatch.setServoEasingMethod(DOOR_RIGHT, Easing::CircularEaseIn);
    servoDispatch.moveTo(DOOR_RIGHT, 150, 500, 1.0); // completely open
}))



MARCDUINO_ACTION(ClosePanelGroup1, #CL01, ({
   // SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, 0);

    servoDispatch.setServoEasingMethod(DOOR_LEFT, Easing::CircularEaseIn);
    servoDispatch.moveTo(DOOR_LEFT, 150, 500, 0.0); // completely close
}))

////////////////

MARCDUINO_ACTION(ClosePanelGroup2, #CL02, ({
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DOOR_DATAPANEL);
    servoDispatch.setServoEasingMethod(DOOR_DATAPANEL, Easing::CircularEaseIn);
    servoDispatch.moveTo(DOOR_DATAPANEL, 150, 500, 0.0); // completely close
    dataPanel.setSequence(DataPanel::kDisabled);
}))

////////////////

MARCDUINO_ACTION(ClosePanelGroup3, #CL03, ({
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DOOR_CHARGEBAY);
    servoDispatch.setServoEasingMethod(DOOR_CHARGEBAY, Easing::CircularEaseIn);
    servoDispatch.moveTo(DOOR_CHARGEBAY, 150, 500, 0.0); // completely close
    
    chargeBayIndicator.setSequence(ChargeBayIndicator::kDisabled);
}))

////////////////

MARCDUINO_ACTION(ClosePanelGroup4, #CL04, ({
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DOOR_MINI);
    servoDispatch.setServoEasingMethod(DOOR_MINI, Easing::CircularEaseIn);
    servoDispatch.moveTo(DOOR_MINI, 150, 500, 0.0); // completely close
}))

////////////////

MARCDUINO_ACTION(ClosePanelGroup5, #CL05, ({
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DOOR_RIGHT);
    servoDispatch.setServoEasingMethod(DOOR_RIGHT, Easing::CircularEaseIn);
    servoDispatch.moveTo(DOOR_RIGHT, 150, 500, 0.0); // completely close
}))

//////////////////
///// ARMS SECTION
//////////////////

MARCDUINO_ACTION(OpenUpperArm, #OPUA, ({
    OpenUpperArm();
}))

////////////////

MARCDUINO_ACTION(OpenLowerArm, #OPLA, ({
    OpenLowerArm();
}))

MARCDUINO_ACTION(CloseUpperArm, #CLUA, ({
    CloseUpperArm();
}))

////////////////

MARCDUINO_ACTION(CloseLowerArm, #CLLA, ({
    CloseLowerArm();
}))


MARCDUINO_ACTION(LiftGripperArm, #LGA, ({
    GrippLift();
}))

MARCDUINO_ACTION(DownGripperArm, #DGA, ({
    GrippDown();
}))

MARCDUINO_ACTION(CloseClaw, #CC, ({
    CloseClaw();
}))

MARCDUINO_ACTION(OpenClaw, #OC, ({
    OpenClaw();
}))

MARCDUINO_ACTION(CPUArmLift, #CPUL, ({
    CPUArmLift();
}))

MARCDUINO_ACTION(CPUArmDown, #CPUD, ({
    CPUArmDown();
}))

MARCDUINO_ACTION(CPUArmON, #CPU1, ({
    CPUArmON();
}))

MARCDUINO_ACTION(CPUArmOFF, #CPU0, ({
    CPUArmOFF();
}))





//////////////////
////DRAWER SECTION
//////////////////  

////////////////

MARCDUINO_ACTION(OpenDrawerAll, #OPD0, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, DRAWER_GROUP);
}))


////////////////

MARCDUINO_ACTION(OpenDrawerGroup1, #OPD1, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, DRAWER_GROUP_1);
}))

////////////////

MARCDUINO_ACTION(OpenDrawerGroup2, #OPD2, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, DRAWER_GROUP_2);
}))

////////////////

MARCDUINO_ACTION(OpenDrawerGroup3, #OPD3, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, DRAWER_GROUP_3);
}))

////////////////

MARCDUINO_ACTION(OpenDrawerGroup4, #OPD4, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpen, DRAWER_GROUP_4);
}))

////////////////

MARCDUINO_ACTION(CloseDrawerAll, #CLD0, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DRAWER_GROUP);
}))

////////////////

MARCDUINO_ACTION(CloseDrawerGroup1, #CLD1, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DRAWER_GROUP_1);
}))

////////////////

MARCDUINO_ACTION(CloseDrawerGroup2, #CLD2, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DRAWER_GROUP_2);
}))

////////////////

MARCDUINO_ACTION(CloseDrawerGroup3, #CLD3, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DRAWER_GROUP_3);
}))

////////////////

MARCDUINO_ACTION(CloseDrawerGroup4, #CLD4, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DRAWER_GROUP_4);
}))
/*
MARCDUINO_ACTION(ClosePanelGroup10, :CL10, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, PANEL_GROUP_10);
}))

////////////////

MARCDUINO_ACTION(CloseTopPanels, :CL11, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, PIE_PANEL);
}))

////////////////

MARCDUINO_ACTION(CloseBottomPanels, :CL12, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, DOME_PANELS_MASK);
}))

////////////////
*/

MARCDUINO_ACTION(FlutterPanelGroup1, #OF01, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_1 , 10, 50);
}))

////////////////

MARCDUINO_ACTION(FlutterPanelGroup2, #OF02, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_2 , 10, 50);
}))

////////////////

MARCDUINO_ACTION(FlutterPanelGroup3, #OF03, ({

  
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_3 , 10, 50);
}))

////////////////

MARCDUINO_ACTION(FlutterPanelGroup4, #OF04, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_4 , 10, 50);
}))

////////////////

MARCDUINO_ACTION(FlutterPanelGroup5, #OF05, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_5 , 10, 50);
}))

MARCDUINO_ACTION(FireOut, FOUT, ({
     //servoDispatch.moveToPulse(FIRE, 150, 100, 800); // Einzenelner Servo
     FireOut();
}))

MARCDUINO_ACTION(FireIN, FIN, ({
   // servoDispatch.moveToPulse(FIRE, 150, 100, 1800); // Einzenelner Servo
   FireIn();
}))

MARCDUINO_ACTION(FireStop, #F0, ({
   // servoDispatch.moveToPulse(FIRE, 150, 100, 1800); // Einzenelner Servo
   FireStop();
}))

/*////FIRESTOP test/////////

MARCDUINO_ACTION(FireStop1, 1, ({
   servoDispatch.moveToPulse(FIRE, 50, 50, 1500); // Einzenelner Servo
   //FireStop();
}))

MARCDUINO_ACTION(FireStop2, 2, ({
   servoDispatch.moveToPulse(FIRE, 50, 50, 1550); // Einzenelner Servo
   //FireStop();
}))
MARCDUINO_ACTION(FireStop3, 3, ({
   servoDispatch.moveToPulse(FIRE, 50, 50, 1600); // Einzenelner Servo
   //FireStop();
}))

MARCDUINO_ACTION(FireStop4, 4, ({
   servoDispatch.moveToPulse(FIRE, 50, 50, 1700); // Einzenelner Servo
   //FireStop();
}))

MARCDUINO_ACTION(FireStop5, 5, ({
   servoDispatch.moveToPulse(FIRE, 50, 50, 1800); // Einzenelner Servo
   //FireStop();
}))

*/

MARCDUINO_ACTION(SprayON, #SP1, ({
    //servoDispatch.moveToPulse(SPRAY, 150, 100, 800); // Einzenelner Servo
    servoDispatch.moveTo(SPRAY, 50, 50, 1.0);
}))

MARCDUINO_ACTION(SprayOFF, #SP0, ({
    ///servoDispatch.moveToPulse(SPRAY, 150, 100, 1800); // Einzenelner Servo
    servoDispatch.moveTo(SPRAY, 50, 50, 0.0);
}))


MARCDUINO_ACTION(LOCK, lock, ({
    Lock();
}))

MARCDUINO_ACTION(UN_LOCK, unlock, ({
    Unlock();
}))


////////////////
/*

MARCDUINO_ACTION(FlutterPanelGroup6, :OF06, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_6, 10, 50);
}))

////////////////

MARCDUINO_ACTION(FlutterPanelGroup7, :OF07, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_7, 10, 50);
}))

////////////////

MARCDUINO_ACTION(FlutterPanelGroup8, :OF08, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_8, 10, 50);
}))

////////////////

MARCDUINO_ACTION(FlutterPanelGroup9, :OF09, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_9, 10, 50);
}))

////////////////

MARCDUINO_ACTION(FlutterPanelGroup10, :OF10, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANEL_GROUP_10, 10, 50);
}))
*/

/*
MARCDUINO_ACTION(test, :CL00, ({
    //Marcduino::processCommand(player, "@4S3");
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, GROUP_DOORS);
    servoDispatch.moveServosTo(GROUP_DOORS, 150, 200, 0.0); // completely closed
   // COMMAND_SERIAL.print("found CL00");
   DEBUG_PRINTLN("found CL00"); 
}))


Each servo can have it's own easing style. To set servo easing there are three different methods:

For a single servo:

    servoDispatch.setServoEasingMethod(1, Easing::CircularEaseIn);

                                SERVO, STARTDELAY, MOVETIME, POS
    servoDispatch.moveToPulse(SPRAY, 150, 100, 800); // Einzenelner Servo

For a group of servos

    servoDispatch.setServosEasingMethod(HOLO_SERVOS_MASK, Easing::CircularEaseIn);

For all servos:

    servoDispatch.setEasingMethod(Easing::CircularEaseIn);

The ServoSequencer also allows you to specify different servo easing methods for opening and closing.

            SEQUENCE_PLAY_ONCE_VARSPEED_EASING(servoSequencer, SeqPanelMarchingAnts, ALL_DOME_PANELS_MASK, 500, 1000, Easing::CircularEaseIn, Easing::BounceEaseOut);


/*
MARCDUINO_ACTION(test1, :OP00, ({
    //Marcduino::processCommand(player, "@4S3");
    //SEQUENCE_PLAY_ONCE(servoSequencer, sMySeqPanelAllOpen, GROUP_DOORS);
    servoDispatch.setServoEasingMethod(GROUP_DOORS, Easing::CircularEaseIn);
    servoDispatch.moveServosTo(GROUP_DOORS, 150, 500, 1.0); // completely open
   //servoDispatch.moveServosTo(GROUP_DOORS, 150, 100, 0.0); // completely closed
   //servoDispatch.moveServosTo(GROUP_DOORS, 150, 100, 0.5); // half open


   // COMMAND_SERIAL.print("found CL00");
   DEBUG_PRINTLN("found OP00"); 
}))


MARCDUINO_ACTION(test3, :MD00, ({
    //Marcduino::processCommand(player, "@4S3");
    //SEQUENCE_PLAY_ONCE(servoSequencer, sMySeqPanelAllOpen, GROUP_DOORS);
    SEQUENCE_PLAY_ONCE_VARSPEED_EASING(servoSequencer, SeqPanelMarchingAnts, GROUP_DOORS, 500, 1000, Easing::CircularEaseIn, Easing::BounceEaseOut);
    //servoDispatch.moveServosTo(GROUP_DOORS, 150, 100, 1.0); // completely open
   //servoDispatch.moveServosTo(GROUP_DOORS, 150, 100, 0.0); // completely closed
   //servoDispatch.moveServosTo(GROUP_DOORS, 150, 500, 0.5); // half open


   // COMMAND_SERIAL.print("found CL00");
   DEBUG_PRINTLN("found MD00"); 
}))
////////////////
*/
