// github.com/Luz

// Adress pins: 0 to 20 (21 pins)
// Data pins: 24 to 39 (16 pins)

// Chip enable:
const int cePin = 23;

// Output enable: (and is also programPin)
const int oePin = 22;

uint32_t writePosition = 0; // can be changed for test purposes
char lsb, msb;

void setup() {
  for (int adressPin=0 ; adressPin<21 ; adressPin++)
    pinMode(adressPin, OUTPUT);
  for (int dataPin=24 ; dataPin<40 ; dataPin++)
    pinMode(dataPin, OUTPUT); // INPUT for reader, OUTPUT for writer
  
  pinMode(cePin, OUTPUT);
  chipEnable(false);
  pinMode(oePin, OUTPUT);
  outputEnable(false);
  
  Serial.begin(115200); // USB is always 12 Mbit/sec
}

void loop() {
  if (Serial.available() >= 2) {
    Serial.readBytes(&lsb, 1); // lsb (send lsb first over serial port)
    Serial.readBytes(&msb, 1); // msb
    programWord(writePosition, (((int16_t)msb)<<8) | lsb);
    writePosition++;
  }
  delay(1);
}

void programWord(uint32_t adress, int16_t word) {
  setAdress(adress);
  writeWord(word);
  outputEnable(true);
  delayMicroseconds(3); // Needs to be 1us or more
  chipEnable(true);
  delayMicroseconds(50); // Do not change! 50us is programming time
  chipEnable(false);
  delayMicroseconds(3); // Data needs to be 2us after programming
  outputEnable(false);
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

void writeWord(int16_t word) {
  (word & 0x0001<<0) ? digitalWriteFast(24, HIGH) : digitalWriteFast(24, LOW);
  (word & 0x0001<<1) ? digitalWriteFast(25, HIGH) : digitalWriteFast(25, LOW);
  (word & 0x0001<<2) ? digitalWriteFast(26, HIGH) : digitalWriteFast(26, LOW);
  (word & 0x0001<<3) ? digitalWriteFast(27, HIGH) : digitalWriteFast(27, LOW);
  (word & 0x0001<<4) ? digitalWriteFast(28, HIGH) : digitalWriteFast(28, LOW);
  (word & 0x0001<<5) ? digitalWriteFast(29, HIGH) : digitalWriteFast(29, LOW);
  (word & 0x0001<<6) ? digitalWriteFast(30, HIGH) : digitalWriteFast(30, LOW);
  (word & 0x0001<<7) ? digitalWriteFast(31, HIGH) : digitalWriteFast(31, LOW);
  (word & 0x0001<<8) ? digitalWriteFast(32, HIGH) : digitalWriteFast(32, LOW);
  (word & 0x0001<<9) ? digitalWriteFast(33, HIGH) : digitalWriteFast(33, LOW);
  (word & 0x0001<<10) ? digitalWriteFast(34, HIGH) : digitalWriteFast(34, LOW);
  (word & 0x0001<<11) ? digitalWriteFast(35, HIGH) : digitalWriteFast(35, LOW);
  (word & 0x0001<<12) ? digitalWriteFast(36, HIGH) : digitalWriteFast(36, LOW);
  (word & 0x0001<<13) ? digitalWriteFast(37, HIGH) : digitalWriteFast(37, LOW);
  (word & 0x0001<<14) ? digitalWriteFast(38, HIGH) : digitalWriteFast(38, LOW);
  (word & 0x0001<<15) ? digitalWriteFast(39, HIGH) : digitalWriteFast(39, LOW);
}

void chipEnable(bool enable) {
  enable ? digitalWriteFast(cePin, LOW) : digitalWriteFast(cePin, HIGH);
}

void outputEnable(bool enable) {
  enable ? digitalWriteFast(oePin, LOW) : digitalWriteFast(oePin, HIGH);
}

