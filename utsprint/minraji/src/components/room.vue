<template>
<!-- 待機部屋の画面、部屋が作られると一覧が表示される -->
<div>
<header>
<h1 class="headline">
  <a>みんラジ!</a>
</h1>
 <ul class="nav-list">
      <li class="nav-list-item"><router-link to="/" id="back-home-button"> ホーム</router-link></li>
      <li class="nav-list-item"><!-- 部屋を作成する画面に移動 --><router-link to="/room_create" id="create-room-button">ルームを作成する</router-link></li>
      <li class="nav-list-item"> <amplify-sign-out></amplify-sign-out></li>
  </ul>	

</header>
<main>
  <section>
    <section>
      <h2>ルーム広場</h2>
      <p>ここはルームに入る待機場所です。「ルームを作成する」ボタンを押したら、ルームを作成するページに移動するので
      そこでルームを作成してください。
      </p>
      <router-link to="/room_create" id="create-room-button">ルームを作成する</router-link>
    </section>
   
      <!-- 部屋情報を一つずつ取ってきて表示する、押すとそれぞれの画面に移動する -->
    <section>
      <calendar></calendar>
      <div class="main-contents">
      <h2>作成したルーム一覧</h2>
      <p>作成されたルーム一覧です。自分が作ったルームに入りましょう。</p>
      <div id='room' v-for="room in rooms" :key="room.id">
        <button id = "go-room-button" v-on:click="gotoroom(room.id)">{{room.tilte}}</button>
        参加者 : {{members[0]}} 名
      </div>
      <div class="error">{{ this.error }}</div>
      </div>
    </section>
      
    
  </section>
</main>

</div>
</template>


<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
// import { Auth } from 'aws-amplify'
import router from '../router/router'
import calendar from "./calendar"
import { listRooms } from '../graphql/queries';
import { getRoom } from '../graphql/queries';
import { listUsers } from '../graphql/queries';
// import { getUser } from '../graphql/queries';
// import { createUser } from "../graphql/mutations";
import { updateUser } from "../graphql/mutations";
import UserStore from '../mobx/UserStore'

window.LOG_LEVEL = 'VERBOSE';

export default {
  name: 'chat',
  components: {
    calendar
  },
  data(){
    return {
      userName: "",
      members: [],
      // subscription: {},
      error: "",
      rooms: [],
      room_id: ""
    }
  },
  methods :{
    async fetch(){
      const room_temp = await API.graphql(graphqlOperation(listRooms,{limit:10}))
      this.rooms = room_temp.data.listRooms.items
      for(let i = 0; i < this.rooms.length; i++){
        let member = await API.graphql(graphqlOperation(getRoom,{id: this.rooms[i].id}))
        this.members.push(member.getRoom.users.items.length)
      }
      console.log(this.rooms)
    },
    async gotoroom(temp){
      //ユーザーの認証とかをやる
      const roomid = await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: this.userName}}}))
      const userroom = roomid.data.listUsers.items[0]
      console.log(userroom)
      // if (!userroom.roomid){
      console.log(document.getElementById("room").textContent)
      var room_a = await API.graphql(graphqlOperation(getRoom,{id: temp}))
      console.log(room_a.data.getRoom.users.items)
      this.members = room_a.data.getRoom.users.items
      var room = room_a.data.getRoom.users
      const userroomid = {
        id: userroom.id,
        username: this.userName,
        userRoomidId: room.id
      }
      console.log(userroomid)
      await API.graphql(graphqlOperation(updateUser, { input: userroomid }))
        .catch(error => this.error = JSON.stringify(error))
      // }
      // else{
      //   console.log('already room in')
      // }
      router.push('/room/in')
    }
  },
  async created(){
    const { username } = await UserStore
    console.log(UserStore)
    this.userName = username
    // this.fetch()
  }
}
</script>

<style src="./chat.css" />
