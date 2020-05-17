<template>
<div>
<header>
<!--this is sign out home screen-->
<h1 class="headline">
      <a>みんラジ!</a>
</h1>
    <ul class="nav-list">
      <li class="nav-list-item"><a href="#link2about">About</a></li>
      <li class="nav-list-item"><a href="#link2service">Service</a></li>
      <li class="nav-list-item"><a href="#link2how2use">How to use</a></li>
      <li class="nav-list-item"> <router-link to="/login" id="login-button">ログインする</router-link></li>
    </ul>	
</header>
<main>
<section>
<section>
<a name="link2about"><h2>About</h2></a>
<p>aboutの説明をする aabb</p>
</section>

<section>
<a name="link2service"><h2>Service</h2></a>
<p>serviceの説明をする aaaaa</p>
</section>

<section>
<a name="link2how2use"><h2>How to use</h2></a>
<p>how to useの説明をする aaa</p>
</section>
</section>
</main>
    
  </div>
</template>

<script>

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
    float: left;
    margin-left: 30px;
    list-style: none;
}
.nav-list-item {
  list-style: none;
  display: inline-block;
  margin: 0 20px;
}

#login-button {
  /*position: relative*/
  display: inline-block;
  padding: 0.15em 0.5em;
  text-decoration: none;
  color: #FFF;
  background: #fd9535;/*背景色*/
  border-bottom: solid 2px #d27d00;/*少し濃い目の色に*/
  border-radius: 4px;/*角の丸み*/
  box-shadow: inset 0 2px 0 rgba(255,255,255,0.2), 0 2px 2px rgba(0, 0, 0, 0.19);
  font-weight: bold;
  height:80px;
}

#logoin-button:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
}

main {
  height: 1000px;
  width: 100%;
  padding: 15px 0;
  /*background-color: #337079;*/
  /*background: #dfefff;*/
}

</style>