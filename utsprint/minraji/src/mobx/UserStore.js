import API, {  graphqlOperation } from '@aws-amplify/api';
import { Auth } from 'aws-amplify'
import { listUsers } from '../graphql/queries';
import { createUser } from "../graphql/mutations";
// import { observable, decorate } from 'mobx'

class User {
  constructor(){
    this.username = ''
    this.userid = ''
    this.init()
  }

  async init() {
    try{
      const user = await Auth.currentAuthenticatedUser()
      this.username = user.username
    } catch (err) {
      console.log('error getting user data... ', err)
    }
    console.log('username:',this.username)
    if(this.username !== ''){
      this.checkIfUserExists(this.username)
    }
  }

  async checkIfUserExists(username) {
    const userdata =  await API.graphql(graphqlOperation(listUsers, { filter: {'username':{eq: username}}}))
    if (!userdata.data.listUsers.items.length){
      this.createUser()
    }
    else{
      this.userid = userdata.data.listUsers.items[0].id
    }
  }

  async createUser() {
    try{
      const newuser = {
        id: new Date().getTime() + this.userName,
        username: this.userName
      }
      API.graphql(graphqlOperation(createUser, { input: newuser }))
        .then(this.user.id = newuser.id)
        .catch(error => this.error = JSON.stringify(error))
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
