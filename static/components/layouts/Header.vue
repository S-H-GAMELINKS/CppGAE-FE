<template>
    <nav class="navbar navbar-expand-lg navbar-dark bg-primary">
        <router-link class="navbar-brand" to="/">C++ GAE/FE Sample</router-link>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarColor01" aria-controls="navbarColor01" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarColor01">
            <ul class="navbar-nav mr-auto">
                <li class="nav-item dropdown">
                  <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                    Menu
                  </a>
                  <div class="dropdown-menu" aria-labelledby="navbarDropdown">
                    <router-link class="dropdown-item" to="/">Top</router-link>
                    <router-link class="dropdown-item" to="/about">About</router-link>
                    <router-link class="dropdown-item" to="/contact">Contact</router-link>
                    <router-link class="dropdown-item" to="/chats">Chat</router-link>
                  </div>
                </li>
            </ul>
        </div>
    </nav>    
</template>
