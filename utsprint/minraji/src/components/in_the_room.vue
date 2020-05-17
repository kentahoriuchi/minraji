<template>
<!-- 部屋の中の画面、へやのidによって画面が異なる -->
<div>
<header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
<ul class="nav-list">
      <li class="nav-list-item"><a href="#link2about">About</a></li>
      <li class="nav-list-item"><a href="#link2service">Service</a></li>
      <li class="nav-list-item"><a href="#link2how2use">How to use</a></li>
      <li class="nav-list-item"> <amplify-sign-out></amplify-sign-out></li>
  </ul>	
</header>
<main>
<section>
    <h2>ルーム</h2>
    <p>ここはルームの中です。動画をみてラジオ体操をしましょう。</p>
    <!-- video-id youtubeの動画のid -->
    <!--<youtube :video-id="video_url" ref="youtube" @playing="playing"></youtube> -->
</section>
<section>
<youtube :video-id="video_url" ref="youtube" @playing="playing"></youtube>
</section>
    <!-- 待機部屋に移動 -->
    <router-link to="/room" id="back-room-button">ルーム広場に戻る</router-link>
 
</main>
  
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
  float: left;
  font-size: 50px;
  margin-left: 100px;
  color: #454545;

}

#back-room-button {
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

#back-room-button:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
}
</style>



