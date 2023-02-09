// モーター制御に必要なPIN
const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;
// モーターのスピード設定
int motor_speed;
// タクトスイッチの設定
const int switch_pin = 2;  // タクトスイッチのピン
int switch_state = 0;  // タクトスイッチの状態(State) 0:オフ，1:オン
int old_switch_state = 0;  // 一回前のタクトスイッチの状態
// モーターを動かすのか
bool is_running = false;

void setup() {
  // モーター制御PINの設定
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  // タクトスイッチPINの設定
  pinMode(switch_state, INPUT_PULLUP);
}

void loop() {
  // タクトスイッチの情報を取得
  // 押している時:LOW・離している時:HIGH
  switch_state = digitalRead(switch_pin);

  // ボタン離した時「動作を切り替える」
  if (old_switch_state == HIGH && switch_state == LOW) {
    // 動作を切り替える
    is_running = !is_running;
    // チャタリング対策
    delay(10);
  } else if (switch_state == HIGH) {
    // チャタリング対策
    delay(10);
  }

  // 前回のスイッチの状態を更新
  old_switch_state = switch_state;

  if (is_running) {  // もし動かすなら
    // スピード100%で前進する
    setMotorSpeed(100);
    setForward(true);
  } else {  // もし動かさないなら
    // スピードを0%にする→モーターに電流を流さない
    setMotorSpeed(0);
  }
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