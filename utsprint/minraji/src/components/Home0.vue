<template>
<div>
<header>
        <h1 class="headline">
            <a>みんラジ!</a>
        </h1>
</header>
  
    <p id ="message_id" v-html="message"><p>
    <p>
      ここはホーム画面です。aaaaaaa
    </p>
    <amplify-sign-out></amplify-sign-out>
    <footer>
     
    </footer>
  </div>
</template>

<script>
export default {
  data: function() {
    return {
      message: '吾輩は猫である。<br>名前はまだない。'
    }
  }
}
</script>

<style>
header {
  width: 100%;
  padding: 15px 0;
  margin: 0 auto;
  text-align: center;
}
header .headline{
  font-size: 100px;
}
#message_id {
  font-size: 100px;
};

</style>