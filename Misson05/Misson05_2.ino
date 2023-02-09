// モーター制御に必要なPIN
const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;
// モーターのスピード設定
int motor_speed;
// タクトスイッチの設定
//// タクトスイッチのPINを2に設定
const int switch_pin = 2;
//// 以前のタクトスイッチの状態
int previous_switch_state = HIGH;

void setup() {
  // モーター制御PINの設定
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  // タクトスイッチPINの設定
  pinMode(switch_state, INPUT_PULLUP);
}

void loop() {
  // タクトスイッチの状態を読み込む
  int switch_state = digitalRead(switch_pin);

  // スイッチの状態が変化した時
  if (switch_state != previous_switch_state) {
    if (switch_state == LOW) {
      setMotorSpeed(100);
      setForward(true);
    } else {
      setMotorSpeed(0);
    }
    // チャタリング対策
    delay(10);
  }

  // 以前のスイッチの状態を更新
  previous_switch_state = switch_state;
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