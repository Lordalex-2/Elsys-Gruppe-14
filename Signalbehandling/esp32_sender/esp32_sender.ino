
const int START_SIGNAL_LENGDE = 5;
const bool START_SIGNAL[START_SIGNAL_LENGDE] = {1, 1, 1, 0, 1}; 
const char MELDING[] = "Hello World!";
bool bits[START_SIGNAL_LENGDE + sizeof(MELDING) * 8] = {};

const int BUZZER_PIN = 13;
const float BIT_TIME = 0.2
const int F0 = 1200;
const int F1 = 2200;
int bit = 0;

void setup() {
  Serial.begin(115200);
  ledcAttach(BUZZER_PIN, F0, 8)
  for (int i = 0; i < START_SIGNAL_LENGDE; i++)
  {
    bits[i] = START_SIGNAL[i];
  }
  for (int bokstav = 0; bokstav < strlen(MELDING); bokstav++) {
    uint8_t byte = MELDING[bokstav];
    int bit = 0;
    while (bit < 8) {
      if (byte & 0x01) {
        bits[bokstav * 8 + bit + START_SIGNAL_LENGDE] = true;
      } else {
        bits[bokstav * 8 + bit + START_SIGNAL_LENGDE] = false;
      }
      bit++;
      byte = byte >> 1;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    if (bit < sizeof(bits)) {
        if (bits[bit]) {
          ledcWriteTone(BUZZER_PIN, F1)
        }
        else {
          ledcWriteTone(BUZZER_PIN, F0)
        }
        bit++;
    }
    delay(BIT_TIME * 1000)
}
