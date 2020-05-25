<template>
  <div>
      <a id="login"><amplify-authenticator v-bind:authConfig="authConfig"/></a>
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
}
</script>

<style>

</style>