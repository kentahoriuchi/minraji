## 動かすために必要なこと書きます

### 追加で入れる必要があるやつ
```
npm install vue-material element-ui --save
```
なんかカスタムされたinput領域とか使える ul-**** (ul-inputなど)

```
npm install @fullcalendar/vue @fullcalendar/core @fullcalendar/daygrid @fullcalendar/interaction @fullcalendar/timegrid sass-loader sass webpack --save
```

### 使い方
へんな文字列が入ってる部分には動画IDを(動画のURLの"v="以降)入力。入力するだけで動画は変わる(TO DOエンターなどで変わるように)

シークしたい時間を下のテキストボックスに入力。エンターで動作。時間単位は秒。(10って入れると10秒ジャンプ)
