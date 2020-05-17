<template>
<div>
<header>

<!--this is sign in home screen-->

<h1 class="headline">
      <a>みんラジ!</a>
</h1>
    <ul class="nav-list">
      <li class="nav-list-item"><a href="#link2about">About</a></li>
      <li class="nav-list-item"><a href="#link2service">Service</a></li>
      <li class="nav-list-item"><a href="#link2how2use">How to use</a></li>
      <li class="nav-list-item"> <amplify-sign-out></amplify-sign-out></li>
    </ul>

	
</header>

<main>
<!--<router-link to="../views/SampleAuth">  ログイン</router-link>-->

    <!--<router-link to="/chat" class="button"> chat page </router-link>
    <br>-->
    <router-link to="/room" id="go-room-button-at-home">ルーム広場に行く</router-link>
    <br>
    <!--<router-link to="/movie"> 動画ページ色々 </router-link>-->
<section>
<section>
<a name="link2about" id="home_link2about"><h2>About</h2></a>
<p>このサイトは東京大学で行われている<a href="https://sites.google.com/g.ecc.u-tokyo.ac.jp/utokyo-project-sprint/" target="_blank">Utokyo Project Sprint</a>に参加しているサービスです。
新型コロナウイルスによって生じた困難をネットサービスで解決または改善を目的としているプロジェクトです。</p>
</section>

<section>
<a name="link2service" id="home_link2service"><h2>Service</h2></a>
<p>新型コロナウイルスの影響で、在宅勤務や休校などで多くの人が現在外出自粛を余儀無くされています。
この自粛期間で運動不足になっている人は多くいると思います。例えば、学生なら部活動やサークルに行くことができない、社会人ならスポーツジムに行くことができない、
プロスポーツ選手でさえ練習することができません。<br>
そこで私たちは、自宅で誰でも気軽に運動できるサービスを開発しようと考えました。自宅できる運動は筋トレなどさまざまあると思いますが、私たちは老若男女の誰もが知っているラジオ体操に焦点を当てました。<br>
多くの人は、学校の体育の授業で友達とラジオ体操を一緒にやった、または町内会で行われている朝の体操で町の人とラジオ体操を一緒にやった経験があると思います。
このようにラジオ体操は誰かと一緒にやる運動だと言えます。<br>
私たちはWeb上で他人とラジオ体操動画を共有して一緒にラジオ体操をするサービスを開発しました。
</p>
</section>

<section>
<a name="link2how2use" id="home_link2how2use"><h2>How to use</h2></a>
<p>how to useの説明をする aaa</p>
</section>
</section>

</main>
  </div>
</template>

<script>

export default {
  mounted() {
    const hash = this.$route.hash;
    if (hash && hash.match(/^#.+$/)) {
      this.$scrollTo(hash);
    }
  }
};
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

#go-room-button-at-home {
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

#gp-room-button-at-home:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
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
main {
  height: 1000px;
  width: 100%;
  padding: 15px 0;
  /*background-color: #337079;*/
  /*background: #dfefff;*/
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