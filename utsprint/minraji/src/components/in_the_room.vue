<template>
<div>
  <div class="title">
    <h2>ルームの中の画面</h2>
    <youtube :video-id="video_url" ref="youtube" @playing="playing"></youtube> 
  </div>
  <footer>
    <router-link to="/room"> room page </router-link>
  </footer>
</div>
</template>

<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import { Auth } from 'aws-amplify'
import { listUsers } from '../graphql/queries';
import Vue from 'vue'
import VueYoutube from 'vue-youtube'

Vue.use(VueYoutube)

export default {

  name: 'room',
  data(){
    return {
      video_url: "",
      subscription: {},
      error: "",
      // videoId: '7bIBZ6M0-tU'
    }
  },
  methods :{
    playVideo() {
      this.player.playVideo()
    },
    playing() {
      console.log('we are watching!!!')
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
    console.log(this.video_url)
  },
}
</script>



