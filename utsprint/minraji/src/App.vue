<template>
  <div id="app">
 
    <p>
      <router-view/>
    </p>

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