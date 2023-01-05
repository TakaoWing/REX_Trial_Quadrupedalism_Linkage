// モーター制御に必要なPIN
const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;
// モーターのスピード設定
int motorSpeed;  // モーターのスピード
// タクトスイッチの設定
const int switchPin = 2;  // タクトスイッチのピン
int switchState = 0;  // タクトスイッチの状態(State) 0:オフ，1:オン
int oldSitchState = 0;  // 一回前のタクトスイッチの状態
// モーターを動かすのか
bool isRunning = false;

void setup() {
  // モーター制御PINの設定
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  // タクトスイッチPINの設定
  pinMode(switchState, INPUT_PULLUP);
}

void loop() {
  // タクトスイッチの情報を取得
  // 押している時:LOW・離している時:HIGH
  switchState = digitalRead(switchPin);

  // ボタン離した時「動作を切り替える」
  if (oldSitchState == HIGH && switchState == LOW) {
    // 動作を切り替える
    isRunning = !isRunning;
    // チャタリング対策
    delay(10);
  } else if (oldSitchState == LOW && switchState == HIGH) {
    // チャタリング対策
    delay(10);
  }

  // 前回のスイッチの状態を更新
  oldSitchState = switchState;

  if (isRunning) {  // もし動かすなら
    // スピード100%で前進する
    setMotorSpeed(100);
    setForward(true);
  } else {  // もし動かさないなら
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