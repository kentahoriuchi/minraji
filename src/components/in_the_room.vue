<template>
<!-- 部屋の中の画面、へやのidによって画面が異なる -->
<div>
<header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
  <ul class="nav-list">

      <li class="nav-list-item"><router-link to="/"><button id="back-home-button">ホーム</button></router-link></li>
      <li class="nav-list-item"><!-- 待機部屋に移動 --><router-link to="/room"><button id="go-room-button">ルーム広場に戻る</button></router-link></li>
      <li class="nav-list-item"><amplify-sign-out></amplify-sign-out></li>
  </ul>	
</header>
<main>
<section>
    <h2>ルーム</h2>

    <p>ここはルームの中です。動画をみてラジオ体操をしましょう。
      ラジオ体操が終わったら「ルームを消す」ボタンを押して、ルーム広場に戻りましょう。</p>
    <div id="all-members">  
    <h2>参加者一覧</h2>
    参加者 : {{members.length}} 名
    <div  v-for="member in members" :key="member.id">
      {{member.username}}
    </div>
    </div>
   
    
    <!-- video-id youtubeの動画のid -->
    <!--<youtube :video-id="video_url" ref="youtube" @playing="playing"></youtube> -->
</section>
    
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
    
    
  <div id="two-buttons-up">
      <button v-on:click="playVideo" id="play-button">play</button>
  <button v-on:click="chat" id="chat-button">チャットする</button>
  </div>

  <div id="two-buttons-down">
  <!-- ルームを消す--><button id="delete-room-button" v-on:click="delete_room">ルームを消す</button>
    <router-link to="/room"><button id="go-room-button">ルーム広場に戻る</button></router-link>
  </div>


  <div id='overlay' v-show='showContent'>
    <div id="main-contents">
    <div v-for="message in messages" :key="message.id">
    <div id="message_base">
    <div v-bind:class="[message.username === userName ? 'message' : 'message_opponent']">{{message.content}}</div>
    <div v-bind:class="[message.username === userName ? 'username' : 'username_opponent']">{{message.username}}</div>
    </div>
    </div>
  </div>
  <table>
  <tr>
  <div>
  <input id="messageinput" placeholder="メッセージを入力してください" size="25" type='text' value=""/>
  </div>
  </tr>
  <tr>
  <div>
  <button id = "sendMessage" v-on:click="sendMessage">送る</button>
  <button id="chat-close" v-on:click='closeModel'>閉じる</button>
  </div>
  </tr>
  </table>
</div>
    
    


</section>
</main>
</div>
</template>

<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import Vue from 'vue'
import VueYoutube, {getIdFromUrl} from 'vue-youtube'
import { getRoom } from '../graphql/queries';
import { getUser } from '../graphql/queries';
import { deleteRoom } from '../graphql/mutations'
import router from '../router/router'
// import UserStore from '../mobx/UserStore'
import { updateUser } from "../graphql/mutations";
// import { updateRoom } from "../graphql/mutations";
import { createMessage } from "../graphql/mutations";
import { onCreateMessage } from '../graphql/subscriptions';
import { onUpdateRoom } from '../graphql/subscriptions';
import { Auth } from 'aws-amplify'
import { listUsers } from '../graphql/queries';
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
      subscriptionchat: {},
      subscriptionmem: {},
      error: "",
      roomId: "",
      members: [],
      userName: "",
      userId: "",
      showContent: false,
      messages: [],
      createdTime: "",
      nowTime: ""
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
      await this.checkTime()
    },
    sendSeek(seconds) {
      this.player.seekTo(seconds)

    },
    chat(){
      this.showContent = true
    },
    async sendMessage(){
      var message = document.getElementById("messageinput")
      if(!message.value){return}
      const createmessage = {
        id: new Date().getTime() + this.userName,
        username: this.userName,
        content: message.value,
        messageRoomidId: this.roomId
      }
      message.value = ""
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
    subscribe(){
      // GraphQLエンドポイントにsubscriptionを発行し、mutationを監視する
      this.subscriptionchat = API.graphql(graphqlOperation(onCreateMessage)).subscribe({
        next: (eventData) => {
          const message = eventData.value.data.onCreateMessage;
          console.log(message.roomid)
          if(message.roomid.id === this.roomId){
            this.messages.push(message);
          }
        }
      }),
      this.subscriptionmem = API.graphql(graphqlOperation(onUpdateRoom)).subscribe({
        next: (eventData) => {
          const member = eventData.value.data.onUpdateRoom;
          console.log(member.users.items)
          if(member.id === this.roomId){
            this.members = member.users.items
          }
        }
      })
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
    closeModel: function(){
      this.showContent = false
    },
    initializedate(){
      var today = new Date();
      today.setDate(today.getDate());
      var yyyy = today.getFullYear();
      var mm = ("0"+(today.getMonth()+1)).slice(-2);
      var dd = ("0"+today.getDate()).slice(-2);
      var hh = ("0"+(today.getHours())).slice(-2);
      var min = ("0"+(today.getMinutes())).slice(-2);
      var sec = ("0"+(today.getSeconds())).slice(-2);
      this.nowTime = yyyy+'-'+mm+'-'+dd +" "+ hh+':'+min+':'+sec;
    },
    checkTime(){
      this.initializedate()
      const wordsCreated = this.createdTime.split(' ');
      const wordsNow = this.nowTime.split(' ');
      console.log( wordsCreated[0])
      console.log( wordsNow[0])
      if(wordsCreated[0].match(wordsNow[0]) != /(\d{4})-(\d{2})-(\d{2})/){
        console.log("day matched!")
        const timeCreated = wordsCreated[1].split(':')
        const timeNow = wordsNow[1].split(':')
        const timeFromStart = (timeNow[0] - timeCreated[0])*3600 + (timeNow[1] - timeCreated[1])*60 + (timeNow[2] - timeCreated[2])
        console.log(timeFromStart)
        // console.log("time is far! moving now")
        if(timeFromStart < 0){
          this.player.pauseVideo()
          console.log('waiting')
          setTimeout(this.player.playVideo(),Math.abs(timeFromStart*1000))
        }else{
          this.sendSeek(timeFromStart)  
        }
        
      }
    }
  },
  computed: {
    player() {
      return this.$refs.youtube.player
    },

  },
  async created(){
    await this.inituserdata()
    const user_id = await API.graphql(graphqlOperation(getUser,{id: this.userId}))
    console.log(user_id.data.getUser.roomid)
    const room_info = user_id.data.getUser.roomid
    this.video_url = getIdFromUrl(room_info.movie)
    this.roomId = room_info.id
    this.createdTime = room_info.reservedtime
    const member = await API.graphql(graphqlOperation(getRoom,{id: this.roomId}))
    this.members = member.data.getRoom.users.items
    console.log(this.members.length)
    // console.log(this.video_url)
    console.log("created: " + this.createdTime)
    console.log("now: " + this.nowTime)
    this.fetch()
    this.subscribe()
    //this.createdTime = get_created_time(userid)
  },
  beforeDestroy() {
      //チャット画面から離れる際に、UnSubscribeする
      this.subscriptionchat.unsubscribe();
      this.subscriptionmem.unsubscribe();
    },
  async destroyed(){
    const updatedata = {
        id: this.userId,
        userRoomidId: null
      }
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

<style src="./chat.css" />


