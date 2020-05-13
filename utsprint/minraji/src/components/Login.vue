<template>
aaaaaa
  <div>
      <div class="login" ><amplify-authenticator></amplify-authenticator></div>

      aaaaaa aaaaaaaaaaaaaaaaaa
  </div>
</template>

<script>
export default {
  data: function(){
    return{
      authConfig: {
        signUpConfig: {
          defaultCountryCode: "44",
          hiddenDefaults: ['phone_number']
        }
      }
    }
  
}

</script>

<style>
div.login {
    margin-top: 50px;
    text-align: center;
}

</style>