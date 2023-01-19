#include <NewPing.h>

// 超音波センサーの設定
const int trigPin = 9;
const int echoPin = 10;
const int maxDisntance = 200;
NewPing sonar(trigPin, echoPin, maxDisntance);
// モーター制御に必要なPIN
const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;
// モーターのスピード設定
int motorSpeed;  // モーターのスピード

void setup() {
  // モーター制御PINの設定
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  // タクトスイッチPINの設定
  pinMode(switchState, INPUT_PULLUP);
}

void loop() {
  if (sonar.ping_cm() > 10) {  // もし距離が10cm以上なら
    // スピード100%で前進する
    setMotorSpeed(100);
    setForward(true);
  } else {  // でなければ
    // スピードを0%にする→モーターに電流を流さない
    setMotorSpeed(0);
  }
}

// モーターの進む方向を指定
void setForward(bool isForward) {
  if (isForward) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
}

// モーターのスピードを割合で指定
void setMotorSpeed(int motorSpeedRate) {
  motorSpeed = map(motorSpeedRate, 0, 100, 0, 254);
  analogWrite(enablePin, motorSpeed);
}