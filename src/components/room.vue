<template>
<!-- 待機部屋の画面、部屋が作られると一覧が表示される -->
<div>
<header>
<h1 class="headline">
  <a>みんラジ!</a>
</h1>
 <ul class="nav-list">
      <li class="nav-list-item"><router-link to="/"><button id="back-home-button">ホーム</button></router-link></li>
      <li class="nav-list-item"><!-- 部屋を作成する画面に移動 --><router-link to="/room_create"><button id="create-room-button">ルームを作成する</button></router-link></li>
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
      <router-link to="/room_create"><button id="create-room-button">ルームを作成する</button></router-link>

    </section>
   
      <!-- 部屋情報を一つずつ取ってきて表示する、押すとそれぞれの画面に移動する -->
    <section>
      <!-- <calendar></calendar> -->
      <div class="main-contents">
      <h2>作成したルーム一覧</h2>
      <p>作成されたルーム一覧です。自分が作ったルームに入りましょう。</p>
      <div id='room' v-for="room in rooms" :key="room.id">
        <button id = "go-my-room-button" v-on:click="passCheck(room.id)">{{room.tilte}}</button>
        参加者 : {{room.numberofmember}} 名
        開始時刻 : {{room.reservedtime}}
      </div>
      <div id='overlay' v-show='showContent'>
        <input id="password-input" placeholder="ルームのパスワードを入力してください" size="20" type='text' value=""/>
        <button id = "password-send-button" v-on:click="passwordInput">送る</button>
        <br>
        <p><button v-on:click='closeModel' id = "password-close-button">閉じる</button></p>
        <br>
        <p id="errormessage"></p>
      </div>
      <div class="error">{{ this.error }}</div>
      </div>
    </section>

    <section>
      <h2>予定の確認</h2>
      <p>「カレンダーページ」ボタンを押すとカレンダーが表示されて、作成されたルームの確認ができます。</p>
      <router-link to="/calendar"><button id="go-calendar-button">カレンダーページ</button></router-link>
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
// import { updateRoom } from "../graphql/mutations";
import { updateUser } from "../graphql/mutations";
// import UserStore from '../mobx/UserStore'
import RoomMember from '../mobx/RoomMember'
import { Auth } from 'aws-amplify'
import { listUsers } from '../graphql/queries';
import { updateRoom } from '../graphql/mutations';

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
      password: "",
      passcheck: false,
      roomId: ""
      // subscription: {},
    }
  },
  methods :{
    async fetch(){
      //部屋データを取得
      RoomMember
      const roomlimit = 100  // 表示する部屋の数のmax
      const rooms = await API.graphql(graphqlOperation(listRooms,{limit:roomlimit}))
      this.rooms = rooms.data.listRooms.items
    },
    async gotoroom(){
      //ユーザー部屋入室情報追加
      const updateuserinput = {
        id: this.userId,
        username: this.userName,
        userRoomidId: this.roomId
      }
      await API.graphql(graphqlOperation(updateUser, { input: updateuserinput }))
        .catch(error => this.error = JSON.stringify(error))
      // 部屋の人数更新
      // const getroom = await API.graphql(graphqlOperation(getRoom,{id: this.roomId}))
      // const roommember = getroom.data.getRoom.numberofmember
      // const addroommenber = {
      //   id: this.roomId,
      //   numberofmember: roommember + 1
      // }
      // console.log(roommember)
      // await API.graphql(graphqlOperation(updateRoom, { input: addroommenber }))
      //   .catch(error => this.error = JSON.stringify(error))

      router.push('/room/in')
    },
    //パスワード関連
    passwordInput(){
      console.log(this.passcheck)
      let passwordinput = document.getElementById("password-input").value
      if(passwordinput === this.password){
        this.showContent = false
        this.gotoroom()
      }
      else{
        var erromessage = document.getElementById("errormessage")
        erromessage.innerHTML = "パスワードが違います"
      }
    },

    async passCheck(id){
      this.roomId = id
      const getroom = await API.graphql(graphqlOperation(getRoom,{id: this.roomId}))
      console.log(getroom.data.getRoom.privatepassword)
      if(getroom.data.getRoom.privatepassword){
        console.log('passcheck')
        this.password = getroom.data.getRoom.privatepassword
        this.showContent = true
      }
      else{
        this.gotoroom()
      }
    },
    async inituserdata() {
      try{
        const user = await Auth.currentAuthenticatedUser()
        this.userName = user.username
      } catch (err) {
        console.log('error getting user data... ', err)
      }
      console.log('username:',this.userName)
      if(this.userName !== ''){
        const userdata =  await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: this.userName}}}))
        console.log(userdata.data.listUsers.items[0].id)
        this.userId = userdata.data.listUsers.items[0].id
      }
    },
    async init(){
    try{
      const roomlimit = 100  // 表示する部屋の数のmax
      const getroomlist = await API.graphql(graphqlOperation(listRooms,{limit:roomlimit}))
      this.rooms = getroomlist.data.listRooms.items
    } catch (err) {
      console.log('error getting room data... ', err)
    }
    for(var i=0;i < this.rooms.length;i++){
      console.log(this.rooms[i])
      var roomid = this.rooms[i].id
      this.upDateRoom(roomid)
    }
  },
  async upDateRoom(id){
    const getroom = await API.graphql(graphqlOperation(getRoom,{id: id}))
    const membernum = getroom.data.getRoom.users.items.length
    const updateroommenber = {
      id: id,
      numberofmember: membernum
    }
    console.log(updateroommenber)
    await API.graphql(graphqlOperation(updateRoom, { input: updateroommenber }))
      .catch(error => this.error = JSON.stringify(error))
  },
    closeModel: function(){
      this.showContent = false
    },
  },
  async created(){
    await this.inituserdata()
    await this.init()
    console.log(this.userName,this.userId)
    this.fetch()
  }
}
</script>

<style src="./chat.css" />
