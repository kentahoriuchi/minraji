<template>
  <div>
  ここはフルコメントアウトです。
    <p>
      <input placeholder="URLを入力" v-model="videoUrl">
    </p>
    <youtube :video-id="videoId" ref="youtube" @playing="playing"></youtube> 
    <p>
      Original URL  : "{{videoUrl}}"
      generated ID  : "{{videoId}}"
      <!--
      player status : "{{playerState}}"
      play time     : " {{currentTime}}"  
      -->
    </p>
    <button @click="playVideo">play</button>
    <p>
      <input placeholder="飛ばしたい時間を入力(Enterで送信)" v-model="seconds" @keydown.enter.native="sendSeek">
    </p>
  </div>
</template>

<script>
import Vue from 'vue'
import VueYoutube from 'vue-youtube'
import API, {  graphqlOperation } from '@aws-amplify/api';
import { Auth } from 'aws-amplify'
import { createMessage } from "../graphql/mutations";
import { listMessages } from '../graphql/queries';
import { onCreateMessage } from '../graphql/subscriptions';

window.LOG_LEVEL = 'VERBOSE';

Vue.use(VueYoutube)

export default {
  data() {
    return {
      videoUrl: 'https://www.youtube.com/watch?v=JyMPBn25wP4',
      seconds: "",
      messages: [],
      content: "",
      userName: "",
      subscription: {},
      error: ""
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
    },
    sendMessage(){
      // TODO(1) GraphQLエンドポイントにMutationを発行し、メッセージを登録する
      if (event.keyCode !== 13) return // Enterキーの場合のみ送信処理を行う
      const message = { 
          id: new Date().getTime() + this.userName,
          username: this.userName,
          content: this.content
      }
      // Mutationの実行
      API.graphql(graphqlOperation(createMessage, { input: message }))
        .catch(error => this.error = JSON.stringify(error))
      this.content = ""
      console.log('mut')
    },
    fetch(){
      // TODO(2) GraphQLエンドポイントにQueryを発行し、メッセージ一覧を取得する
      API.graphql(graphqlOperation(listMessages, { limit: 200 }))
      .then(messages => this.messages = messages.data.listMessages.items.sort((a,b) => a.id > b.id ? 1 : -1))
      .catch(error => this.error = JSON.stringify(error))
      console.log('query')
    },
    subscribe(){
      // TODO(3-1) GraphQLエンドポイントにSubscriptionを発行し、mutationを監視する
      this.subscription = API.graphql(graphqlOperation(onCreateMessage)).subscribe({
        next: (eventData) => {
          const message = eventData.value.data.onCreateMessage;
          this.messages.push(message);
          console.log('subs')
          console.log(this.messages)
          console.log(this.messages.content)
        }
      })
    }
  },
  async created(){
    this.userName = (await Auth.currentAuthenticatedUser()).username;
    this.fetch()
    this.subscribe()
  },
  beforeDestroy() {
    // TODO(3-2) チャット画面から離れる際に、UnSubscribeする
    this.subscription.unsubscribe();
  },
  computed: {
    player() {
      return this.$refs.youtube.player
    },
    videoId(){
      var array1 = this.videoUrl.match(/\?v=([^&]+)/)
      return array1[1]
    }/*,
    currentTime: function(){
      return this.$refs.youtube.player.getCurrentTime()
    },
    playerState(){
      return this.$refs.youtube.player.getPlayerState()
    } */
  }
}
</script>

<style src="./Movie.css" />