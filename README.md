# このライブラリについて
ロボマスモータを動かすためのライブラリです．

ロボマスモータ専用のモータードライバを使うことを前提としています．

# ROBOMasterクラス

## インスタンス化
ロボマスモータのインスタンスを作成します．
```c++
newROBOMaster name(rd,td);
ROBOMaster name(&pinmap);
```
rd – read from transmitter (TDピン)<br>
td – transmit to transmitter (RDピン)<br>
pinmap – reference to structure which holds static pinmap<br>

## パブリックメンバ関数
一覧↓
```c++
name.set_speed(motor_no,speed);
val = name.write();
```

### set_speed
ロボマスモータの制御電流値を設定します．
```c++
name.set_speed(motor_no,speed);
```
パラメーター:<br>
motor_no – 設定するモータ番号(1～8)<br>
speed – 設定したい制御電流値(-10000～10000)<br>

### write
ロボマスモータにCANでデータを送ります．
```c++
val = name.write();
```
戻り値:<br>
0 if write failed (失敗), 1 if write was successful (成功)<br>

# 参考文献
- [ロボマスモータについて](https://www.robomaster.com/zh-CN/products/components/general/M2006)
- [モータードライバについて](https://store.dji.com/jp/product/rm-c610-brushless-dc-motor-speed-control?vid=40021)
- [ロボマスモータのデータシート](https://rm-static.djicdn.com/tem/17348/RM%20M2006%20P36%E7%9B%B4%E6%B5%81%E6%97%A0%E5%88%B7%E5%87%8F%E9%80%9F%E7%94%B5%E6%9C%BA%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E.pdf)
- [モータードライバのデータシート](https://rm-static.djicdn.com/tem/RM%20C610%E6%97%A0%E5%88%B7%E7%94%B5%E6%9C%BA%E8%B0%83%E9%80%9F%E5%99%A8%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E%20%E5%8F%91%E5%B8%83%E7%89%88.pdf)
- [参考にした記事](https://sabanekko2.hatenablog.com/entry/2023/07/17/005431)

# 今後の展望(やることリスト)

## フィードバックする
readして配列か何かに保存する．その内容を取り出せるようにする．

## 概要を書く
exampleがあるからいーじゃんとか思っていたものの，ちょっとは書くべきだろう．writeしないといけないのは罠だ．

## set_speedの後に勝手にwriteしてくれたら便利じゃね？というお話
単純に煩わしいので，勝手にwriteしてくれるようになるオプションを作ってもいいかなと思う．

## インスタンス化する際に，既存のCANインスタンスを指定できるようにする．
一つのCANで複数のROBOMasterということ．動作中に勝手にCANがdeleteされたらどうするのかという問題．結構つらい．