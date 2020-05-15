<template>
<!-- 部屋作成の画面 -->
<div>
  <div class="title">
    <h2>ルーム作成画面</h2>
  </div>
  <div class="main-contents">
    <!-- 動画のidを入力させる、入力欄と送信ボタン -->
    <form id="movie1">
      <input id="movie" placeholder="Youtube リンク入力(Enterで送信)" type='text' value=""/>
      <input type="button" v-on:click="roomCreate" value="room create">
    </form>
    <br>
    <!-- テスト用 -->
    <button v-on:click="fetch">room_test</button>
    <br>
    <!-- テスト用そのに -->
    <button v-on:click="userRead">room_test2</button>
    <div class="error">{{ this.error }}</div>
  </div>
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
      console.log(input_movie)
      const room = {
        id : id,
        movie : input_movie
      }
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
