<template>
<!-- 部屋作成の画面 -->
<div>
<header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
  <ul class="nav-list">
      <li class="nav-list-item"><router-link to="/" id="back-home-button"> ホーム</router-link></li>
      <li class="nav-list-item"><router-link to="/room" id="back-room-button-header">ルーム広場に戻る</router-link></li>
      <li class="nav-list-item"> <amplify-sign-out></amplify-sign-out></li>
  </ul>	
</header>
<main>
  <section>
    <h2>ルーム作成</h2>
    <p>ここはルーム作成ページです。ルームタイトルにルーム名を記入して、youtubeにあるラジオ体操の動画のURLを下のボックスにいれて「ルームを作る」ボタンを押してください。
      プレイベートルームを希望の方は、「プライベートルームにする」にチェックをつけてパスワードを入力してください。
      「ルームを作る」ボタンを押したら自動的にルーム広場に戻ります。ルーム広場では作成したルームに入ってください。
    </p>
    <p>
    例えば、https://www.youtube.com/watch?v=5sYm_3z6NsQ の動画を使ってルームを作るとします。
    URLを全部下のボックスに貼ります。
    </p>
  </section>

  <div class="main-contents">
    <!-- 動画のidを入力させる、入力欄と送信ボタン -->
    <form id="movie1">
      <div id="input1">
      <input id="title" placeholder="ルームタイトルを入力してください" size="30" type='text' value=""/>
      <input id="movie" placeholder="Youtubeのリンク入力をしてください" size="30" type='text' value=""/>
      </div>
      <div id="input2">
      <input type='checkbox' id="check" />プライベートルームにする
      <input id="password" placeholder="パスワードを入力してください" size="30" type='text' value=""/>
      </div>
      <div id="input3">
      <input type="button" v-on:click="roomCreate" value="ルームを作る" id="room-create-button">
      </div>
    </form>
    
    <div class="error">{{ this.error }}</div>
  </div>
  <!--<router-link to="/room" id="back-room-button">ルーム広場に戻る</router-link>-->
 </main>
</div>
</template>

<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import router from '../router/router'
import { createRoom } from "../graphql/mutations";
import UserStore from '../mobx/UserStore'

export default {
  name: 'room',
  data(){
    return {
      roomNumber: [],
      userData: [],
      userName: "",
      error: "",
      // subscription: {},
    }
  },
  methods :{
    async roomCreate(){
      const id = new Date().getTime() + this.userName

      const inputmovie = document.getElementById("movie").value
      const movietitle = document.getElementById("title").value
      var password = document.getElementById("password").value
      const privatemode = document.getElementById("check").checked
      //プライベートモードの時、パスワード所持
      if(!privatemode){
        password = null
      }
      console.log(password)
      const createroom = {
        id : id,
        movie : inputmovie,
        tilte : movietitle,
        numberofmember : 0,
        privatepassword: password
      }
      console.log(createroom)
      await API.graphql(graphqlOperation(createRoom, { input: createroom }))
        .catch(error => this.error = JSON.stringify(error))
      router.push({name:'room'})
    },
  },
  async created(){
    const { username } = await UserStore
    this.userName = username
  },
}
</script>

<style>
header {
  height: 120px;
  width: 100%;
  padding: 15px 0;
  /*background-color: #337079;*/
  background: #dfefff;
}
header .headline{
  /*background: #dfefff;
  box-shadow: 0px 0px 0px 5px #dfefff;
  border: dashed 1px #96c2fe;
  padding: 0.2em 0.5em;
  color: #454545;*/
  line-height: 100px;
  float: left;
  font-size: 50px;
  margin-left: 100px;
  color: #454545;
}
main {
  height: 1000px;
  width: 100%;
  padding: 15px 0;
  /*background-color: #337079;*/
  /*background: #dfefff;*/
}
#back-home-button{
  font-size: 1.4em;
  position: relative;
  display: inline-block;
  padding: 0.25em 0.5em;
  text-decoration: none;
  color: #FFF;
  background: #fd9535;/*背景色*/
  border-bottom: solid 2px #d27d00;/*少し濃い目の色に*/
  border-radius: 4px;/*角の丸み*/
  box-shadow: inset 0 2px 0 rgba(255,255,255,0.2), 0 2px 2px rgba(0, 0, 0, 0.19);
  font-weight: bold;
}
  
#back-home-button:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
}
#back-room-button-header {
  font-size: 1.4em;
  position: relative;
  display: inline-block;
  padding: 0.25em 0.5em;
  text-decoration: none;
  color: #FFF;
  background: #fd9535;/*背景色*/
  border-bottom: solid 2px #d27d00;/*少し濃い目の色に*/
  border-radius: 4px;/*角の丸み*/
  box-shadow: inset 0 2px 0 rgba(255,255,255,0.2), 0 2px 2px rgba(0, 0, 0, 0.19);
  font-weight: bold;
}
#back-room-button-header:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
}
#back-room-button {
  font-size: 1.4em;
  position: relative;
  top:20px;
  display: inline-block;
  padding: 0.25em 0.5em;
  text-decoration: none;
  color: #FFF;
  background: #fd9535;/*背景色*/
  border-bottom: solid 2px #d27d00;/*少し濃い目の色に*/
  border-radius: 4px;/*角の丸み*/
  box-shadow: inset 0 2px 0 rgba(255,255,255,0.2), 0 2px 2px rgba(0, 0, 0, 0.19);
  font-weight: bold;
}
#back-room-button:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
}
#room-create-button {
  font-size: 1.4em;
  position: relative;
  left:10px;
  display: inline-block;
  padding: 0.25em 0.5em;
  text-decoration: none;
  color: #FFF;
  background: #fd9535;/*背景色*/
  border-bottom: solid 2px #d27d00;/*少し濃い目の色に*/
  border-radius: 4px;/*角の丸み*/
  box-shadow: inset 0 2px 0 rgba(255,255,255,0.2), 0 2px 2px rgba(0, 0, 0, 0.19);
  font-weight: bold;
}
#movie {
  position:relative;
  left:5px;
  width:20%;
  height:15px;
}
#movie::placeholder{
  font-size:1.4em;
}

#title {
  position:relative;
  width:20%;
  height:15px;
}
#title::placeholder{
  font-size:1.4em;
}
#password {
  width:20%;
  height:15px;
}
#paasword::placeholder{
  font-size:1.4em;
}
#input1 {
  position:relative;
  top:5px;
}
#input2 {
  position:relative;
  top:10px;
}
#input3 {
  position:relative;
  top:15px;
}
</style>