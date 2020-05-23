<template>
  <div>
<header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
<div>
    <ul class="nav-list">
      <li class="nav-list-item"><router-link to="/"><button id="back-home-button">ホーム</button></router-link></li>
      <li class="nav-list-item" v-if="signedIn"><router-link to="/room"><button id="go-room-button">ルーム広場に行く</button></router-link></li>
      <li class="nav-list-item"  v-if="signedIn"><amplify-sign-out></amplify-sign-out></li>
      <li class="nav-list-item"  v-if="!signedIn"> <router-link to="/login"><button id="login-button">ログインする</button></router-link></li>
    </ul>
</div>
</header>
<main>
    <section>
<a name="link2how2use" id="home_link2how2use"><h2>How to use</h2></a>
<h3>1. 新規会員登録</h3>
<p>まず「ログインする」ボタンを押しましょう。そうすればログインページに移動します。
  ログイン画面の「新規登録」を押してください。メールアドレスが必要です。
</p>
<h3>2. ログイン</h3>
<p>新規登録が済んだ方もしくはすでに登録した方は、
「ログインする」ボタンを押してログイン画面に登録したユーザー名とパスワードを入力してログインしましょう。</p>
<h3>3. ルーム広場に行く</h3>
<p>「ルーム広場に行く」ボタンを押しましょう。ルーム広場はラジオ体操する前の待機場所です。</p>
<h3>4. ルームを作成する</h3>
<p>ルーム広場にある「ルームを作成する」ボタンを押しましょう。ルームを作成するページに飛びます。
自分の好きな体操の動画のURLを入力してください。</p>
<h3>5. 作成したルームにいく</h3>
<p>ルームを作成したら、「ルーム広場に戻る」ボタンを押してください。
ルーム一覧にある自分が作成したルームのボタンを押してください。ルームに移動できます。</p>
<h3>6. ラジオ体操</h3>
<p>人と一緒に動画をみてラジオ体操をしましょう。終わったらルームから出ましょう。
  ラジオ体操が終わったら「ルーム広場に戻る」ボタンを押してルーム広場に戻りましょう。
</p>
<p>
  <img src="../image/computer_school_girl.png" id="computer_school_girl" alt="ラジオ体操" width=20%>
  <img src="../image/radio_taisou.png" id="radio_taiso" alt="ラジオ体操" width=20%>
</p>
</section>
</main>

  </div>
</template>

<script>
import { Auth } from 'aws-amplify'
import { AmplifyEventBus } from 'aws-amplify-vue'

window.LOG_LEVEL = 'VERBOSE';

export default {
  name: 'home',
  data(){
    return {
      signedIn: false,
      username: ''
    }
  },
  async beforeCreate() {
    // Auth.currentAuthenticatedUser()でユーザ情報を取得する。
    // 取得できなければ認証ステータスをfalseに設定する
    try {
      let cognitoUser = await Auth.currentAuthenticatedUser()
      this.signedIn = true
      this.username = cognitoUser.username
    } catch (err) {
      this.signedIn = false
    }
    // 認証ステータスが変わった時に呼び出されるイベントを登録
    AmplifyEventBus.$on('authState', async  info => {
      if (info === 'signedIn') {
        let cognitoUser = await Auth.currentAuthenticatedUser()
        this.signedIn = true
        this.username = cognitoUser.username
      } else {
        this.signedIn = false
      }
    });
  }
};


</script>

<style src="./chat.css" />





