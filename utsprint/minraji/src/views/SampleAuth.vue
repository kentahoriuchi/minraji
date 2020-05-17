<template>
<div>
<!--ログイン画面-->
<header>
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
</header>

  
  <a id="login-screen"><amplify-authenticator v-bind:authConfig="authConfig"></amplify-authenticator></a>

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

header .headline-login{
  /*background: #dfefff;
  box-shadow: 0px 0px 0px 5px #dfefff;
  border: dashed 1px #96c2fe;
  padding: 0.2em 0.5em;
  color: #454545;*/
  line-height: 100px;
  float: left;
  font-size: 100px;
  margin-left: 100px;
  color: #454545;

}
#login-screen {
  margin-top: 100px;
  text-align: left;
}
</style>