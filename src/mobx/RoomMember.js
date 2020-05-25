import API, {  graphqlOperation } from '@aws-amplify/api';
import { updateRoom } from '../graphql/mutations';
import { listRooms } from '../graphql/queries';
import { getRoom } from '../graphql/queries';


class RoomMember{
  constructor(){
    this.init()
  }

  async init(){
    try{
      const roomlimit = 100  // 表示する部屋の数のmax
      const getroomlist = await API.graphql(graphqlOperation(listRooms,{limit:roomlimit}))
      this.rooms = getroomlist.data.listRooms.items
    } catch (err) {
      console.log('error getting room data... ', err)
    }
    for(var i=0;i < this.rooms.length;i++){
      console.log(this.rooms[i])
      var roomid = this.rooms[i].id
      this.upDateRoom(roomid)
    }
  }
  async upDateRoom(id){
    const getroom = await API.graphql(graphqlOperation(getRoom,{id: id}))
    const membernum = getroom.data.getRoom.users.items.length
    const updateroommenber = {
      id: id,
      numberofmember: membernum
    }
    console.log(updateroommenber)
    await API.graphql(graphqlOperation(updateRoom, { input: updateroommenber }))
      .catch(error => this.error = JSON.stringify(error))
  }
}

export default new RoomMember()