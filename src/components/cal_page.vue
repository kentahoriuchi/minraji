<template>
<!-- 待機部屋の画面、部屋が作られると一覧が表示される -->
<div>
<header>
<h1 class="headline">
  <a>みんラジ!</a>
</h1>
 <ul class="nav-list">
      <li class="nav-list-item"><router-link to="/" id="back-home-button"> ホーム</router-link></li>
      <li class="nav-list-item"><router-link to="/room" id="back-room-button-header">ルーム広場に行く</router-link></li>
      <li class="nav-list-item"> <amplify-sign-out></amplify-sign-out></li>
  </ul>	
  <!--<router-link
    :to="{
      name: '/', 
      hash: '#hashtag'
      }"
  >ルームを作成する</router-link>-->
</header>
<main>
  <section>
    
   
    
    <section>
      <calendar></calendar>
    </section>
      
    
  </section>
</main>

</div>
</template>


<script>
import API, {  graphqlOperation } from '@aws-amplify/api';
import { Auth } from 'aws-amplify'
import { createUser } from "../graphql/mutations";
import { updateUser } from "../graphql/mutations";
import { listRooms } from '../graphql/queries';
import { getRoom } from '../graphql/queries';
import { listUsers } from '../graphql/queries';
import router from '../router/router'
import calendar from "./calendar"

window.LOG_LEVEL = 'VERBOSE';
export default {
  name: 'chat',
  components: {
    calendar
  },
  data(){
    return {
      userName: "",
      members: [],
      // subscription: {},
      error: "",
      rooms: [],
      room_id: ""
    }
  },
  methods :{
    async fetch(){
      const room_temp = await API.graphql(graphqlOperation(listRooms,{limit:10}))
      this.rooms = room_temp.data.listRooms.items
      for(let i = 0; i < this.rooms.length; i++){
        let member = await API.graphql(graphqlOperation(getRoom,{id: this.rooms[i].id}))
        this.members.push(member.getRoom.users.items.length)
      }
      console.log(this.rooms)
    },
    async gotoroom(temp){
      //ユーザーの認証とかをやる
      const roomid = await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: this.userName}}}))
      const userroom = roomid.data.listUsers.items[0]
      console.log(userroom)
      // if (!userroom.roomid){
      console.log(document.getElementById("room").textContent)
      var room_a = await API.graphql(graphqlOperation(getRoom,{id: temp}))
      console.log(room_a.data.getRoom.users.items)
      this.members = room_a.data.getRoom.users.items
      var room = room_a.data.getRoom.users
      const userroomid = {
        id: userroom.id,
        username: this.userName,
        userRoomidId: room.id
      }
      console.log(userroomid)
      await API.graphql(graphqlOperation(updateUser, { input: userroomid }))
        .catch(error => this.error = JSON.stringify(error))
      // }
      // else{
      //   console.log('already room in')
      // }
      router.push('/room/in')
    }
  },
  async created(){
    this.userName = (await Auth.currentAuthenticatedUser()).username;
    var user = await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: this.userName}}}))
    console.log(user.data.listUsers.items.length)
    console.log(!user.data.listUsers.items.length)
    if (!user.data.listUsers.items.length){
      const newuser = {
        id: new Date().getTime() + this.userName,
        username: this.userName
      }
      API.graphql(graphqlOperation(createUser, { input: newuser }))
        .catch(error => this.error = JSON.stringify(error))
      console.log(newuser)
    }
    this.fetch()
  }
}
</script>

<style>

#back-home-button {
  font-size: 1.4em;
  position: relative;
  display: inline-block;
  padding: 0.25em 0.5em;
  text-decoration: none;
  color: #FFF;
  background: #4235fd;/*背景色*/
  border-bottom: solid 2px #d27d00;/*少し濃い目の色に*/
  border-radius: 4px;/*角の丸み*/
  box-shadow: inset 0 2px 0 rgba(255,255,255,0.2), 0 2px 2px rgba(0, 0, 0, 0.19);
  font-weight: bold;
}
  
#back-home-button:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
}

#back-room-button {
  font-size: 1.4em;
  position: relative;
  left: 600px;
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
