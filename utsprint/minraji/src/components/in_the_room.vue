<template>
<!-- 部屋の中の画面、へやのidによって画面が異なる -->
<div>
  <div class="title">
    <h2>ルームの中の画面</h2>

    <!-- video-id youtubeの動画のid -->
    <youtube :video-id="video_url" ref="youtube" @playing="playing"></youtube> 
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
import { deleteRoom } from '../graphql/mutations'
import router from '../router/router'

Vue.use(VueYoutube)

export default {

  name: 'room',
  data(){
    return {
      video_url: "",
      subscription: {},
      error: "",
      roomid: "",
      // videoId: '7bIBZ6M0-tU'
    }
  },
  methods :{
    playVideo() {
      this.player.playVideo()
    },
    playing() {
      console.log('we are watching!!!')
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
    }
  },
  async created(){
    this.userName = (await Auth.currentAuthenticatedUser()).username;
    const userid = await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: this.userName}}}))
    this.video_url = userid.data.listUsers.items[0].roomid.movie
    this.roomid = userid.data.listUsers.items[0].roomid.id
    console.log(this.video_url)
  },
}
</script>



