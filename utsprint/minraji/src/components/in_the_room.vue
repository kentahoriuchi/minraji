<template>
<!-- 部屋の中の画面、へやのidによって画面が異なる -->
<div>
<header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
  <ul class="nav-list">
      <li class="nav-list-item"><router-link to="/" id="back-home-button"> ホーム</router-link></li>
      <li class="nav-list-item"><!-- 待機部屋に移動 --><router-link to="/room" id="back-room-button-header">ルーム広場に戻る</router-link></li>
      <li class="nav-list-item"><amplify-sign-out></amplify-sign-out></li>
  </ul>	
</header>
<main>
<section>
    <h2>ルーム</h2>

    <p>ここはルームの中です。動画をみてラジオ体操をしましょう。</p>
    参加者 : {{members.length}} 名
    <div  v-for="member in members" :key="member.id">
      {{member.username}}
    </div>
    
    <!-- video-id youtubeの動画のid -->
    <!--<youtube :video-id="video_url" ref="youtube" @playing="playing"></youtube> -->
</section>
<div id='overlay' v-show='showContent'>
  <div v-for="message in messages" :key="message.id">
    <p v-bind:class="[message.username === userName ? 'message' : 'message_opponent']">{{message.content}}</p>
    <p v-bind:class="[message.username === userName ? 'username' : 'username_opponent']">{{message.username}}</p>
  </div>
  <input id="messageinput" placeholder="メッセージを入力してください" size="30" type='text' value=""/>
  <button id = "sendMessage" v-on:click="sendMessage">send</button>
  <p><button v-on:click='closeModel'>close</button></p>
</div>
    
  <!-- ルームを消す-->
  <button v-on:click="delete_room">ルームを消す</button>
<section>   
    <!-- video-id youtubeの動画のid -->
    <div align="center"><youtube :video-id="video_url" ref="youtube" 
      @playing="playing" 
      @cued="cued" 
      @ready="ready" 
      @ended="ended" 
      @paused="paused"
      @buffering="buffering">
    </youtube>
    </div>
    <br>
    <button v-on:click="playVideo" id="play-button">play</button>
    <!-- <foryoutube :videoId='JyMPBn25wP4'></foryoutube> -->
    <br>
    <button v-on:click="chat" id="button">chatroom</button>
    <router-link to="/room" id="back-room-button">ルーム広場に戻る</router-link>


</section>
</main>
</div>
</template>

<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import Vue from 'vue'
import VueYoutube from 'vue-youtube'
import { getRoom } from '../graphql/queries';
import { getUser } from '../graphql/queries';
import { deleteRoom } from '../graphql/mutations'
import router from '../router/router'
import UserStore from '../mobx/UserStore'
import { updateUser } from "../graphql/mutations";
import { updateRoom } from "../graphql/mutations";
import { createMessage } from "../graphql/mutations";
// import foryoutube from './foryoutube'

Vue.use(VueYoutube)

export default {
  name: 'room',
  // components: {
  //   foryoutube
  // },
  data(){
    return {
      video_url: "",
      subscription: {},
      error: "",
      roomId: "",
      createdTime: 1589620500,
      members: [],
      userName: "",
      userId: "",
      showContent: false,
      messages: [],
      // playerVars: {
      //   autoplay: 0
      // }
      // videoId: '7bIBZ6M0-tU'
    }
  },
  methods :{
    async fetch(){
      const getroom = await API.graphql(graphqlOperation(getRoom,{id: this.roomId}))
      this.messages = getroom.data.getRoom.messages.items
      console.log(this.messages)
    },
    async playVideo() {
      // await this.player.seekTo(10,true)
      await this.sendSeek(30)
      this.player.playVideo()
      console.log(await this.player.getPlayerState())
      // Do something after the playVideo command
      // this.player.seekTo(10)
    },
    async ready() {
      console.log("Now we are ready for stream!!!")
      //this.player.addEventListener(this.player.onStateChange, )
      console.log(await this.player.getPlayerState())
      this.sendSeek(30)
      // this.player.seekTo(Math.floor(new Date().getTime()/1000) - this.createdTime)
      // this.playVideo()
    },
    async playing() {
      // await this.sendSeek(30)
      console.log('we are watching!!!')
      console.log(this.player.getPlayerState())
      // this.player.seekTo(10)
    },
    async cued() {
      console.log('cued')
      console.log(await this.player.getPlayerState())

    },
    ended() {
      console.log('ended')
      console.log(this.player.getPlayerState())
    },
    paused() {
      console.log('paused')
      console.log(this.player.getPlayerState())
    },
    async buffering() {
      console.log('buffering')
      console.log(this.player.getPlayerState())
      setTimeout(console.log('7777777'),5000)
      await this.sendSeek(30)
    },
    sendSeek(seconds) {
      this.player.seekTo(seconds)

    },
    chat(){
      this.showContent = true
    },
    async sendMessage(){
      const message = document.getElementById("messageinput").value
      const createmessage = {
        id: new Date().getTime() + this.userName,
        username: this.userName,
        content: message,
        messageRoomidId: this.roomId
      }
      console.log(createmessage)
      await API.graphql(graphqlOperation(createMessage, { input: createmessage }))
        .catch(error => this.error = JSON.stringify(error))
    },
    async delete_room(){
      const roomi = {
        id: this.roomId
      }
      console.log(roomi)
      await API.graphql(graphqlOperation(deleteRoom, { input: roomi}))
        .catch(error => this.error = JSON.stringify(error))
      router.push({name:'room'})
    },
    closeModel: function(){
      this.showContent = false
    },
  },
  computed: {
    player() {
      return this.$refs.youtube.player
    },

  },
  async created(){
    const { username,userid } = await UserStore
    console.log(UserStore)
    this.userName = username
    this.userId = userid 
    const user_id = await API.graphql(graphqlOperation(getUser,{id: this.userId}))
    console.log(user_id.data.getUser.roomid)
    const room_info = user_id.data.getUser.roomid
    this.video_url = room_info.movie
    this.roomId = room_info.id
    const member = await API.graphql(graphqlOperation(getRoom,{id: this.roomId}))
    this.members = member.data.getRoom.users.items
    console.log(this.members)
    console.log(this.video_url)
    this.fetch()
    //this.createdTime = get_created_time(userid)
  },
  async destroyed(){
    const updatedata = {
        id: this.userId,
        userRoomidId: null
      }
    const roominfo = await API.graphql(graphqlOperation(getRoom,{id: this.roomId}))
    const roommember = roominfo.data.getRoom.numberofmember
    const addroommenber = {
      id: this.roomId,
      numberofmember: roommember - 1
    }
    await API.graphql(graphqlOperation(updateRoom, { input: addroommenber }))
      .catch(error => this.error = JSON.stringify(error))
    await API.graphql(graphqlOperation(updateUser, { input: updatedata }))
      .catch(error => this.error = JSON.stringify(error))
  }
}

/*
function get_created_time(userid){
  if (userid.data.listUsers.items[0].roomid.time !== /\d{10}/g) {
    const room ={
      id: userid.data.listUsers.items[0].roomid.id,
      time: Math.floor(new Date().getTime()/1000)
    }
    console.log("time is NOT set in this room. The time is " + room.time + " now and was set.")
    console.log("room is " + room.id)
    API.graphql(graphqlOperation(updateRoom, { input: room}))
    .then(console.log("set successfully!"))
    .catch(error => this.error = JSON.stringify(error))
    return new room.time
  }
  else{
    console.log("time is set in this room. the time is " + userid.data.listUsers.items[0].roomid.time)
    return userid.data.listUsers.items[0].roomid.time
  }
}
*/
//function sendSeek(seconds) {
  // this.player.seekTo(this.seconds)
//}

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
  /*float: left;*/
  font-size: 50px;
  margin-left: 100px;
  color: #454545;
}

#back-home-button {
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
  left: 600px;
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


#play-button {
  font-size: 1.4em;
  position: relative;
  left: 400px;
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

#play-button:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
}
</style>


