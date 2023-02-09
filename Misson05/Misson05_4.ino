/* モーター制御に必要なPIN */
const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;
/* タクトスイッチの設定 */
// タクトスイッチのPIN
const int switch_pin = 2;
// 以前のタクトスイッチの状態
int previous_switch_state = HIGH;
/* チャタリング対策用変数 */
// 最後にタクトスイッチが押された時間
unsigned long last_switch_time = 0;
// スイッチの状態が変化した時に待つ時間
const int switchDebounceTime = 10;

void setup() {
  /* モーター制御PINの設定 */
  // controlPin1を出力に設定
  pinMode(controlPin1, OUTPUT);
  // controlPin2を出力に設定
  pinMode(controlPin2, OUTPUT);
  // enablePinを出力に設定
  pinMode(enablePin, OUTPUT);
  /* タクトスイッチPINの設定 */
  // switch_pinを入力に設定
  // プルアップ抵抗を使用
  pinMode(switch_state, INPUT_PULLUP);
}

void loop() {
  // タクトスイッチの状態を読み込む
  int switch_state = digitalRead(switch_pin);
  // スイッチの状態が変化した時
  if (switch_state != previous_switch_state) {
    // 設定した待ち時間以上経過している場合
    long period_time = milliseconds() - last_switch_time;
    if (period_time > switchDebounceTime) {
      // スイッチが押された時
      if (switch_state == LOW) {
        setSpeed(100);
      }
      // スイッチが押されていない時
      else {
        setSpeed(0);
      }
      // 最後にタクトスイッチが押された時間を更新
      last_switch_time = milliseconds();
    }
  }
  // 以前のスイッチの状態を更新
  previous_switch_state = switch_state;
}

// モーターの状態を切り替える
void switchMotor(int state) {
  if (state == 0) {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);
  } else if (state == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else if (state == -1) {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
}

// モーターのスピードを割合で指定
void setSpeed(int speed_rate) {
  if (speed_rate > 0) {
    switchMotor(1);
  } else if (speed_rate < 0) {
    switchMotor(-1);
  } else {
    switchMotor(0);
  }
  int mortor_speed = map(abs(speed_rate), 0, 100, 0, 254);
  analogWrite(enablePin, motor_speed);
}