
const int BUZZER_PIN = -1;
const int START_SIGNAL[7] = { 1, 1, 1, 0, 0, 1, 0 };  // barker code med lenge 7
const char MELDING[] = "Hello world!";
bool bits[sizeof(MELDING) * 8] = {};
const int f_0 = 1200;
const int f_1 = 2200;
void setup() {
  Serial.begin(115200);
  for (int i = 0; i < strlen(MELDING); i++) {
    uint8_t byte = MELDING[i];
    uint8_t bit = 0;
    while (bit < 8) {
      if (byte & 0x01) {
        bits[i * 8 + bit] = true;
      } else {
        bits[i * 8 + bit] = false;
      }
      bit++;
      byte = byte >> 1;
    }
    Serial.print(" ");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
