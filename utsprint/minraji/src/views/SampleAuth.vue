<template>
<div>
<!--ログイン画面-->

  <header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
<ul class="nav-list">
      <li class="nav-list-item"><amplify-sign-out ></amplify-sign-out></li>
    </ul>	
</header>
<main>
  <section>
    <section>
      <h2>サインイン</h2>
    <p>ユーザー名とパスワードを入力してサインインしてください。もしログイン画面が表示されないなら、もう一度「サインアウト」ボタンを押してホームに戻り「ログインする」ボタンを押してください。</p>
    </section>
    <section>
      <div align=center>ログイン画面</div>
      <!--amplify-authenticatorはサインインしていると表示されない-->
     <div class="login-screen"><amplify-authenticator v-bind:authConfig="authConfig"></amplify-authenticator></div>
     </section>
  </section>

 
</main> 
</div>
</template>
<script>
export default {
  name: "login",
  data() {
    return {
      authConfig: {
        signUpConfig: {
          hiddenDefaults: ["phone_number"]
        }
      }
    };
  }
};
</script>
<style>
header {
  height: 120px;
  width: 100%;
  padding: 15px 0;
  /*background-color: #337079;*/
  background: #dfefff;

}

header .headline{
  /*background: #dfefff;
  box-shadow: 0px 0px 0px 5px #dfefff;
  border: dashed 1px #96c2fe;
  padding: 0.2em 0.5em;
  color: #454545;*/
  line-height: 100px;
  float: left;
  font-size: 50px;
  margin-left: 100px;
  color: #454545;

}
.nav-list {
    line-height: 100px;
    /*float: left;*/
    margin-left: 30px;
    list-style: none;
}
.nav-list-item {
  list-style: none;
  display: inline-block;
  margin: 0 20px;
}
div.login-screen {
  margin-top: 100px;
  text-align: center;
}
main {
  height: 1000px;
  width: 100%;
  padding: 15px 0;
  /*background-color: #337079;*/
  /*background: #dfefff;*/
}

footer{
    width: 100%;
    height: 100px;
    background-color: #174a5c;
    color: white;
    text-align: center;
}
</style>