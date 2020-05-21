<template>
  <div id="app">
    <p>
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
footer{
  top: 3000px;
  width: 100%;
  height: 400px;
  background-color: #174a5c;
  color: white;
  text-align: center;
}

ul.footer-menu li {
display: inline;
}
</style>