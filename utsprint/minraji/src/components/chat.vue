<template>
<div>
  <div class="title">
    <h2>Amplifyで作るチャットアプリ</h2>
  </div>
  <div class="main-contents">
    <div class="message_base">
        <div v-for="message in messages" :key="message.id">
          <div v-bind:class="[message.username === userName ? 'message' : 'message_opponent']">{{message.content}}</div>
          <div v-bind:class="[message.username === userName ? 'username' : 'username_opponent']">{{message.username}}</div>
        </div>
    </div>
    <el-input placeholder="メッセージを入力(Enterで送信)" v-model="content" @keydown.enter.native="sendMessage"></el-input>
    <div class="error">{{ this.error }}</div>
  </div>
</div>
</template>

<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import { Auth } from 'aws-amplify'
import { createMessage } from "../graphql/mutations";
import { listMessages } from '../graphql/queries';
import { onCreateMessage } from '../graphql/subscriptions';
window.LOG_LEVEL = 'VERBOSE';
export default {
  name: 'chat',
  data(){
    return {
      messages: [],
      content: "",
      userName: "",
      subscription: {},
      error: ""
    }
  },
  methods :{
    sendMessage(){
      // TODO(1) GraphQLエンドポイントにMutationを発行し、メッセージを登録する
    },
    fetch(){
      // TODO(2) GraphQLエンドポイントにQueryを発行し、メッセージ一覧を取得する
    },
    subscribe(){
      // TODO(3-1) GraphQLエンドポイントにSubscriptionを発行し、mutationを監視する
    },
    scrollBottom() {
      const container = this.$el.querySelector(".message_base");
      container.scrollTop = container.scrollHeight;
    }
  },
  async created(){
    this.userName = (await Auth.currentAuthenticatedUser()).username;
    this.fetch()
    this.subscribe()
  },
  beforeDestroy() {
    // TODO(3-2) チャット画面から離れる際に、UnSubscribeする
  },
  updated: function () {
    this.scrollBottom()
  }
}
</script>

