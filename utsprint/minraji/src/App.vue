<template>
  <div id="app">
    <p>
      <router-view/>
    </p>
    <p>
      <input type="text" v-model="videoId">
    </p>
    <youtube :video-id="videoId" ref="youtube" @playing="playing"></youtube> 
    <p>
      {{videoId}}
    </p>
    <button @click="playVideo">play</button>
    <p>
      <el-input placeholder="飛ばしたい時間を入力(Enterで送信)" v-model="seconds" @keydown.enter.native="sendSeek"></el-input>
    </p>
  </div>
</template>

<script>
import Vue from 'vue'
import VueYoutube from 'vue-youtube'

Vue.use(VueYoutube)

export default {
  data() {
    return {
      videoId: '4VEE01EFHFs',
      seconds: ""
    }
  },
  methods: {
    playVideo() {
      this.player.playVideo()
    },
    playing() {
      console.log('we are watching!!!')
    },
    sendSeek() {
      this.player.seekTo(this.seconds)
    }
  },
  computed: {
    player() {
      return this.$refs.youtube.player
    }
  }
}
</script>
