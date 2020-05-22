<template>
<div>
<header>

<!--this is sign in home screen-->

<h1 class="headline">
      <a>みんラジ!</a>
</h1>
<div v-if="signedIn">
    <ul class="nav-list">
      <li class="nav-list-item"><a href="#link2about">About</a></li>
      <li class="nav-list-item"><a href="#link2service">Service</a></li>
      <li class="nav-list-item"><router-link to="/use" id="go-how-to-use-button">How to use</router-link></li>
      <li class="nav-list-item" ><router-link to="/room" id="go-room-button-at-home">ルーム広場に行く</router-link></li>
      <!--<li class="nav-list-item"><router-link to="/cal_page" id="cal-room-button">予定を確認する</router-link></li>-->
      <li class="nav-list-item"><input type="button" name="buttonName" id="question-button" value="アンケートに答える" onClick="window.open('https://docs.google.com/forms/d/e/1FAIpQLSeeWIQ5NyHNrhWfj9K_ZJS8sZ_wD0ZJTYCOpQr1qm9KkUDLBQ/viewform?usp=sf_link','_blank')" /></li>
      <li class="nav-list-item"><amplify-sign-out></amplify-sign-out></li>
    </ul>
    <router-link to="/calendar">カレンダーページ</router-link>
</div>
<div v-if="!signedIn">
<ul class="nav-list">
      <li class="nav-list-item"><a href="#link2about">About</a></li>
      <li class="nav-list-item"><a href="#link2service">Service</a></li>
      <li class="nav-list-item"><router-link to="/use" id="go-how-to-use-button">How to use</router-link></li>
      <li class="nav-list-item"> <router-link to="/login" id="login-button">ログインする</router-link></li>
    </ul>	

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
<p>
<img src="../image/radio_taisou.png" id="radio_taiso" alt="ラジオ体操"  width=20%>
</p>
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
  <input type="button" name="buttonName" id="question-button" value="アンケートに答える" onClick="window.open('https://docs.google.com/forms/d/e/1FAIpQLSeeWIQ5NyHNrhWfj9K_ZJS8sZ_wD0ZJTYCOpQr1qm9KkUDLBQ/viewform?usp=sf_link','_blank')" />
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

/*export default {
  mounted() {
    const hash = this.$route.hash;
    if (hash && hash.match(/^#.+$/)) {
      this.$scrollTo(hash);
    }
  }
};*/
</script>

<style>
header {
  height: 200px;
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
  /*float: left;*/
  font-size: 50px;
  margin-left: 100px;
  color: #454545;

}

#go-room-button-at-home {
  font-size: 1.4em;
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

#go-how-to-use-button {
  font-size: 1.4em;
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

#go-how-to-use-button:active {
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

#login-button {
  /*position: relative*/
  font-size: 1.4em;
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

#cal-room-button {
  font-size: 1.4em;
  position: relative;
  display: inline-block;
  padding: 0.25em 0.5em;
  text-decoration: none;
  color: #FFF;
  background: #fd9535;/*背景色*/
  border-bottom: solid 2px #3b280c;/*少し濃い目の色に*/
  border-radius: 4px;/*角の丸み*/
  box-shadow: inset 0 2px 0 rgba(255,255,255,0.2), 0 2px 2px rgba(0, 0, 0, 0.19);
  font-weight: bold;
}

#cal-room-button:active {
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

#radio_taiso{
  position: relative;
  left:500px;
}

#question-button {
  font-size: 1.4em;
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

#question-button:active {
  border-bottom: solid 2px #fd9535;
  box-shadow: 0 0 2px rgba(0, 0, 0, 0.30);
}

main {
  height: 2000px;
  width: 100%;
  padding: 15px 0;
  /*background-color: #337079;*/
  /*background: #dfefff;*/
}



</style>