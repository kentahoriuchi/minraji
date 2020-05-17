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

    <router-link to="/chat" class="button"> chat page </router-link>
    <br>
    <router-link to="/room" class="button"> room page </router-link>
    <br>
    <!--<router-link to="/movie"> 動画ページ色々 </router-link>-->
     <footer>
    <ul class="footer-menu">
     <li>home ｜</li>
     <li>about ｜</li>
     <li>service ｜</li>
     <li>contact us</li>
    </ul>
    <p>© All rights reserved by minraji.</p>
     
    </footer>
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
.button {
  position: relative;
  display: inline-block;
  padding: 0.25em 0.5em;
  text-decoration: none;
  color: #FFF;
  background: #fd9535;/*背景色*/
  border-bottom: solid 2px #d27d00;/*少し濃い目の色に*/
  border-radius: 4px;/*角の丸み*/
  box-shadow: inset 0 2px 0 rgba(255,255,255,0.2), 0 2px 2px rgba(0, 0, 0, 0.19);
  font-weight: bold;
}

.button:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
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

footer{
    width: 100%;
    height: 100px;
    background-color: #174a5c;
    color: white;
    text-align: center;
}

ul.footer-menu li {
display: inline;
}


</style>