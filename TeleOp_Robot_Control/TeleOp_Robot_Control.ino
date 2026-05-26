#include "WebHelper.h"

int BACK_LEFT_A = 18;
int BACK_LEFT_B = 17;

int BACK_RIGHT_A = 21;
int BACK_RIGHT_B = 47;

int FRONT_LEFT_A = 5;
int FRONT_LEFT_B = 4;

int FRONT_RIGHT_A = 41;
int FRONT_RIGHT_B = 42;


void setup() {
  Serial.begin(115200);
  setupOTA();
  setupWebServer();


  pinMode(BACK_LEFT_A, OUTPUT);
  pinMode(BACK_LEFT_B, OUTPUT);

  pinMode(BACK_RIGHT_A, OUTPUT);
  pinMode(BACK_RIGHT_B, OUTPUT);

  pinMode(FRONT_LEFT_A, OUTPUT);
  pinMode(FRONT_LEFT_B, OUTPUT);

  pinMode(FRONT_RIGHT_A, OUTPUT);
  pinMode(FRONT_RIGHT_B, OUTPUT);
}

void loop() {
  handleWebServer();
  // put your main code here, to run repeatedly:




  if (keyboard.w && keyboard.a) {
    webPrintLn("FRONT/LEFT");
    mecanumFLBR(1);
  } else if (keyboard.w && keyboard.d) {
    webPrintLn("FRONT/RIGHT");
    mecanumFRBL(1);
  } else if (keyboard.s && keyboard.d) {
    webPrintLn("BACK/RIGHT");
    mecanumFRBL(-1);
  } else if (keyboard.s && keyboard.a) {
    webPrintLn("BACK/LEFT");
    mecanumFLBR(-1);
  } else if (keyboard.w) {
    webPrintLn("FORWARD");
    mecanumFRBL(1);
    mecanumFLBR(1);
  } else if (keyboard.s) {
    webPrintLn("BACK");
    mecanumFRBL(-1);
    mecanumFLBR(-1);
  } else if (keyboard.a) {
    webPrintLn("LEFT");
    mecanumFLBR(-1);
    mecanumFRBL(1);
  } else if (keyboard.d) {
    webPrintLn("RIGHT");
    mecanumFLBR(1);
    mecanumFRBL(-1);
  } else if (keyboard.q) {
    webPrintLn("ROTATE LEFT");
    frontLeftDrive(-1);
    backLeftDrive(-1);
    frontRightDrive(1);
    backRightDrive(1);
  } else if (keyboard.e) {
    webPrintLn("ROTATE RIGHT");
    frontLeftDrive(1);
    backLeftDrive(1);
    frontRightDrive(-1);
    backRightDrive(-1);
  } else if (keyboard.w) {
    webPrintLn("FORWARD");
    mecanumFRBL(1);
    mecanumFLBR(1);
  } else if (keyboard.s) {
    webPrintLn("BACK");
    mecanumFRBL(-1);
    mecanumFLBR(-1);
  } else if (keyboard.a) {
    webPrintLn("LEFT");
    mecanumFLBR(-1);
    mecanumFRBL(1);
  } else if (keyboard.d) {
    webPrintLn("RIGHT");
    mecanumFLBR(1);
    mecanumFRBL(-1);
  } 
  
  else {
    // webPrintLn("STOP");
    frontLeftDrive(0);
    backLeftDrive(0);
    frontRightDrive(0);
    backRightDrive(0);
  }



  // delay(20);
}

void mecanumFLBR(int power) {
  frontLeftDrive(power);
  backRightDrive(power);
}

void mecanumFRBL(int power) {
  frontRightDrive(power);
  backLeftDrive(power);
}


void frontLeftDrive(float power) {
  motorDrive(power, FRONT_LEFT_A, FRONT_LEFT_B);
}


void frontRightDrive(float power) {
  motorDrive(power, FRONT_RIGHT_A, FRONT_RIGHT_B);
}


void backLeftDrive(float power) {
  motorDrive(power, BACK_LEFT_A, BACK_LEFT_B);
}
void backRightDrive(float power) {
  motorDrive(power, BACK_RIGHT_A, BACK_RIGHT_B);
}

void motorDrive(float power, int pinA, int pinB) {
  power = constrain(power, -1, 1);
  power = map(power * 100, -100, 100, 0, 255);
  analogWrite(pinA, power);
  analogWrite(pinB, 255 - power);
}
