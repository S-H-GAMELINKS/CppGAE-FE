<template>
    <div data-controller="chat">
        <div data-target="chat.title"></div>
        <div class="input-group">
            <div class="input-group-append">
                <span class="input-group-text">Input your tlak</span>
            </div>
            <input type="text" class="form-control" data-target="chat.content"> 
        </div>
        <p>
            <button v-if="!this.$store.state.session" type="button" class="btn btn-primary" data-action="click->chat#submit">Submit</button>
        </p>
        <div class="talk-box">
            <div class="talk-area" data-target="chat.talks"></div>
        </div>
    </div>
</template>

<script>
export default {
}
</script>

<style>
.talk-box {
    width: 100%;
    height: auto;
    overflow: hidden;
    margin-bottom: 20px;
}
.talk-area {
    width: 100%;
    float: right;
}
.talk {
    width: 80%;
    display: inline-block;
    padding: 15px 20px;
    margin-left: 120px;
    margin-top: 10px;
    border: 1px solid gray;
    border-radius: 10px;
}
</style>