import API, {  graphqlOperation } from '@aws-amplify/api';
import { Auth } from 'aws-amplify'
import { listUsers } from '../graphql/queries';
import { createUser } from "../graphql/mutations";
// import { observable, decorate } from 'mobx'

class User {
  constructor(){
    this.userName = ''
    this.userid = ''
    this.init()
  }

  async init() {
    try{
      const user = await Auth.currentAuthenticatedUser()
      this.userName = user.username
    } catch (err) {
      console.log('error getting user data... ', err)
    }
    console.log('username:',this.userName)
    if(this.userName !== ''){
      this.checkIfUserExists(this.userName)
    }
  }

  async checkIfUserExists(username) {
    const userdata =  await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: username}}}))
    console.log(userdata.data.listUsers.items)
    if (!userdata.data.listUsers.items.length){
      this.createUser()
    }
    else{
      console.log('------------')
      this.userid = userdata.data.listUsers.items[0].id
    }
  }

  async createUser() {
    try{
      const newuser = {
        id: new Date().getTime() + this.userName,
        username: this.userName
      }
      await API.graphql(graphqlOperation(createUser, { input: newuser }))
      this.user.id = newuser.id
        
      console.log('newuser:',newuser)
    }
    catch(err){
      console.log('error creating user data... ', err)
    }
  }
}

// decorate(User, {
//   username: observable,
//   userid: observable
// });

export default new User()
