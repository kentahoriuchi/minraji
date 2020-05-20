<template>
<!-- 部屋作成の画面 -->
<div>
<header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
  <ul class="nav-list">
      <li class="nav-list-item"><router-link to="/signout" id="back-home-button"> ホーム</router-link></li>
      <li class="nav-list-item"> <amplify-sign-out></amplify-sign-out></li>
  </ul>	
</header>
<main>
  <section>
    <h2>ルーム作成</h2>
    <p>ここはルーム作成ページです。youtubeのURLを下のボックスにいれて「ルームを作る」ボタンを押してください。
    ルームを作成したら「ルーム広場に戻る」ボタンを押して作成したルームに入ってください</p>
  </section>

  <div class="main-contents">
    <!-- 動画のidを入力させる、入力欄と送信ボタン -->
    <form>
      <input id="title" placeholder="タイトル入力(Enterで送信)" size="50" type='text' value=""/>
      <input id="movie" placeholder="Youtube リンク入力(Enterで送信)" size="50" type='text' value=""/>
      <input type="button" v-on:click="roomCreate" value="ルームを作る" id="room-create-button">
    </form>
    <!--<br>-->
    <!-- テスト用 -->
    <!--<button v-on:click="fetch">room_test</button>-->
    
    <!-- テスト用そのに -->
    <!--<button v-on:click="userRead">room_test2</button>-->
  
    <div class="error">{{ this.error }}</div>
  </div>
  <router-link to="/room" id="back-room-button">ルーム広場に戻る</router-link>
 </main>
</div>
</template>

<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import { Auth } from 'aws-amplify'
import { createUser } from "../graphql/mutations";
import { createRoom } from "../graphql/mutations";
import { listRooms } from '../graphql/queries';
import { listUsers } from '../graphql/queries';
import router from '../router/router'
export default {
  name: 'room',
  data(){
    return {
      room_number: [],
      userData: [],
      userName: "",
      // subscription: {},
      error: ""
    }
  },
  methods :{
    userRead(){
      API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: this.userName}}}))
        .then(userData => this.userData = userData.data.listUsers.items)
      console.log(Array.from(this.userData))
      if (Array.from(this.userData) !== []) return
      console.log(this.userData)
      const newuser = {
        id: new Date().getTime() + this.userName,
        username: this.userName
      }
      API.graphql(graphqlOperation(createUser, { input: newuser }))
        .catch(error => this.error = JSON.stringify(error))
      this.userData = []
    },
    roomCreate(){
      const id = new Date().getTime() + this.userName
      const input_movie = document.getElementById("movie").value
      const movie_title = document.getElementById("title").value
      console.log(movie_title)
      const room = {
        id : id,
        movie : input_movie,
        tilte : movie_title
      }
      console.log(room)
      API.graphql(graphqlOperation(createRoom, { input: room }))
        .catch(error => this.error = JSON.stringify(error))
      router.push({name:'room'})
    },
    fetch(){
      API.graphql(graphqlOperation(listRooms, { limit: 100 }))
      .then(room_number => this.room_number = room_number.data.listRooms.items)
      .catch(error => this.error = JSON.stringify(error))
      console.log(this.room_number)
    }
  },
  async created(){
    this.userName = (await Auth.currentAuthenticatedUser()).username;
    this.fetch()
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
#back-room-button {
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

#back-room-button:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
}

#room-create-button {
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
</style>
