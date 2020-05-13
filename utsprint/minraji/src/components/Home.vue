<template>
<div>
<header>
        <h1 class="headline">
            <a>みんラジ!</a>
        </h1>
        <!--このコメントアウト消えるかも-->

        <iframe src="https://calendar.google.com/calendar/b/4/embed?height=300&amp;wkst=1&amp;bgcolor=%23ffffff&amp;ctz=Asia%2FTokyo&amp;src=amEuamFwYW5lc2UjaG9saWRheUBncm91cC52LmNhbGVuZGFyLmdvb2dsZS5jb20&amp;color=%230B8043&amp;showTitle=0" style="border:solid 1px #777" width="400" height="300" frameborder="0" scrolling="no"></iframe>
         <youtube :video-id="videoId" ref="youtube" @playing="playing"></youtube> 
         <button @click="playVideo">play</button>

    <button id="make-room" type=“button” onclick="location.href='https://www.youtube.com/watch?v=k2ThIEbisnY'">ルーム作成</button>
    <button id="enter-room" type=“button” onclick="location.href='https://www.youtube.com/watch?v=k2ThIEbisnY'">ルームに入る</button>
</header>
  
    <amplify-sign-out></amplify-sign-out>
    <footer>
     
    </footer>
  </div>
</template>

<script>
import Vue from 'vue'
import VueYoutube from 'vue-youtube'
Vue.use(VueYoutube)
export default {
  data() {
    return {
      videoId: 'k2ThIEbisnY'
    }
  },
  methods: {
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
  }
}
</script>

<style>
header {
  width: 100%;
  padding: 15px 0;
  margin: 0 auto;
  text-align: center;
}
header .headline{
  font-size: 100px;
  padding: 0.4em 0.5em;/*文字の上下 左右の余白*/
  color: #494949;/*文字色*/
  background: #f4f4f4;/*背景色*/
  border-left: solid 5px #7db4e6;/*左線*/
  border-bottom: solid 3px #d7d7d7;/*下線*/
}
#message_id {
  font-size: 100px;
}

#make-room {
  display: inline-block;
  padding: 0.5em 1em;
  text-decoration: none;
  border-radius: 3px;
  font-weight: bold;
  color: #FFF;
  background-image: linear-gradient(45deg, #709dff 0%, #b0c9ff 100%);
  transition: .4s;
  cursor: pointer; 
}

#make-room:hover {
  background-image: linear-gradient(45deg, #709dff 50%, #b0c9ff 100%);
}

#enter-room {
  display: inline-block;
  padding: 0.5em 1em;
  text-decoration: none;
  border-radius: 3px;
  font-weight: bold;
  color: #FFF;
  background-image: linear-gradient(45deg, #709dff 0%, #b0c9ff 100%);
  transition: .4s;
  cursor: pointer; 
}

#enter-room:hover {
  background-image: linear-gradient(45deg, #709dff 50%, #b0c9ff 100%);
}

.botton-pos{
  top:100px;
}

</style>