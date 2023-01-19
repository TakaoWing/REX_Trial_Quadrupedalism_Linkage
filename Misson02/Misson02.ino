// モーター制御に必要なPIN
const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;
// モーターのスピード設定
int motorSpeedRate = 100;  // モーターのスピードの割合
int motorSpeed;            // モーターのスピード

void setup() {
  // モーター制御PINの設定
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  // モーターの回転方向を指定
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW);
  // モーターのスピードを割合で指定
  motorSpeed = map(motorSpeedRate, 0, 100, 0, 254);
  analogWrite(enablePin, motorSpeed);
}

void loop() {}