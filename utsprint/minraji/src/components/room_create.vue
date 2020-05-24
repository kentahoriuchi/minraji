<template>
<!-- 部屋作成の画面 -->
<div>
<header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
  <ul class="nav-list">
      <li class="nav-list-item"><router-link to="/"><button id="back-home-button">ホーム</button></router-link></li>
      <li class="nav-list-item"><router-link to="/room"><button id="go-room-button">ルーム広場に戻る</button></router-link></li>
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
      </div>
      <div id="input2">
        ルームの開始時刻を入力してください
        <input type="time" id="reservedtime"  size="30" value=""/>
      </div>
      <div id="input3">
      <input id="movie" placeholder="Youtubeのリンク入力をしてください" size="30" type='text' value=""/>
      </div>
      <div id="input4">
      <input type='checkbox' id="check" />プライベートルームにする
      </div>
      <div id="input5">
        <input id="password" placeholder="パスワードを入力してください" size="30" type='text' value=""/>
      </div>
      <div id="input6">
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
      const reservedtime = document.getElementById("reservedtime").value
      var password = document.getElementById("password").value
      const privatemode = document.getElementById("check").checked

      console.log(reservedtime)
      //プライベートモードの時、パスワード所持
      if(!privatemode){
        password = null
      }
      if(!inputmovie || !movietitle || !reservedtime){
        var erromessage = document.getElementById("errormessage")
        erromessage.innerHTML = "ルーム情報が無効です"
        return
      }
      if(privatemode && !password){
        var erromessagepassword = document.getElementById("errormessage")
        erromessagepassword.innerHTML = "パスワードを入力してください"
        return
      }
      console.log(password)
      const createroom = {
        id : id,
        movie : inputmovie,
        tilte : movietitle,
        numberofmember : 0,
        privatepassword: password,
        reservedtime: reservedtime
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
<style src="./chat.css" />



