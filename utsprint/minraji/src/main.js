import Vue from 'vue'
import App from './App'
// import router from './router/router'
// import ElementUI from 'element-ui';
// import 'element-ui/lib/theme-chalk/index.css';
// import locale from 'element-ui/lib/locale/lang/ja';

// //Element UI 
// import ElementUI from 'element-ui'
// import locale from 'element-ui/lib/locale/lang/ja'
// import 'element-ui/lib/theme-chalk/index.css'
// import 'element-ui/lib/theme-chalk/display.css'

//import awsconfig from './aws-exports';
import Amplify, * as AmplifyModules from 'aws-amplify';
import { AmplifyPlugin } from 'aws-amplify-vue';

import { I18n } from '@aws-amplify/core';
import aws_exports from "./aws-exports";

Amplify.configure(aws_exports);
//Amplify.configure(awsconfig);
Vue.use(AmplifyPlugin, AmplifyModules);

// //Element UI
// Vue.use(ElementUI, { locale });

Vue.config.productionTip = false
Vue.use(ElementUI, { locale });

let languageDict = {
  ja:{
    "Back to Sign In": "サインイン画面に戻る",
    Confirm: "確認",
    "Confirm Sign Up": "サインアップの確認",
    "Confirmation Code": "確認コード",
    "Create Account": "新規登録",
    "Create a new account": "アカウントの新規登録",
    "Create account": "新規登録",
    Email: "メールアドレス",
    "Enter your code": "確認コードを入力してください",
    "Enter your password": "パスワードを入力してください",
    "Enter your Username": "ユーザー名を入力してください",
    "Forget your password? ": "パスワードをお忘れの方 ",
    "Have an account? ": "アカウント登録済みの方 ",
    Hello: "こんにちは ",
    "Incorrect username or password": "ユーザー名またはパスワードが異なります",
    "Lost your code? ": "コードを紛失した方 ",
    "No account? ": "アカウント未登録の方 ",
    Password: "パスワード",
    "Phone Number": "電話番号",
    "Resend Code": "確認コードの再送",
    "Reset password": "パスワードのリセット",
    "Reset your password": "パスワードのリセット",
    "Send Code": "コードの送信",
    "Sign In": "サインイン",
    "Sign Out": "サインアウト",
    "Sign in": "サインイン",
    "Sign in to your account": "サインイン",
    "User does not exist": "ユーザーが存在しません",
    Username: "ユーザー名",
    "Username cannot be empty": "ユーザー名は必須入力です",
    "Username/client id combination not found.": "ユーザー名が見つかりません"
  }
}
I18n.putVocabularies(languageDict)
I18n.setLanguage("ja");

new Vue({
  router,
  render: h => h(App),
}).$mount('#app')
/*
import Vue from 'vue'
import App from './App.vue'
import Amplify, * as AmplifyModules from 'aws-amplify'
import { AmplifyPlugin } from 'aws-amplify-vue'
import awsmobile from './aws-exports'
import { I18n } from '@aws-amplify/core';

I18n.setLanguage("ja");

Amplify.configure(awsmobile)

Vue.use(AmplifyPlugin, AmplifyModules)
Vue.config.productionTip = false

let languageDict = {
    ja:{
        'Sign In Account' : 'アカウントにサインイン',
        'Username' : 'ユーザ名',
        'Enter your username' : 'ユーザ名を入力してください',
        'Password' : 'パスワード',
        'Enter your password' : 'パスワードを入力してください',
        'Forget your password? ' : 'パスワードを忘れた場合',
        'Reset password' : 'パスワードのリセット',
        'No account? ' : 'まだアカウントがない場合',
        'Create account' : 'アカウント作成',
        'Sign In' : 'サインイン',
    }
}
AmplifyModules.I18n.putVocabularies(languageDict)

new Vue({
  render: h => h(App)
}).$mount('#app')*/