<template>
  <div id="app">
    <p id="contents">
      <router-view/>
    </p>
    <footer>
    <ul class="footer-menu">
     <li><router-link to="/"> home</router-link> ｜</li>
     <li><router-link to="/"> about</router-link>｜</li>
     <li><router-link to="/"> service</router-link></li>
    </ul>
    <p>© All rights reserved by minraji.</p>
    </footer>
  </div>
  

</template>


<script>

</script>

<style>

#app {
  width: 80%;
  margin: 0 auto;
  /*border: blue 5px solid;*/
}
#contents {
    height:1500px;
    width: 100%;
  }
footer{
  width: 100%;
  height: 100px;
  background-color: #174a5c;
  color: white;
  text-align: center;
  /*position: fixed;
  bottom: 0;*/
}

ul.footer-menu li {
display: inline;
}


@media screen and (max-width: 1000px) {
  #app {
    height:400px;
    border-color: yellow;
  }
  #contents {
    height:3000px;
    width: 100%;
  }

  footer{
  width: 100%;
  height: 100px;
  background-color: #174a5c;
  color: white;
  text-align: center;
  /*position: fixed;
  bottom: 0;*/
}

ul.footer-menu li {
display: inline;
}
}

@media screen and (max-width: 700px) {
  #app {
    height:2000px;
    width:100%;
    border-color: red;
  }
  #contents {
    height:2200px;
    width: 100%;
  }

  footer{
  width: 50%;
  height: 100px;
  background-color: #174a5c;
  color: white;
  text-align: center;
  /*position: fixed;
  bottom: 0;*/
}

ul.footer-menu li {
display: inline;
}
  
  
}
</style>