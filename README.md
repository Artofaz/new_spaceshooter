<p align="center" >
  <img src="https://img.shields.io/badge/spaceshooter++-C++/SDL2-FF226F?style=square&logo=cplusplus" width=450 height=50 />
</p>

<h1 align="center" >spaceshooter++</h1>
<h1 align="center" >⚠️ Currently in development ⚠️</h1>
<h2 align="center" >Little arcade-like space shooter game</h2>

<p align="center" >
  <a href="#compiling" >Compiling</a>
  <span>•</span>
  <a href="#game" >Game</a>
</p>

---
## **COMPILING**

<br/>

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/22/Heckert_GNU_white.svg/langfr-260px-Heckert_GNU_white.svg.png" width=50 height=50 />

- Windows: `execute the second line in "compile.txt" in your terminal` 
  > For windows, all libraries and dll files are included in the project, you just need [mingw32](https://sourceforge.net/projects/mingw-w64/) installed 
  
<br/>

<img src="https://www.debian.org/Pics/debian-logo-1024x576.png" width=50 height=50/>

- Linux: `execute the first line in "compile.txt" in your terminal`
  > To install SDL2 libraries on a debian-based distro: <br /> 
  ```bash
  sudo apt-get install libsdl2-2.0-dev
  sudo apt-get install libsdl2-image-dev
  sudo apt-get install libsdl2-ttf-dev
  
  #!Verify that the libraries are installed:
  apt-cache search libsdl2
  ```
  > or by directly downloading the source code [here](https://libsdl.org/download-2.0.php)

---
## **Game**

1. Keybindings
   
    | Key         | Action |
    |-------------|--------|
    | Up arrow    | Up     |
    | Down arrow  | Down   |
    | Left arrow  | Left   |
    | Right arrow | Right  |
    | Space       | Shoot  |
