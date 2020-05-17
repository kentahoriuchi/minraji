<template>
<!-- 待機部屋の画面、部屋が作られると一覧が表示される -->
<div>
<header>
<h1 class="headline">
  <a>みんラジ!</a>
</h1>
 <ul class="nav-list">
      <li class="nav-list-item"><router-link to="/signout" id="back-home-button"> ホーム</router-link></li>
      <li class="nav-list-item"> <amplify-sign-out></amplify-sign-out></li>
  </ul>	
  <!--<router-link
    :to="{
      name: '/', 
      hash: '#hashtag'
      }"
  >ルームを作成する</router-link>-->
</header>
<main>
  <section>
    <section>
      <h2>ルーム広場</h2>
      <p>ここはルームに入る待機場所です。「ルームを作成する」ボタンを押したらルームを作成できます。</p>
    </section>
   
    
      <!-- 部屋を作成する画面に移動 -->
      <router-link to="/room_create" id="create-room-button">ルームを作成する</router-link>


      <!-- 部屋情報を一つずつ取ってきて表示する、押すとそれぞれの画面に移動する -->
    <section>
      <div class="main-contents">
      <h2>作成したルーム一覧</h2>
      <p>作成されたルーム一覧です。自分が作ったルームに入りましょう。</p>
      <!--<router-link to="/signout" id="back-home-button"> ホームに戻る</router-link>-->
      <div id='room' v-for="room in rooms" :key="room.id">
        <button id = "go-room-button" v-on:click="gotoroom(room.id)">{{room.id}}</button>
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
import { Auth } from 'aws-amplify'
import { createUser } from "../graphql/mutations";
import { updateUser } from "../graphql/mutations";
import { listRooms } from '../graphql/queries';
import { listUsers } from '../graphql/queries';
import router from '../router/router'
window.LOG_LEVEL = 'VERBOSE';
export default {
  name: 'chat',
  data(){
    return {
      userName: "",
      // subscription: {},
      error: "",
      rooms: [],
      room_id: ""
    }
  },
  methods :{
    fetch(){
      API.graphql(graphqlOperation(listRooms,{limit:10}))
        .then(rooms => this.rooms = rooms.data.listRooms.items)
        .catch(error => this.error = JSON.stringify(error))
      console.log(this.rooms)
    },
    async gotoroom(temp){
      //ユーザーの認証とかをやる
      const roomid = await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: this.userName}}}))
      const userroom = roomid.data.listUsers.items[0]
      // console.log(userroom.roomid)
      // if (!userroom.roomid){
      console.log(document.getElementById("room").textContent)
      var room_a = await API.graphql(graphqlOperation(listRooms, { filter: {'id':{eq: temp}}}))
      var room = room_a.data.listRooms.items[0]
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
    this.userName = (await Auth.currentAuthenticatedUser()).username;
    var user = await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: this.userName}}}))
    console.log(user.data.listUsers.items.length)
    console.log(!user.data.listUsers.items.length)
    if (!user.data.listUsers.items.length){
      const newuser = {
        id: new Date().getTime() + this.userName,
        username: this.userName
      }
      API.graphql(graphqlOperation(createUser, { input: newuser }))
        .catch(error => this.error = JSON.stringify(error))
      console.log(newuser)
    }
    this.fetch()
  }
}
</script>

<style src="./chat.css" />
