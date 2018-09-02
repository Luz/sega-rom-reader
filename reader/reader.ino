// github.com/Luz

// Adress pins: 0 to 20 (21 pins)
// Data pins: 24 to 39 (16 pins)

// Chip enable:
const int cePin = 23;

// Output enable: (and is also programPin)
const int oePin = 22;

void setup() {
  for (int adressPin=0 ; adressPin<21 ; adressPin++)
    pinMode(adressPin, OUTPUT);
  for (int dataPin=24 ; dataPin<40 ; dataPin++)
    pinMode(dataPin, INPUT); // INPUT for reader, OUTPUT for writer
  
  pinMode(cePin, OUTPUT);
  chipEnable(false);
  pinMode(oePin, OUTPUT);
  outputEnable(false);
  
  Serial.begin(115200); // USB is always 12 Mbit/sec
}

void loop() {
  delay(5000); // 5 seconds. ensure com port is opened in that time... then read the rom!
  
  for (uint32_t adress=0; adress < (1<<21); adress++) {
    chipEnable(true);
    outputEnable(true);
    int16_t word = 0;
    setAdress(adress);
    delayMicroseconds(3); // does not work accurately with less than 3us
    word = readWord();

    Serial.print(char(word&0xFF)); // lsb (send lsb first over serial port)
    Serial.print(char(word>>8));   // msb
    // 8 seconds to transmit 4MB over USB (should be the current limit of teensy usb library)

    delayMicroseconds(7); // i guess we need to give the usb send function some time... how much?
  }
  
  while(true); // Read the ROM only once, so for the moment get stuck in here.
}

void setAdress(uint32_t adress) {
  (adress & 0x00000001<<0) ? digitalWriteFast(0, HIGH) : digitalWriteFast(0, LOW);
  (adress & 0x00000001<<1) ? digitalWriteFast(1, HIGH) : digitalWriteFast(1, LOW);
  (adress & 0x00000001<<2) ? digitalWriteFast(2, HIGH) : digitalWriteFast(2, LOW);
  (adress & 0x00000001<<3) ? digitalWriteFast(3, HIGH) : digitalWriteFast(3, LOW);
  (adress & 0x00000001<<4) ? digitalWriteFast(4, HIGH) : digitalWriteFast(4, LOW);
  (adress & 0x00000001<<5) ? digitalWriteFast(5, HIGH) : digitalWriteFast(5, LOW);
  (adress & 0x00000001<<6) ? digitalWriteFast(6, HIGH) : digitalWriteFast(6, LOW);
  (adress & 0x00000001<<7) ? digitalWriteFast(7, HIGH) : digitalWriteFast(7, LOW);
  (adress & 0x00000001<<8) ? digitalWriteFast(8, HIGH) : digitalWriteFast(8, LOW);
  (adress & 0x00000001<<9) ? digitalWriteFast(9, HIGH) : digitalWriteFast(9, LOW);
  (adress & 0x00000001<<10) ? digitalWriteFast(10, HIGH) : digitalWriteFast(10, LOW);
  (adress & 0x00000001<<11) ? digitalWriteFast(11, HIGH) : digitalWriteFast(11, LOW);
  (adress & 0x00000001<<12) ? digitalWriteFast(12, HIGH) : digitalWriteFast(12, LOW);
  (adress & 0x00000001<<13) ? digitalWriteFast(13, HIGH) : digitalWriteFast(13, LOW);
  (adress & 0x00000001<<14) ? digitalWriteFast(14, HIGH) : digitalWriteFast(14, LOW);
  (adress & 0x00000001<<15) ? digitalWriteFast(15, HIGH) : digitalWriteFast(15, LOW);
  (adress & 0x00000001<<16) ? digitalWriteFast(16, HIGH) : digitalWriteFast(16, LOW);
  (adress & 0x00000001<<17) ? digitalWriteFast(17, HIGH) : digitalWriteFast(17, LOW);
  (adress & 0x00000001<<18) ? digitalWriteFast(18, HIGH) : digitalWriteFast(18, LOW);
  (adress & 0x00000001<<19) ? digitalWriteFast(19, HIGH) : digitalWriteFast(19, LOW);
  (adress & 0x00000001<<20) ? digitalWriteFast(20, HIGH) : digitalWriteFast(20, LOW);
}

int16_t readWord() {
  int16_t tmp = 0;
  tmp |= (digitalReadFast(24) ? 0x0001<<0 : 0);
  tmp |= (digitalReadFast(25) ? 0x0001<<1 : 0);
  tmp |= (digitalReadFast(26) ? 0x0001<<2 : 0);
  tmp |= (digitalReadFast(27) ? 0x0001<<3 : 0);
  tmp |= (digitalReadFast(28) ? 0x0001<<4 : 0);
  tmp |= (digitalReadFast(29) ? 0x0001<<5 : 0);
  tmp |= (digitalReadFast(30) ? 0x0001<<6 : 0);
  tmp |= (digitalReadFast(31) ? 0x0001<<7 : 0);
  tmp |= (digitalReadFast(32) ? 0x0001<<8 : 0);
  tmp |= (digitalReadFast(33) ? 0x0001<<9 : 0);
  tmp |= (digitalReadFast(34) ? 0x0001<<10 : 0);
  tmp |= (digitalReadFast(35) ? 0x0001<<11 : 0);
  tmp |= (digitalReadFast(36) ? 0x0001<<12 : 0);
  tmp |= (digitalReadFast(37) ? 0x0001<<13 : 0);
  tmp |= (digitalReadFast(38) ? 0x0001<<14 : 0);
  tmp |= (digitalReadFast(39) ? 0x0001<<15 : 0);

  return tmp;
}

void chipEnable(bool enable) {
  enable ? digitalWriteFast(cePin, LOW) : digitalWriteFast(cePin, HIGH);
}

void outputEnable(bool enable) {
  enable ? digitalWriteFast(oePin, LOW) : digitalWriteFast(oePin, HIGH);
}

