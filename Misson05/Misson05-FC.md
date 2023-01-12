```mermaid
flowchart TB
  node_1(["開始"])
  node_2["モーター制御に必要なPINの変数を定義"]
  node_3[["setup関数"]]
  node_4[["loop関数"]]
  node_4 --> node_4
  node_13["モーターのスピード設定"]
  node_5(["setup関数"])
  node_6["モーター制御PINの設定"]
  node_8(["Return"])
  node_9(["loop関数"])
  node_17["タクトスイッチの設定"]
  node_18["モーターを動作を設定"]
  node_19["タクトスイッチ制御PINの設定"]
  node_7["タクトスイッチの情報を取得"]
  node_10["ボタンの動作で動きを変更"]
  node_11["動作を切り替える"]
  node_12["0.01秒待つ（チャタリング対策）"]
  node_14["0.01秒待つ（チャタリング対策）"]
  node_15["前回のスイッチの状態を更新"]
  node_16["動作するになってますか？"]
  node_20["スピードを100%にする"]
  node_21["直進"]
  node_22(["Return"])
  node_23["スピードを0%にする"]
  node_1 --> node_2
  node_3 --> node_4
  node_2 --> node_13
  node_5 --> node_6
  node_13 --> node_17
  node_17 --> node_18
  node_18 --> node_3
  node_6 --> node_19
  node_19 --> node_8
  node_9 --> node_7
  node_7 --> node_10
  node_10 --"ボタンを離した時"--> node_11
  node_11 --> node_12
  node_10 --"ボタンを押した時"--> node_14
  node_12 --> node_15
  node_14 --> node_15
  node_15 --> node_16
  node_16 --"はい"--> node_20
  node_20 --> node_21
  node_21 --> node_22
  node_16 --"いいえ"--> node_23
  node_23 --> node_22
```
