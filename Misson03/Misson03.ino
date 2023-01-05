// モーター制御に必要なPIN
const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;
// モーターのスピード設定
int motorSpeedRate = 100;  // モーターのスピードの割合
int moterSpeed;            // モーターのスピード
// モーターの向き
bool isForward = true;

void setup() {
  // モーター制御PINの設定
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  // モーターのスピードを割合で指定
  moterSpeed = map(motorSpeedRate, 0, 100, 0, 254);
  analogWrite(enablePin, moterSpeed);
}

void loop() {
  // モーターの回転方向を指定
  if (isForward) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
}