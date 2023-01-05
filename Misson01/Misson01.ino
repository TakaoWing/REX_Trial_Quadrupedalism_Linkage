// モーター制御に必要なPIN
const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;

void setup() {
  // モーター制御PINの設定
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  // モーターの回転方向を指定
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW);
  // モーターに3V流す
  analogWrite(enablePin, 255);
}

void loop() {}