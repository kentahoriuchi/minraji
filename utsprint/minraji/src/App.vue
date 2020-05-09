<template>
  <div id="app">
    <p>
      <!-- <myheader></myheader> -->
      <router-view/>
    </p>
    <youtube :video-id="videoId" ref="youtube" @playing="playing"></youtube> 
    <button @click="playVideo">play</button>
    <!-- おっぱい　-->
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