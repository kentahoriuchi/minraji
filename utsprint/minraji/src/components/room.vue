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
      <!-- <calendar></calendar> -->
      <div class="main-contents">
      <h2>作成したルーム一覧</h2>
      <p>作成されたルーム一覧です。自分が作ったルームに入りましょう。</p>
      <div id='room' v-for="room in rooms" :key="room.id">
        <button id = "go-room-button" v-on:click="gotoroom(room.id)">{{room.tilte}}</button>
        参加者 : {{room.numberofmember}} 名
      </div>
      <!-- <div id='overlay' v-show='showContent'>
        <p>これがモーダルウィンドウです。</p>
        <p><button v-on:click='closeModel'>close</button></p>
      </div> -->
      <div class="error">{{ this.error }}</div>
      </div>
    </section>
      
    
  </section>
</main>

</div>
</template>


<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import router from '../router/router'
// import calendar from "./calendar"
import { listRooms } from '../graphql/queries';
import { getRoom } from '../graphql/queries';
import { updateRoom } from "../graphql/mutations";
import { updateUser } from "../graphql/mutations";
import UserStore from '../mobx/UserStore'

window.LOG_LEVEL = 'VERBOSE';

export default {
  name: 'chat',
  // components: {
    // calendar
  // },
  data(){
    return {
      userName: "",
      userId: "",
      members: [],
      error: "",
      rooms: [],
      showContent: false,
      // subscription: {},
    }
  },
  methods :{
    async fetch(){
      //部屋データを取得
      const roomlimit = 100  // 表示する部屋の数のmax
      const rooms = await API.graphql(graphqlOperation(listRooms,{limit:roomlimit}))
      this.rooms = rooms.data.listRooms.items
    },
    async gotoroom(id){
      //ユーザー部屋入室情報追加
      const updateuserinput = {
        id: this.userId,
        username: this.userName,
        userRoomidId: id
      }
      await API.graphql(graphqlOperation(updateUser, { input: updateuserinput }))
        .catch(error => this.error = JSON.stringify(error))
      // 部屋の人数更新
      const getroom = await API.graphql(graphqlOperation(getRoom,{id: id}))
      // if(roominfo.data.getRoom.privatepassword){
      //   this.showContent = true
      // }
      const roommember = getroom.data.getRoom.numberofmember
      const addroommenber = {
        id: id,
        numberofmember: roommember + 1
      }
      console.log(roommember)
      await API.graphql(graphqlOperation(updateRoom, { input: addroommenber }))
        .catch(error => this.error = JSON.stringify(error))

      router.push('/room/in')
    },
    // closeModel: function(){
    //   this.showContent = false
    // }
  },
  async created(){
    const { username,userid } = await UserStore
    console.log(UserStore)
    this.userName = username
    this.userId = userid 
    this.fetch()
  }
}
</script>

<style src="./chat.css" />
