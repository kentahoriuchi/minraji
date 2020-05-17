<template>
  <div>
  </div>
</template>

<script>

  const player = require('youtube-player')

  const UNSTARTED = -1
  const ENDED = 0
  const PLAYING = 1
  const PAUSED = 2
  const BUFFERING = 3
  const CUED = 5

  export default {
    name: 'foryoutube',
    props: {
      videoId: {
        type: String,
        default: "8CR32KdFD-c"
      },
      playerVars: {
        type: Object,
        default: () => ({})
      },
      height: {
        type: [Number, String],
        default: 360
      },
      width: {
        type: [Number, String],
        default: 640
      },
      resize: {
        type: Boolean,
        default: false
      },
      resizeDelay: {
        type: Number,
        default: 100
      },
      nocookie: {
        type: Boolean,
        default: false
      },
      fitParent: {
        type: Boolean,
        default: false
      }
    },
    data () {
      return {
        player: {},
        events: {
          [UNSTARTED]: 'unstarted',
          [PLAYING]: 'playing',
          [PAUSED]: 'paused',
          [ENDED]: 'ended',
          [BUFFERING]: 'buffering',
          [CUED]: 'cued'
        },
        resizeTimeout: null
      }
    },
    computed: {
      aspectRatio () {
        return this.width / this.height
      }
    },
    methods: {
      playerReady (e) {
        this.$emit('ready', e.target)
      },
      playerStateChange (e) {
        if (e.data !== null && e.data !== UNSTARTED) {
          this.$emit(this.events[e.data], e.target)
        }
        console.log("state changed! " + this.events[e.data])
      },
      playerError (e) {
        this.$emit('error', e.target)
      },
      async updatePlayer (videoId) {
        if (!videoId) {
          this.player.stopVideo()
          return
        }

        if (this.playerVars.autoplay === 1) {
          await this.player.loadVideoById( videoId, 5 )
          //.then(this.player.seek(10))
          return
        }

        this.player.cueVideoById({ 'videoId': videoId, 'startSeconds':"10.0"})
      },
      resizeProportionally () {
        this.player.getIframe().then(iframe => {
          const width = this.fitParent
            ? iframe.parentElement.offsetWidth
            : iframe.offsetWidth
          const height = width / this.aspectRatio
          this.player.setSize(width, height)
        })
      },
      onResize () {
        clearTimeout(this.resizeTimeout)
        this.resizeTimeout = setTimeout(
          this.resizeProportionally,
          this.resizeDelay
        )
      }
    },
    watch: {
      videoId: 'updatePlayer',
      resize (val) {
        if (val) {
          window.addEventListener('resize', this.onResize)
          this.resizeProportionally()
        } else {
          window.removeEventListener('resize', this.onResize)
          this.player.setSize(this.width, this.height)
        }
      },
      width (val) {
        this.player.setSize(val, this.height)
      },
      height (val) {
        this.player.setSize(this.width, val)
      }
    },
    beforeDestroy () {
      if (this.player !== null && this.player.destroy) {
        this.player.destroy()
        delete this.player
      }

      if (this.resize) {
        window.removeEventListener('resize', this.onResize)
      }
    },
    mounted () {
      window.YTConfig = {
        host: 'https://www.youtube.com/iframe_api'
      }
      
      const host = this.nocookie ? 'https://www.youtube-nocookie.com' : 'https://www.youtube.com'

      this.player = player(this.$el, {
        host,
        width: this.width,
        height: this.height,
        videoId: this.videoId,
        playerVars: this.playerVars
      })

      this.player.on('ready', this.playerReady)
      this.player.on('stateChange', this.playerStateChange)
      this.player.on('error', this.playerError)

      if (this.resize) {
        window.addEventListener('resize', this.onResize)
      }

      if (this.fitParent) {
        this.resizeProportionally()
      }
    },
    render (h) {
      return h('div')
    }
  }

  // // 2. This code loads the IFrame Player API code asynchronously.
  // var tag = document.createElement('script');

  // tag.src = "https://www.youtube.com/iframe_api";
  // var firstScriptTag = document.getElementsByTagName('script')[0];
  // firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

  // // 3. This function creates an <iframe> (and YouTube player)
  // //    after the API code downloads.
  // var player;
  // function onYouTubeIframeAPIReady() {
  //   player = new YT.Player('player', {
  //     height: '360',
  //     width: '640',
  //     videoId: 'M7lc1UVf-VE',
  //     events: {
  //       'onReady': onPlayerReady,
  //       'onStateChange': onPlayerStateChange
  //     }
  //   });
  // }

  // // 4. The API will call this function when the video player is ready.
  // function onPlayerReady(event) {
  //   event.target.playVideo();
  // }

  // // 5. The API calls this function when the player's state changes.
  // //    The function indicates that when playing a video (state=1),
  // //    the player should play for six seconds and then stop.
  // var done = false;
  // function onPlayerStateChange(event) {
  //   if (event.data == YT.PlayerState.PLAYING && !done) {
  //     setTimeout(stopVideo, 6000);
  //     done = true;
  //   }
  // }
  // function stopVideo() {
  //   player.stopVideo();
  // }
</script>