<template>
<!-- 部屋の中の画面、へやのidによって画面が異なる -->
<div>
  <div class="title">
    <h2>ルームの中の画面</h2>
    <!-- video-id youtubeの動画のid -->
    <youtube :video-id="video_url" ref="youtube" 
      :player-vars="playerVars"
      @playing="playing" 
      @cued="cued" 
      @ready="ready" 
      @ended="ended" 
      @paused="paused"
      @buffering="buffering">
    </youtube> 
    <button @click="playVideo">play</button>
    <foryoutube :player-vars="playerVars"></foryoutube>
  </div>

  <footer>
    <!-- 待機部屋に移動 -->
    <router-link to="/room"> room page </router-link>
    <br>
    <button v-on:click="delete_room">delete room</button>
  </footer>
</div>
</template>

<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import { Auth } from 'aws-amplify'
import { listUsers } from '../graphql/queries';
import Vue from 'vue'
import VueYoutube from 'vue-youtube'
//import { deleteRoom, updateRoom } from '../graphql/mutations'
import { deleteRoom } from '../graphql/mutations'
import router from '../router/router'
import foryoutube from './foryoutube'

Vue.use(VueYoutube)

export default {
  name: 'room',
  components: {
    foryoutube
  },
  data(){
    return {
      video_url: "",
      subscription: {},
      error: "",
      roomid: "",
      createdTime: 1589620500,
      playerVars: {
        autoplay: 0
      }
      // videoId: '7bIBZ6M0-tU'
    }
  },
  methods :{
    playVideo() {
      // await this.player.playVideo()
      // await this.player.seekTo(10,true)
      this.sendSeek("10")
      // Do something after the playVideo command
      // this.player.seekTo(10)
    },
    ready() {
      console.log("Now we are ready for stream!!!")
      //this.player.addEventListener(this.player.onStateChange, )
      console.log(this.player.getPlayerState())
      // this.player.seekTo(Math.floor(new Date().getTime()/1000) - this.createdTime)
      // this.playVideo()
    },
    playing() {
      console.log('we are watching!!!')
      console.log(this.player.getPlayerState())
      // this.player.seekTo(10)
    },
    cued() {
      console.log('cued')
      console.log(this.player.getPlayerState())
    },
    ended() {
      console.log('ended')
      console.log(this.player.getPlayerState())
    },
    paused() {
      console.log('paused')
      console.log(this.player.getPlayerState())
    },
    buffering() {
      console.log('buffering')
      console.log(this.player.getPlayerState())
    },
    sendSeek(seconds) {
      this.player.seekTo(seconds)
    },
    delete_room(){
      const roomi = {
        id: this.roomid
      }
      console.log(roomi)
      API.graphql(graphqlOperation(deleteRoom, { input: roomi}))
        .catch(error => this.error = JSON.stringify(error))
      router.push({name:'room'})
    }
  },
  computed: {
    player() {
      return this.$refs.youtube.player
    },

  },
  async created(){
    this.userName = (await Auth.currentAuthenticatedUser()).username;
    const userid = await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: this.userName}}}))
    this.video_url = userid.data.listUsers.items[0].roomid.movie
    this.roomid = userid.data.listUsers.items[0].roomid.id
    console.log(this.video_url)
    //this.createdTime = get_created_time(userid)
  },
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