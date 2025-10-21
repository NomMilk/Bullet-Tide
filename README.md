# Bullet Tide
<img width="600" height="250" alt="image" src="https://github.com/user-attachments/assets/c141deda-f5f5-476b-aaf9-9e5dc13cc1c6" />
<br>
<h2>About</h2>
<img width="350" height="200" alt="image" src="https://github.com/user-attachments/assets/63a97bd1-4fbb-474e-ae3a-2688f073d159" />

Tired of having an operating system on your machine? Well, fear no longer!
Instead of running a boring old operating system, you can convert your old machine to this game.
I don't know why you would want to do this but it supports x86_64, so you can game on any
hardware!!!
<h2>Features</h2>

- infinite levels
- randomly spawning enemies
- there is sound effects
- maybe a memory leak?
  
<h2>Compilation</h2>
There are some requirements before being able to compile it. Although docker should be able to handle all of it. Make sure you have docker installed you will need it to compile this
<br>
<br>

- First build the docker image by running

```
docker build -t fishos-buildenv .
```

- Then run the docker image
```
docker run --rm -it -v "%cd%":/root/env fishos-buildenv
```

- And finally use the make command
<h2>Installation</h2>
Download the ISO in the dist/x86_64 and flash it on a usb drive
<br>
or run it on emulation if you're weak
