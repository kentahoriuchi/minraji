<template>
<div>
<header>
        <h1 class="headline">
            <a>みんラジ!</a>
        </h1>

        <iframe src="https://calendar.google.com/calendar/b/4/embed?height=300&amp;wkst=1&amp;bgcolor=%23ffffff&amp;ctz=Asia%2FTokyo&amp;src=amEuamFwYW5lc2UjaG9saWRheUBncm91cC52LmNhbGVuZGFyLmdvb2dsZS5jb20&amp;color=%230B8043&amp;showTitle=0" style="border:solid 1px #777" width="400" height="300" frameborder="0" scrolling="no"></iframe>
         <youtube :video-id="videoId" ref="youtube" @playing="playing"></youtube> 
         <button @click="playVideo">play</button>
    
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
      videoId: '4VEE01EFHFs'
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
}
#message_id {
  font-size: 100px;
};

</style>