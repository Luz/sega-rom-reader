# sega-rom-reader
This reader for "sega mega drive" ROMs directly accesses the games by using the 5V-tolerant "Teensy 3.5".

## Pictures of the reader:
Reader: Teensy 3.5 and the socket for the cartridge
![reader](https://raw.githubusercontent.com/Luz/sega-rom-reader/master/pics/pic1.jpg)

Bottom side: made with wire wrap technology
![wire-wrap](https://raw.githubusercontent.com/Luz/sega-rom-reader/master/pics/pic2.jpg)

Jumper: will be used later for the creation of a sega-game-programmer
![jumper](https://raw.githubusercontent.com/Luz/sega-rom-reader/master/pics/pic3.jpg)

ROM: The first ROM that was read
![first-rom](https://raw.githubusercontent.com/Luz/sega-rom-reader/master/pics/pic4.jpg)

Wire-Wrap pins: Close shot of two wire wrap connections
![wire-wrap-pins](https://raw.githubusercontent.com/Luz/sega-rom-reader/master/pics/pic5.jpg)

Cartridge pcb: This socket was not able to reliably hold an EEPROM
![cartridge-bad-socket](https://raw.githubusercontent.com/Luz/sega-rom-reader/master/pics/pic6.jpg)

Cartridge with 27C322: PCB still needs to be tested, but some bytes were already written
![cartridge-with-27c322](https://raw.githubusercontent.com/Luz/sega-rom-reader/master/pics/pic7.jpg)

## TODO
* Since a ROM can be less than 4MB and the reader currently reads 4MB (21 adress lines at 2 bytes), a 2MB file will be read duplicated. Detect duplications and remove that unnecessary data.

* Add a button or a command to read more than just one ROM

* Create a sega mega drive programmer

