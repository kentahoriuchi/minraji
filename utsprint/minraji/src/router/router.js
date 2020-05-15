import Vue from 'vue'
import Router from 'vue-router'

//import Login from '@/components/Login'
import Home from '@/components/Home'
import Chat from '@/components/chat'
import Room from '@/components/room'
import Room_create from '@/components/room_create'
import SampleAuth from "../views/SampleAuth";
import In_the_room from '@/components/in_the_room'
import Movie from '@/components/Movie'

// Amplify読み込み
import {  AmplifyEventBus } from 'aws-amplify-vue'
import { AmplifyPlugin } from 'aws-amplify-vue'
import AmplifyModules from 'aws-amplify'

Vue.use(AmplifyPlugin, AmplifyModules)
Vue.use(Router)

let user;

// ユーザー管理
getUser().then((user) => {
    if (user) {
        router.push({path: '/'});
    }
});

function getUser() {
    return Vue.prototype.$Amplify.Auth.currentAuthenticatedUser().then((data) => {
        if (data && data.signInUserSession) {
            return data;
        }
    }).catch(() => {
        return null;
    });
}

// ログイン状態管理
AmplifyEventBus.$on('authState', async (state) => {
    if (state === 'signedOut'){
        user = null;
        router.push({path: '/login'});
    } else if (state === 'signedIn') {
        user = await getUser();
        router.push({path: '/'});
    }
});

const router = new Router({
    mode:'history',

  routes: [
    {
      path: '/login',
      name: 'login',
      //component: Login
      component: SampleAuth
    },
    {
      path: '/',
      name: 'home',
      component: Home,
      meta:{ requireAuth:true}
    },
    {
        path: '/chat',
        name: 'chat',
        component: Chat
    },
    {
        path: '/room',
        name: 'room',
        component: Room
    },
    {
        path: '/room_create',
        name: 'room_create',
        component: Room_create
    },
    {
        path: '/room/in',
        name: 'in_the_room',
        component: In_the_room
    },
    {
        path: '/movie',
        name: 'Movie',
        component: Movie
    },
  ]
})

router.beforeResolve(async (to, from, next) => {
    if (to.matched.some(record => record.meta.requiresAuth)) {
        user = await getUser();
        if (!user) {
            return next({
                path: '/login'
            });
        }
        return next()
    }
    return next()
});

export default router