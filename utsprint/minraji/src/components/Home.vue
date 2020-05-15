<template>
<div>
<header>
        <h1 class="headline">
            <a>みんラジ!</a>
        </h1>
</header>
    <router-link to="/chat"> chat page </router-link>
    <br>
    <router-link to="/room"> room page </router-link>
    <amplify-sign-out></amplify-sign-out>
    <footer>
     
    </footer>
  </div>
</template>

<script>

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