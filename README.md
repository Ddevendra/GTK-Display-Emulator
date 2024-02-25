Display Emulator to design UI of embedded systems.

- Do not have to deploy UI to target system each time.
- Uses same source file as the main project.

---

### Dependencies :

- sudo apt install libcairo2-dev
- sudo apt-get install build-essential libgtk-3-dev

Execution :
- g++ ./gtk.c $(pkg-config --libs --cflags cairo gtk+-3.0)
