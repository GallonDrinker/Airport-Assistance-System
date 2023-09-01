#include<AFMotor.h>

AF_DCMotor fl(1);
AF_DCMotor bl(2);
AF_DCMotor fr(3);
AF_DCMotor br(4);
int fd = 70;
int lr = 160;
int mastercard;
char value,terminal_one,terminal_two,lobie,select;
void setup() {
  for (int i = 1; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  fl.setSpeed(fd);
  bl.setSpeed(fd);
  fr.setSpeed(fd);
  br.setSpeed(fd);
}

void loop() {
  voicecontrol();
  //go_terminal_one();
}

void voicecontrol() {
  if (Serial.available() > 0) {
    value = Serial.read();
    Serial.println(value);
    if (value == '1') {
      go_terminal_one();
    } else if (value == '2') {
      go_terminal_two();
    }
    else if (value == '3') {
      imi_ter1();
    }
    else if (value == '4') {
      imi_lobbi();
    }
    else if (value == '5') {
      lobbi_ter1();
    }
    else if (value == '6') {
      ter1_ini();
    }
    else if (value == '7') {
      imi_ter2();
    }
    else if (value == '8') {
      imi_lobbi2();
    }
    else if (value == '9') {
      lobbi2_ter2();
    }
    else if (value == '10') {
      ter2_ini();
    }
  }
}

void go_terminal_one(void) {
  move_Fwd_ter();
  movement_Rgt_ter();
  move_Fwd_ter();
  move_Lft_ter();
  Serial.print("imigration reached");
  delay(10000);
}
/*  while(!voicecontrol()){
    
  }
    move_Lft_ter();
    move_Fwd_ter104();
    movement_Inst_Stp();
    movement_Rgt_ter();
    move_Fwd_ter105();
    movement_Inst_Stp();
    delay(10000);
    Serial.print("Terminal one reached");
    if (mastercard == 1) {
      move_Lft_ter();
      move_Lft_ter();
      movement_Inst_Stp();
      move_Fwd_ter102();
      move_Lft_ter();
      movement_Inst_Stp();
      move_Fwd_ter104();
      move_Fwd_ter102();
      movement_Inst_Stp();
      movement_Rgt_ter();
      movement_Inst_Stp();
      move_Fwd_ter102();
      movement_Inst_Stp();
      move_Lft_ter();
      movement_Inst_Stp();
      move_Fwd_ter101();
      movement_Inst_Stp();
      movement_Rgt_ter();
      movement_Rgt_ter();
      Serial.println("initial reached");
    }
  }
  else if (select == lobie) {
    move_Lft_ter();
    move_Fwd_ter104();
    movement_Inst_Stp();
    move_Lft_ter();
    move_Fwd_ter106();
    movement_Inst_Stp();
    Serial.print("lobie reached");
    delay(5000);
    if (select == terminal_one) {
      move_Lft_ter();
      move_Lft_ter();
      move_Fwd_ter106();
      move_Fwd_ter107();
      movement_Inst_Stp();
      Serial.print("Terminal one reached");
      delay(10000);
      if (mastercard == 1) {
        move_Lft_ter();
        move_Lft_ter();
        movement_Inst_Stp();
        move_Fwd_ter102();
        move_Lft_ter();
        movement_Inst_Stp();
        move_Fwd_ter104();
        move_Fwd_ter102();
        movement_Inst_Stp();
        movement_Rgt_ter();
        movement_Inst_Stp();
        move_Fwd_ter102();
        movement_Inst_Stp();
        move_Lft_ter();
        movement_Inst_Stp();
        move_Fwd_ter101();
        movement_Inst_Stp();
        movement_Rgt_ter();
        movement_Rgt_ter();
        Serial.println("initial reached");
      }
    }
  }
}*/

void imi_ter1(){
  move_Fwd_ter();
  movement_Rgt_ter();
  move_Fwd_terf();
}

void imi_lobbi(){
  move_Fwd_ter();
  move_Lft_ter();
  move_Fwd_terf();
}

void lobbi_ter1(){
  movement_Rgt_ter();
  movement_Rgt_ter();
  move_Fwd_terf();
  move_Fwd_terf();
}

void ter1_ini(){
  movement_Rgt_ter();
  movement_Rgt_ter();
  move_Fwd_terf();
  move_Lft_ter();
  move_Fwd_ter();
  movement_Rgt_ter();
  move_Fwd_ter();
  move_Lft_ter();
  move_Fwd_ter();
  movement_Rgt_ter();
  movement_Rgt_ter();
}

void go_terminal_two(void) {
  move_Fwd_ter();
  move_Lft_ter();
  move_Fwd_ter();
  movement_Rgt_ter();
  Serial.print("imigration reached");
  delay(10000);
}
  /*if (select == terminal_two) {
    movement_Rgt_ter();
    move_Fwd_ter204();
    movement_Inst_Stp();
    move_Lft_ter();
    move_Fwd_ter202();
    movement_Inst_Stp();
    delay(10000);
    Serial.print("Terminal two reached");
    if (mastercard == 2) {
      movement_Rgt_ter();
      movement_Rgt_ter();
      movement_Inst_Stp();
      move_Fwd_ter202();
      movement_Inst_Stp();
      movement_Rgt_ter();
      movement_Inst_Stp();
      move_Fwd_ter204();
      move_Fwd_ter202();
      movement_Inst_Stp();
      move_Lft_ter();
      movement_Inst_Stp();
      move_Fwd_ter202();
      movement_Inst_Stp();
      movement_Rgt_ter();
      movement_Inst_Stp();
      move_Fwd_ter201();
      movement_Inst_Stp();
      move_Lft_ter();
      move_Lft_ter();
      movement_Inst_Stp();
      delay(10000);
      Serial.println("inital reached");
    }
  }
  else if (select == lobie) {
    movement_Rgt_ter();
    move_Fwd_ter204();
    movement_Inst_Stp();
    movement_Rgt_ter();
    move_Fwd_ter202();
    movement_Inst_Stp();
    Serial.print("lobie reached");
    delay(5000);
    if (select == terminal_two) {
      move_Lft_ter();
      move_Lft_ter();
      move_Fwd_ter202();
      move_Fwd_ter202();
      movement_Inst_Stp();
      Serial.print("Terminal two reached");
      delay(10000);
      if (mastercard == 1) {
        movement_Rgt_ter();
        movement_Rgt_ter();
        movement_Inst_Stp();
        move_Fwd_ter202();
        movement_Inst_Stp();
        movement_Rgt_ter();
        movement_Inst_Stp();
        move_Fwd_ter204();
        move_Fwd_ter202();
        movement_Inst_Stp();
        move_Lft_ter();
        movement_Inst_Stp();
        move_Fwd_ter202();
        movement_Inst_Stp();
        movement_Rgt_ter();
        movement_Inst_Stp();
        move_Fwd_ter201();
        movement_Inst_Stp();
        move_Lft_ter();
        move_Lft_ter();
        movement_Inst_Stp();
        delay(10000);
        Serial.println("inital reached");
      }
    }
  }
}*/


void imi_ter2(){
  move_Fwd_ter();
  move_Lft_ter();
  move_Fwd_terf();
}

void imi_lobbi2(){
  move_Fwd_ter();
  movement_Rgt_ter();
  move_Fwd_terf();
}

void lobbi2_ter2(){
  move_Lft_ter();
  move_Lft_ter();
  move_Fwd_terf();
  move_Fwd_terf();
}

void ter2_ini(){
  movement_Rgt_ter();
  movement_Rgt_ter();
  move_Fwd_terf();
  movement_Rgt_ter();
  move_Fwd_ter();
  move_Lft_ter();
  move_Fwd_ter();
  movement_Rgt_ter();
  move_Fwd_ter();
  movement_Rgt_ter();
  movement_Rgt_ter();
}

void move_Fwd_ter(void) {
  Serial.println("Going_Forward");
  fl.setSpeed(fd);
  bl.setSpeed(fd);
  fr.setSpeed(fd);
  br.setSpeed(fd);
  fl.run(FORWARD);
  bl.run(FORWARD);
  fr.run(FORWARD);
  br.run(FORWARD);
  delay(1000);
  fl.run(RELEASE);
  bl.run(RELEASE);
  fr.run(RELEASE);
  br.run(RELEASE);
  delay(300);
}

void move_Fwd_terf(void) {
  Serial.println("Going_Forward");
  fl.setSpeed(fd);
  bl.setSpeed(fd);
  fr.setSpeed(fd);
  br.setSpeed(fd);
  fl.run(FORWARD);
  bl.run(FORWARD);
  fr.run(FORWARD);
  br.run(FORWARD);
  delay(500);
  fl.run(RELEASE);
  bl.run(RELEASE);
  fr.run(RELEASE);
  br.run(RELEASE);
  delay(300);
}

void move_Lft_ter(void) {
  fl.setSpeed(lr);
  bl.setSpeed(lr);
  fr.setSpeed(lr);
  br.setSpeed(lr);
  Serial.println("Going_Left");
  fl.run(BACKWARD);
  bl.run(BACKWARD);
  fr.run(FORWARD);
  br.run(FORWARD);
  delay(500);
  fl.run(RELEASE);
  bl.run(RELEASE);
  fr.run(RELEASE);
  br.run(RELEASE);
  //delay(200);
}

void movement_Rgt_ter(void) {
  fl.setSpeed(lr);
  bl.setSpeed(lr);
  fr.setSpeed(lr);
  br.setSpeed(lr);
  Serial.println("Going_Right");
  fl.run(FORWARD);
  bl.run(FORWARD);
  fr.run(BACKWARD);
  br.run(BACKWARD);
  delay(500);
  fl.run(RELEASE);
  bl.run(RELEASE);
  fr.run(RELEASE);
  br.run(RELEASE);
  //delay(200);
}

void move_Bwd_ter(void) {
  fl.setSpeed(fd);
  bl.setSpeed(fd);
  fr.setSpeed(fd);
  br.setSpeed(fd);
  Serial.println("Going_Backward");
  fl.run(BACKWARD);
  bl.run(BACKWARD);
  fr.run(BACKWARD);
  br.run(BACKWARD);
  delay(1000);
  fl.run(RELEASE);
  bl.run(RELEASE);
  fr.run(RELEASE);
  br.run(RELEASE);
}


void movement_Inst_Stp(void) {
  Serial.println("Stopping");
  fl.run(RELEASE);
  bl.run(RELEASE);
  fr.run(RELEASE);
  br.run(RELEASE);
}
