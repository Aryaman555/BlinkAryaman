const int ledPin = 13;   // Pin for LED
const int buttonPin = 7; // Pin for the push button

const char* morseCode[] = {
  ".-",    // A
  "-...",  // B
  "-.-.",  // C
  "-..",   // D
  ".",     // E
  "..-.",  // F
  "--.",   // G
  "....",  // H
  "..",    // I
  ".---",  // J
  "-.-",   // K
  ".-..",  // L
  "--",    // M
  "-.",    // N
  "---",   // O
  ".--.",  // P
  "--.-",  // Q
  ".-.",   // R
  "...",   // S
  "-",     // T
  "..-",   // U
  "...-",  // V
  ".--",   // W
  "-..-",  // X
  "-.--",  // Y
  "--.."   // Z
};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    blinkName();  // Function to blink name
    delay(1000);  // Delay to prevent multiple activations from a single press
  }
}

void blinkName() {
  const char* name = "ARYAMAN";  // The name you want to BLINK here ...

  for (int i = 0; name[i] != '\0'; i++) {
    char letter = name[i];
    if (letter >= 'A' && letter <= 'Z') {
      int morseIndex = letter - 'A';
      const char* morseSequence = morseCode[morseIndex];

      for (int j = 0; morseSequence[j] != '\0'; j++) {
        if (morseSequence[j] == '.') {
          digitalWrite(ledPin, HIGH);
          delay(200); // Dot duration
          digitalWrite(ledPin, LOW);
          delay(200); // Gap between dots and dashes
        } else if (morseSequence[j] == '-') {
          digitalWrite(ledPin, HIGH);
          delay(600); // Dash duration
          digitalWrite(ledPin, LOW);
          delay(200); // Gap between dots and dashes
        }
      }
      delay(400); // Gap between letters
    }
  }
}
