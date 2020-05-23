<template>
<div id="page">
<header>

<!--this is sign in home screen-->

<h1 class="headline">
    <a>みんラジ!</a>
</h1>
<div v-if="signedIn">
    <ul class="nav-list">
      <li class="nav-list-item"><a href="#link2about">About</a></li>
      <li class="nav-list-item"><a href="#link2service">Service</a></li>
      <li class="nav-list-item"><router-link to="/use" ><button id="go-how-to-use-button">How to use</button></router-link></li>
      <li class="nav-list-item" ><router-link to="/room" ><button id="go-room-button">ルーム広場に行く</button></router-link></li>
      <!--<li class="nav-list-item"><router-link to="/cal_page" id="cal-room-button">予定を確認する</router-link></li>-->
      <li class="nav-list-item"><input type="button" name="buttonName" id="question-button" value="アンケート" onClick="window.open('https://docs.google.com/forms/d/e/1FAIpQLSeeWIQ5NyHNrhWfj9K_ZJS8sZ_wD0ZJTYCOpQr1qm9KkUDLBQ/viewform?usp=sf_link','_blank')" /></li>
      <li class="nav-list-item"><amplify-sign-out></amplify-sign-out></li>
    </ul>
</div>
<div v-if="!signedIn">
  
    <ul class="nav-list">
      <li class="nav-list-item"><a href="#link2about">About</a></li>
      <li class="nav-list-item"><a href="#link2service">Service</a></li>
      <li class="nav-list-item"><router-link to="/use"><button id="go-how-to-use-button">How to use</button></router-link></li>
      <li class="nav-list-item"> <router-link to="/login"><button id="login-button">ログイン</button></router-link></li>
    </ul>	

    <!--<nav class="menu">
  <ul>
    <li><a href="#link2about">About</a></li>
    <li><a href="#link2service">Service</a></li>
    <li><router-link to="/use"><button id="go-how-to-use-button">How to use</button></router-link></li>
    <li><router-link to="/login"><button id="login-button">ログイン</button></router-link></li>
  </ul>
</nav>-->

</div>
</header>
<main>
<!--<router-link to="../views/SampleAuth">  ログイン</router-link>-->

    <!--<router-link to="/chat" class="button"> chat page </router-link>
    <br>-->
    <!--<router-link to="/movie"> 動画表示用 </router-link>-->
    <!--<router-link to="/movie"> 動画ページ色々 </router-link>-->
<section>

<section>
<a name="link2about" id="home_link2about"><h2>About</h2></a>
<p>このサイトは東京大学で行われている<a href="https://sites.google.com/g.ecc.u-tokyo.ac.jp/utokyo-project-sprint/" target="_blank">Utokyo Project Sprint</a>に参加しているサービスです。
新型コロナウイルスによって生じた困難をネットサービスで解決または改善を目的としているプロジェクトです。
詳しいことは上記にあるサイトに書いてあるので参照してください。</p>
</section>

<section>
<a name="link2service"><h2>Service</h2></a>
<p>新型コロナウイルスの影響で、在宅勤務や休校などで多くの人が現在外出自粛を余儀無くされています。
この自粛期間で運動不足になっている人は多くいると思います。例えば、学生なら部活動やサークルに行くことができない、社会人ならスポーツジムに行くことができない、
プロスポーツ選手でさえ練習することができません。コロナ太りと検索すると記事がたくさん出てくるように多くの人が運動不足になっています。
肥満体になると、健康でなくなる、服のサイズが合わなくなるなど日常生活で様々な障害が発生します。
多くの人が運動不足を解消したいと思っているはずです。
また、これから夏に入ると暑くなり、肌の露出が多い服を着る機会が増えると思いますが、体がたるんでいては格好悪いでしょう。
しかし、新型コロナウイルスの感染が怖く、外に出て運動することは中々できないと思います。そこで、私たちは新型コロナウイルスの感染防止を考慮して在宅で運動不足を解消するために、自宅で誰でも気軽に運動できるサービスを開発しようと考えました。</p>
<p>自宅でできる運動は筋トレなどさまざまあると思いますが、
私たちはラジオ体操に焦点を当てました。
多くの人は、学校の体育の授業で友達とラジオ体操を一緒にやった、または町内会で行われている朝の体操で町の人とラジオ体操を一緒にやった経験があると思います。
老若男女の誰もが知っているかつ気軽にできるラジオ体操だからこそ、在宅で行うハードルは低いと思います。
</p>
<!--<div id="radio_taiso">
<img src="../image/radio_taisou.png" alt="ラジオ体操"  width=10%>
</div>-->
家の中でラジオ体操や筋トレをやろうと意気込んでも、三日坊主になり長続きするのは難しいです。これは1人でやっているため、他人の目や強制力がないことが原因だと言えます。
他人と一緒にやれば、あの子が続けているから私も頑張って続けようと思えるはずです。
誰かと一緒に時間を共有することが長続きの秘訣だと言えます。
私たちは、同じ動画を共有することで擬似的に他人と一緒に何かをしている感覚が生み出せるのではないかと考えました。<br>
<p>新型コロナウイルスの感染防止のために在宅、肥満解消のために運動をしたい、持続するために他人と時間を共有したいという課題を解決するために、
  私たちはweb上で他人とラジオ体操動画を共有して一緒に在宅でラジオ体操をするサービスを開発しました。
</p>
<p>
  サービスをお使い頂いたら、サービスの品質向上のためにアンケートにご協力ください。
</p>
<p>
  <input type="button" name="buttonName" id="question-button" value="アンケート" onClick="window.open('https://docs.google.com/forms/d/e/1FAIpQLSeeWIQ5NyHNrhWfj9K_ZJS8sZ_wD0ZJTYCOpQr1qm9KkUDLBQ/viewform?usp=sf_link','_blank')" />
</p>
</section>
</section>
</main>
</div>
</template>

<script>
import { Auth } from 'aws-amplify'
import { AmplifyEventBus } from 'aws-amplify-vue'

window.LOG_LEVEL = 'VERBOSE';

export default {
  name: 'home',
  data(){
    return {
      signedIn: false,
      username: ''
    }
  },
  async beforeCreate() {
    // Auth.currentAuthenticatedUser()でユーザ情報を取得する。
    // 取得できなければ認証ステータスをfalseに設定する
    try {
      let cognitoUser = await Auth.currentAuthenticatedUser()
      this.signedIn = true
      this.username = cognitoUser.username
    } catch (err) {
      this.signedIn = false
    }
    // 認証ステータスが変わった時に呼び出されるイベントを登録
    AmplifyEventBus.$on('authState', async  info => {
      if (info === 'signedIn') {
        let cognitoUser = await Auth.currentAuthenticatedUser()
        this.signedIn = true
        this.username = cognitoUser.username
      } else {
        this.signedIn = false
      }
    });
  }
};


</script>

<style src="./chat.css" />