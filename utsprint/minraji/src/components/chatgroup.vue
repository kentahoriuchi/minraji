<template>
<div>
<header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
</header>

<main>
  <div class="main-contents">
    <div class="message_base">
        <div v-for="message in messages" :key="message.id">
          <div v-bind:class="[message.username === userName ? 'message' : 'message_opponent']">{{message.content}}</div>
          <div v-bind:class="[message.username === userName ? 'username' : 'username_opponent']">{{message.username}}</div>
        </div>
    </div>
    <!-- <el-input placeholder="メッセージを入力(Enterで送信)" v-model="content" @keydown.enter.native="sendMessage"></el-input> -->
    <input id="messageinput" placeholder="メッセージを入力してください" size="30" type='text' value=""/>
    <button id = "sendMessage" v-on:click="sendMessage">send</button>
    <router-link to='/room/in' id="chatgroup">test</router-link>
    <div class="error">{{ this.error }}</div>
  </div>


  </main>

  
</div>  
</template>

<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import { createMessage } from "../graphql/mutations";
import { getRoom } from '../graphql/queries';
import { getUser } from '../graphql/queries';
import UserStore from '../mobx/UserStore';
// import { onCreateMessage } from '../graphql/subscriptions';

window.LOG_LEVEL = 'VERBOSE';
export default {
  data(){
    return{
      messages: [],
      roomId: "",
      userName: "",
      userId: "",
      error: "",
      subscription: {},
    }
  },
  methods :{
    async fetch(){
      const getroom = await API.graphql(graphqlOperation(getRoom,{id: this.roomId}))
      this.messages = getroom.data.getRoom.messages.items
      console.log(this.messages)
    },
    async sendMessage(){
      const message = document.getElementById("messageinput").value
      const createmessage = {
        id: new Date().getTime() + this.userName,
        username: this.userName,
        content: message,
        messageRoomidId: this.roomId
      }
      console.log(createmessage)
      await API.graphql(graphqlOperation(createMessage, { input: createmessage }))
        .catch(error => this.error = JSON.stringify(error))
    },
    // subscribe(){
    //   this.subscription = API.graphql(graphqlOperation(onCreateMessage)).subscribe({
    //     next: (eventData) => {
    //       const message = eventData.value.data.onCreateMessage;
    //       this.messages.push(message);
    //     }
    //   })
    // },
  },
  async created(){
    const { username,userid } = await UserStore
    this.userName = username
    this.userId = userid 
    const user_id = await API.graphql(graphqlOperation(getUser,{id: this.userId}))
    console.log(user_id.data.getUser.roomid.id)
    this.roomId = user_id.data.getUser.roomid.id
    this.fetch()
    // this.subscribe()
  },

}
</script>

<style src="./chat.css" />

