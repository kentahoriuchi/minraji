<template>
  <!--ログイン画面を写している-->
  <a class="log-sc"><amplify-authenticator v-bind:authConfig="authConfig"></amplify-authenticator></a>
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
.log-sc {
    margin-top: 100px;
    text-align: center;
}

</style>