<template>
    <div class="container">
        <div class="jumbotron">
            <h1 class="display-4">C++ GAE/FE Sample!</h1>
            <p class="lead">Very Simple Chat App!</p>
            <hr class="my-4">
            <p>Developed by C++/Stmilus/Vue.js/FireBase/Docker</p>
            <p class="lead">
                <button v-if="!this.$store.state.session" v-on:click="login" class="btn btn-primary">Login to GitHub</button>
            </p>
        </div>
    </div>    
</template>

<script>
export default {
    mounted: function() {
        this.userLogin();
    },
    methods: {
        userLogin: function() {
            const firebase = this.$store.state.firebase;
            firebase.auth().onAuthStateChanged((response) => {
                if (response) {
                    this.$store.commit('getSession', true);
                    router.push({path: '/'});
                } else {
                    this.$store.commit('getSession', false);
                    router.push({path: '/'});
                }
            }, (error) => {
                console.log(error);
            });
        },
        login: function() {
            const firebase = this.$store.state.firebase;
            const provider = this.$store.state.provider;
            firebase.auth().signInWithPopup(provider).then((response) => {
                this.$store.commit('login', response.user.uid);
                this.$store.commit('setUserName', response.additionalUserInfo.profile.name);
                this.$store.commit('setUserIcon', response.additionalUserInfo.profile.avatar_url);
            }, (error) => {
                console.log(error)
            })
            this.userLogin();
        }
    }
}
</script>