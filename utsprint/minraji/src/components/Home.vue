<template>
<div>
<header>

<!--this is sign in home screen-->

<h1 class="headline">
      <a>みんラジ!</a>
</h1>
    <ul class="nav-list">
      <li class="nav-list-item">
        <a>Home</a>
      </li>
      <li class="nav-list-item">About</li>
      <li class="nav-list-item"> <amplify-sign-out></amplify-sign-out></li>
    </ul>

	
</header>

<!--<router-link to="../views/SampleAuth">  ログイン</router-link>-->

    <router-link to="/chat"> chat page </router-link>
    <br>
    <router-link to="/room"> room page </router-link>
    <br>
    <!--<router-link to="/movie"> 動画ページ色々 </router-link>-->
  </div>
</template>

<script>

</script>

<style>
header {
  height: 100px;
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
    line-height: 400px;
    float: left;
    margin-left: 30px;
    list-style: none;
}
.nav-list-item {
  list-style: none;
  display: inline-block;
  margin: 30px;
}



</style>