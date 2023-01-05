const int controlPin1 = 13;
const int controlPin2 = 12;
const int enablePin = 11;

int motorEnable = 0;
int motorSpeedRate = 80;
int motorDirection = 1;

const int switchPin = 2;  // タクトスイッチのピン
int switchState = 0;  // タクトスイッチの状態(State) 0:オフ，1:オン
int old_switchState = 0;  // 一回前のタクトスイッチの状態
// モーターを動かすかどうか false:動かさない, true:動かす
bool isRunning = false;

void setup() {
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  switchState = digitalRead(switchPin);  // switchPinの状態をswitchStateに代入
                                         // 押している時:LOW 離している時:HIGH
  if (switchState == LOW &&
      old_switchState ==
          HIGH) {  // もし「今の状態が押している時かつ前の状態が押していない時(スイッチを押した一瞬)」なら
    isRunning = !isRunning;  // 動きを切り替える
    delay(10);               // チャタリング用
  } else if (
      switchState == HIGH &&
      old_switchState ==
          LOW) {  // もし「今の状態が押している時」かつ「前の状態が押していない時」(スイッチを離したら)なら
    delay(10);    // チャタリング用
  }

  if (isRunning) {  // もし動かすなら
    analogWrite(enablePin, map(motorSpeedRate, 0, 100, 0, 254));
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {                      // 動かさなければ
    analogWrite(enablePin, 0);  // モータに電流を流さない
  }
  old_switchState = switchState;  // 今回のスイッチの状態を代入

  // delay(3000);

  // digitalWrite(controlPin1, LOW);
  // digitalWrite(controlPin2, HIGH);

  // delay(3000);
}