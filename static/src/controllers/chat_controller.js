import { Controller } from "stimulus"
import store from '../../store/index'

const database = store.state.database;

export default class extends Controller {
    static get targets() {
        return ["title", "talks", "content"]
    }

    initialize() {
        this.update();
    }

    update() {
        const data = database.ref('cppgaefe' + String(location.pathname).replace(/\/chats/, ''));
        data.on("value", (snapshot) => {
            const cppgaefe = Object.entries(snapshot.val());

            this.talksTarget.innerHTML = "";
            for(var i = 0; i < cppgaefe.length; i++) {
                if (cppgaefe[i][0] === "title") {
                    this.titleTarget.innerHTML = `<h1>${cppgaefe[i][1]}</h1>`
                }
                if (cppgaefe[i][1].content !== undefined && cppgaefe[i][1].content !== "") {
                    this.talksTarget.innerHTML += `<img src=${cppgaefe[i][1].icon} width="64" height="64" class="img-thumbnail">${cppgaefe[i][1].name}<div class="talk">${cppgaefe[i][1].content}</div>`;
                }
            }
        }, (errorObject) => {
            console.log("The read failed: " + errorObject.code);
        })
    }

    submit() {
        database.ref('cppgaefe' + String(location.pathname).replace(/\/chats/, '')).push({
            content: this.contentTarget.value,
            name: store.state.name,
            icon: store.state.icon
        });
        this.contentTarget.value = "";
    }
}