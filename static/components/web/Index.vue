<template>
    <div class="container">
        <h1>Index Pagse</h1>

        <button v-if="!this.$store.state.session" v-on:click="login" class="btn btn-primary">Login to GitHub</button>
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
            }, (error) => {
                console.log(error)
            })
            this.userLogin();
        }
    }
}
</script>