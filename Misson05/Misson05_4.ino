/* モーター制御に必要なPIN */
// int型の変数controlPin1を宣言
// 整数「13」を代入
const int controlPin1 = 13;
// int型の変数controlPin2を宣言
// 整数「12」を代入
const int controlPin2 = 12;
// int型の変数enablePinを宣言
// 整数「11」を代入
const int enablePin = 11;

/* タクトスイッチの設定 */
/* タクトスイッチのPIN */
// int型の変数switchPinを宣言
// 整数「2」を代入
const int switchPin = 2;
/* 以前のタクトスイッチの状態を保存する変数 */
// int型の変数previous_switch_stateを宣言
// HIGH(整数「0」)を代入
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
  // switchPinを入力(プルアップ抵抗を使用)に設定
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  // タクトスイッチの状態を読み込む
  int switch_state = digitalRead(switchPin);
  // スイッチの状態が変化していない時
  if (switch_state == previous_switch_state) {
    // 何もしない
    return;
  }
  // 設定した待ち時間以上経過している場合
  unsigned long period_time = milliseconds() - last_switch_time;
  if (period_time <= switchDebounceTime) {
    // 何もしない
    return;
  }
  // スイッチが押された時
  if (switch_state == LOW) {
    // モーターを100%のスピードで回転
    setSpeed(100);
  }
  // スイッチが押されていない時
  else {
    // モーターを停止
    setSpeed(0);
  }
  // 最後にタクトスイッチが押された時間を更新
  last_switch_time = milliseconds();
  // 以前のスイッチの状態を更新
  previous_switch_state = switch_state;
}

/* モーターの状態を切り替える */
void switchMotor(int speed_rate) {
  // speed_rateが0の時モーターを停止
  if (speed_rate == 0) {
    /* モーターを停止 */
    // controlPin1をLOWに設定
    digitalWrite(controlPin1, LOW);
    // controlPin2をLOWに設定
    digitalWrite(controlPin2, LOW);
  }
  // speed_rateが0より大きい時モーターを正転
  else if (speed_rate > 0) {
    /* モーターを正転 */
    // controlPin1をHIGHに設定
    digitalWrite(controlPin1, HIGH);
    // controlPin2をLOWに設定
    digitalWrite(controlPin2, LOW);
  }
  // speed_rateが0より小さい時モーターを逆転
  else if (speed_rate < 0) {
    /* モーターを逆転 */
    // controlPin1をLOWに設定
    digitalWrite(controlPin1, LOW);
    // controlPin2をHIGHに設定
    digitalWrite(controlPin2, HIGH);
  }
}

/* スピードを割合で指定 */
void setSpeed(int speed_rate) {
  // モーターの状態を切り替える
  switchMotor(speed_rate);
  // speed_rateを0~100から0~254に変換
  int mortor_speed = map(abs(speed_rate), 0, 100, 0, 254);
  /* モーターのスピードを設定 */
  // enablePinにmotor_speedを設定
  analogWrite(enablePin, motor_speed);
}

// map関数とは、指定した範囲の値を別の範囲の値に変換する関数
// map(変換する値, 変換前の最小値, 変換前の最大値, 変換後の最小値,
// 変換後の最大値)
// 変換する値が変換前の最小値より小さい場合は、変換後の最小値を返す
// 変換する値が変換前の最大値より大きい場合は、変換後の最大値を返す

// 例えば、map(100, 0, 100, 0, 255)の場合、
// 100が変換前の最小値より大きいので、
// 100を変換前の最大値で割った値である1を変換後の最大値で割った値である255に掛ける
// 255 * 1 = 255
// つまり、100は変換後の最大値である255に変換される

// また、map(0, 0, 100, 0, 255)の場合、
// 0が変換前の最小値と同じなので、
// 0を変換前の最大値で割った値である0を変換後の最大値で割った値である255に掛ける
// 255 * 0 = 0
// つまり、0は変換後の最小値である0に変換される

// このように、map関数は、指定した範囲の値を別の範囲の値に変換する関数である

// このプログラムでは、map関数を使って、
// speed_rateを0~100から0~254に変換している

// abs関数とは、絶対値を返す関数
// abs(値)
// 例えば、abs(-100)の場合、
// -100の絶対値である100を返す
// つまり、abs(-100)は100を返す

// このプログラムでは、abs関数を使って、
// speed_rateの絶対値を取得している

// millisecond関数とは、プログラムが起動してからの経過時間をミリ秒で返す関数
// millisecond関数は、unsigned long型の値を返す
// unsigned long型とは、符号なしの32ビットの整数型である
// つまり、0から4294967295までの値を表すことができる

// このプログラムでは、millisecond関数を使って、
// プログラムが起動してからの経過時間をミリ秒で取得している