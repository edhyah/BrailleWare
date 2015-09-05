/*
  PennApps Fall 2015
  Braille Output onto Arduino Micro
*/

// pins of 6 dot array
const int ONE = 5;
const int TWO = 6;
const int THREE = 7;
const int FOUR = 8;
const int FIVE = 9;
const int SIX = 10;

// character definitions
const boolean CHR_A[] = { true, false, false, false, false, false };
const boolean CHR_B[] = { true, false, true, false, false, false };
const boolean CHR_C[] = { true, true, false, false, false, false };
const boolean CHR_D[] = { true, true, false, true, false, false };
const boolean CHR_E[] = { true, false, false, true, false, false };
const boolean CHR_F[] = { true, true, true, false, false, false };
const boolean CHR_G[] = { true, true, true, true, false, false };
const boolean CHR_H[] = { true, false, true, true, false, false };
const boolean CHR_I[] = { false, true, true, false, false, false };
const boolean CHR_J[] = { false, true, true, true, false, false };
const boolean CHR_K[] = { true, false, false, false, true, false };
const boolean CHR_L[] = { true, false, true, false, true, false };
const boolean CHR_M[] = { true, true, false, false, true, false };
const boolean CHR_N[] = { true, true, false, true, true, false };
const boolean CHR_O[] = { true, false, false, true, true, false };
const boolean CHR_P[] = { true, true, true, false, true, false };
const boolean CHR_Q[] = { true, true, true, true, true, false };
const boolean CHR_R[] = { true, false, true, true, true, false };
const boolean CHR_S[] = { false, true, true, false, true, false };
const boolean CHR_T[] = { false, true, true, true, true, false };
const boolean CHR_U[] = { true, false, false, false, true, true };
const boolean CHR_V[] = { true, false, true, false, true, true };
const boolean CHR_W[] = { false, true, true, true, false, true };
const boolean CHR_X[] = { true, true, false, false, true, true };
const boolean CHR_Y[] = { true, true, false, true, true, true };
const boolean CHR_Z[] = { true, false, false, true, true, true };
const boolean CHR_0[] = { false, true, true, true, false, false };
const boolean CHR_1[] = { true, false, false, false, false, false };
const boolean CHR_2[] = { true, false, true, false, false, false };
const boolean CHR_3[] = { true, true, false, false, false, false };
const boolean CHR_4[] = { true, true, false, true, false, false };
const boolean CHR_5[] = { true, false, false, true, false, false };
const boolean CHR_6[] = { true, true, true, false, false, false };
const boolean CHR_7[] = { true, true, true, true, false, false };
const boolean CHR_8[] = { true, false, true, true, false, false };
const boolean CHR_9[] = { false, true, true, false, false, false };
const boolean CHR_PERIOD[] = { false, false, true, true, false, true };
const boolean CHR_COMMA[] = { false, false, true, false, false, false };
const boolean CHR_SEMICLN[] = { false, false, true, false, true, false };
const boolean CHR_COLON[] = { false, false, true, true, false, false };
const boolean CHR_SLASH[] = { false, true, false, false, true, false };
const boolean CHR_QUERY[] = { false, false, true, false, true, true };
const boolean CHR_BANG[] = { false, false, true, true, true, false };
const boolean CHR_AT[] = { false, true, false, true, true, false };
const boolean CHR_POUND[] = { false, true, false, true, true, true };
const boolean CHR_PLUS[] = { false, false, true, true, true, false };
const boolean CHR_MINUS[] = { false, false, true, true, false, false };
const boolean CHR_ASTER[] = { false, false, false, true, true, false };
const boolean CHR_QUOTE[] = { false, false, true, false, true, true };
const boolean CHR_APOST[] = { false, false, false, false, true, false };
const boolean CHR_LCARET[] = { true, false, true, false, false, true };
const boolean CHR_RCARET[] = { false, true, false, true, true, false };
const boolean CHR_PAREN[] = { false, false, true, true, true, true };

void setup() {
  pinMode(ONE, OUTPUT);
  pinMode(TWO, OUTPUT);
  pinMode(THREE, OUTPUT);
  pinMode(FOUR, OUTPUT);
  pinMode(FIVE, OUTPUT);
  pinMode(SIX, OUTPUT);
}

// turn off all vibrations
void turnOffAll() {
  digitalWrite(ONE, LOW);
  digitalWrite(TWO, LOW);
  digitalWrite(THREE, LOW);
  digitalWrite(FOUR, LOW);
  digitalWrite(FIVE, LOW);
  digitalWrite(SIX, LOW);
  delay(20);
}

// turn on specific character pattern on 6 dot array
void turnOnChr(const boolean *chr) {
  int currentPin = ONE;
  for (int i = 0; i < 6; i++) {
    if (chr[i]) digitalWrite(currentPin, HIGH);
    currentPin++;
  }
  delay(1000);
  turnOffAll();
}

// turn on a string of character patterns on 6 dot array
void turnOnStr(String str) {
  str.toUpperCase();
  for (int i = 0; i < str.length(); i++) {
    switch(str[i]) {
      case 'A':
        turnOnChr(CHR_A);
        break;
      case 'B':
        turnOnChr(CHR_B);
        break;
      case 'C':
        turnOnChr(CHR_C);
        break;
      case 'D':
        turnOnChr(CHR_D);
        break;
      case 'E':
        turnOnChr(CHR_E);
        break;
      case 'F':
        turnOnChr(CHR_F);
        break;
      case 'G':
        turnOnChr(CHR_G);
        break;
      case 'H':
        turnOnChr(CHR_H);
        break;
      case 'I':
        turnOnChr(CHR_I);
        break;
      case 'J':
        turnOnChr(CHR_J);
        break;
      case 'K':
        turnOnChr(CHR_K);
        break;
      case 'L':
        turnOnChr(CHR_L);
        break;
      case 'M':
        turnOnChr(CHR_M);
        break;
      case 'N':
        turnOnChr(CHR_N);
        break;
      case 'O':
        turnOnChr(CHR_O);
        break;
      case 'P':
        turnOnChr(CHR_P);
        break;
      case 'Q':
        turnOnChr(CHR_Q);
        break;
      case 'R':
        turnOnChr(CHR_R);
        break;
      case 'S':
        turnOnChr(CHR_S);
        break;
      case 'T':
        turnOnChr(CHR_T);
        break;
      case 'U':
        turnOnChr(CHR_U);
        break;
      case 'V':
        turnOnChr(CHR_V);
        break;
      case 'W':
        turnOnChr(CHR_W);
        break;
      case 'X':
        turnOnChr(CHR_X);
        break;
      case 'Y':
        turnOnChr(CHR_Y);
        break;
      case 'Z':
        turnOnChr(CHR_Z);
        break;
      case '0':
        turnOnChr(CHR_0);
        break;
      case '1':
        turnOnChr(CHR_1);
        break;
      case '2':
        turnOnChr(CHR_2);
        break;
      case '3':
        turnOnChr(CHR_3);
        break;
      case '4':
        turnOnChr(CHR_4);
        break;
      case '5':
        turnOnChr(CHR_5);
        break;
      case '6':
        turnOnChr(CHR_6);
        break;
      case '7':
        turnOnChr(CHR_7);
        break;
      case '8':
        turnOnChr(CHR_8);
        break;
      case '9':
        turnOnChr(CHR_9);
        break;
      case '.':
        turnOnChr(CHR_PERIOD);
        break;
      case ',':
        turnOnChr(CHR_COMMA);
        break;
      case ';':
        turnOnChr(CHR_SEMICLN);
        break;
      case ':':
        turnOnChr(CHR_COLON);
        break;
      case '/':
        turnOnChr(CHR_SLASH);
        break;
      case '?':
        turnOnChr(CHR_QUERY);
        break;
      case '!':
        turnOnChr(CHR_BANG);
        break;
      case '@':
        turnOnChr(CHR_AT);
        break;
      case '#':
        turnOnChr(CHR_POUND);
        break;
      case '+':
        turnOnChr(CHR_PLUS);
        break;
      case '-':
        turnOnChr(CHR_MINUS);
        break;
      case '*':
        turnOnChr(CHR_ASTER);
        break;
      case '\"':
        turnOnChr(CHR_QUOTE);
        break;
      case '\'':
        turnOnChr(CHR_APOST);
        break;
      case '<':
        turnOnChr(CHR_LCARET);
        break;
      case '>':
        turnOnChr(CHR_RCARET);
        break;
      case '(':
        turnOnChr(CHR_PAREN);
        break;
      case ')':
        turnOnChr(CHR_PAREN);
        break;
      default:
        break;
    }
  }
}

void loop() {
  // read data from Bluetooth
  String text = "";
  while (Serial.available()) {
    text += char(Serial.read());
  }
  // display text
  turnOnStr(text);
}
