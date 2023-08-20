# nightmare
 Nightmare is a engine with base on SDL2 made in cpp for all devices  
 but for now is a API in test phase, version: _beta 0.0.4_,  
 start devlopment: _august 18th 2023_, last modify: __august 20th 2023__

# features
 - Avaliable in all devices  
 - More simple and fast  
 - Error tratament system  

# how it works
 - [ ] To it works correctly you will need have the SDL2 in your device  
 - [ ] How include it in your code with `#include "nightmareAPI.hpp"`  
 - [ ] Create a new game class using `nightmare game;`
 - [ ] Make a main function and put alls respectives functions in yours positions  
 ```cpp
 #include "nightmareAPI/nightmare.hpp"
 
 nightmare game;
 int main(int argc, char *argv[])
 {
     //init
     game.init("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, true); //here settings like window position (undefined from mobile), window size or fullscreen
     //images fonts to load
     //game loop
     while (true)
     {
         //events
         if (game.getEvents() == "quit") 
         {
             break;
         }
         //render
         game.render();
         //images and text to reder...
         //update
         int dt = game.update(60); //here define your framerate, default: 60 fps
         //logic...
     }
     //then the game ends
     game.destroy();
     return 0; 
 }
 ```

# functions
it's a beta then hasn't much functions
|name|paramters|
|---|---|
|loadfont|path, size|
|---|---|
|loadImage|image source|
|---|---|
|drawImage|image, posx, posy, width, height, offsetx, offsety|
|---|---|
|drawText|font, posx, posy, width, height  offsetx  offsety|

# how i can contribute?
 Make a fork with your ideas :)