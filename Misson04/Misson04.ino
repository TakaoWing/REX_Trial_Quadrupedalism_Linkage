// モーター制御に必要なPIN
const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;
// モーターのスピード設定
int motor_speed;  // モーターのスピード

void setup() {
  // モーター制御PINの設定
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
}

void loop() {
  // スピード100%にする
  setMotorSpeed(100);
  // 直進
  setForward(true);
  // 3秒待つ
  delay(3000);
  // スピードを80%にする
  setMotorSpeed(80);
  // 後進
  setForward(false);
  // 3秒待つ
  delay(3000);
}

// モーターの進む方向を指定
void setForward(bool is_forward) {
  if (is_forward) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
}

// モーターのスピードを割合で指定
void setMotorSpeed(int speed_rate) {
  motor_speed = map(speed_rate, 0, 100, 0, 254);
  analogWrite(enablePin, motor_speed);
}