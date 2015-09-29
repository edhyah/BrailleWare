#define BUTTON_ZERO A0
#define BUTTON_ONE A1
#define BUTTON_TWO A2
#define BUTTON_THREE A3
#define BUTTON_FOUR A4
#define BUTTON_FIVE A5

#define VIBE_ZERO 3
#define VIBE_ONE 5
#define VIBE_TWO 6
#define VIBE_THREE 9
#define VIBE_FOUR 10
#define VIBE_FIVE 11

// define the array of characters
const char characters[] = {'A','B','C','D','E','F','G','H','I',
                         'J','K','L','M','N','O','P','Q','R',
                         'S','T','U','V','W','X','Y','Z','0',
                         '1','2','3','4','5','6','7','8','9',
                         '.',',',';',':','/','?','!','@','#',
                         '+','-','*','"','\'','<','>','('};

const bool braille_grid[][6] = {
  { true , false, false, false, false, false },
  { true , false, true , false, false, false },
  { true , true , false, false, false, false },
  { true , true , false, true , false, false },
  { true , false, false, true , false, false },
  { true , true , true , false, false, false },
  { true , true , true , true , false, false },
  { true , false, true , true , false, false },
  { false, true , true , false, false, false },
  { false, true , true , true , false, false },
  { true , false, false, false, true , false },
  { true , false, true , false, true , false },
  { true , true , false, false, true , false },
  { true , true , false, true , true , false },
  { true , false, false, true , true , false },
  { true , true , true , false, true , false },
  { true , true , true , true , true , false },
  { true , false, true , true , true , false },
  { false, true , true , false, true , false },
  { false, true , true , true , true , false },
  { true , false, false, false, true , true  },
  { true , false, true , false, true , true  },
  { false, true , true , true , false, true  },
  { true , true , false, false, true , true  },
  { true , true , false, true , true , true  },
  { true , false, false, true , true , true  },
  { false, true , true , true , false, false },
  { true , false, false, false, false, false },
  { true , false, true , false, false, false },
  { true , true , false, false, false, false },
  { true , true , false, true , false, false },
  { true , false, false, true , false, false },
  { true , true , true , false, false, false },
  { true , true , true , true , false, false },
  { true , false, true , true , false, false },
  { false, true , true , false, false, false },
  { false, false, true , true , false, true  },
  { false, false, true , false, false, false },
  { false, false, true , false, true , false },
  { false, false, true , true , false, false },
  { false, true , false, false, true , false },
  { false, false, true , false, true , true  },
  { false, false, true , true , true , false },
  { false, true , false, true , true , false },
  { false, true , false, true , true , true  },
  { false, false, true , true , true , false },
  { false, false, true , true , false, false },
  { false, false, false, true , true , false },
  { false, false, true , false, true , true  },
  { false, false, false, false, true , false },
  { true , false, true , false, false, true  },
  { false, true , false, true , true , false },
  { false, false, true , true , true , true  }
};

void setup() {
  pinMode(BUTTON_ZERO, INPUT);
  pinMode(BUTTON_ONE, INPUT);
  pinMode(BUTTON_TWO, INPUT);
  pinMode(BUTTON_THREE, INPUT);
  pinMode(BUTTON_FOUR, INPUT);
  pinMode(BUTTON_FIVE, INPUT);

  pinMode(VIBE_ZERO, OUTPUT);
  pinMode(VIBE_ONE, OUTPUT);
  pinMode(VIBE_TWO, OUTPUT);
  pinMode(VIBE_THREE, OUTPUT);
  pinMode(VIBE_FOUR, OUTPUT);
  pinMode(VIBE_FIVE, OUTPUT);
  Serial.begin(115200);
}

bool zero_press = false;
bool one_press = false;
bool two_press = false;
bool three_press = false;
bool four_press = false;
bool five_press = false;

bool presses[6];

bool do_read() {
 /* I/O loop, needs to read first, then display if anything is left */
  // low will be the button is pressed
  presses[0] = digitalRead(BUTTON_ZERO);
  presses[1] = digitalRead(BUTTON_ONE);
  presses[2] = digitalRead(BUTTON_TWO);
  presses[3] = digitalRead(BUTTON_THREE);
  presses[4] = digitalRead(BUTTON_FOUR);
  presses[5] = digitalRead(BUTTON_FIVE);

  double scale = 0.5;

  if (presses[0]) {
    analogWrite(VIBE_ZERO, 255 * scale);
  } else {
    analogWrite(VIBE_ZERO, 0);
  }

  if (presses[1]) {
    analogWrite(VIBE_ONE, 255 * scale);
  } else {
    analogWrite(VIBE_ONE, 0);
  }

  if (presses[2]) {
    analogWrite(VIBE_TWO, 255 * scale);
  } else {
    analogWrite(VIBE_TWO, 0);
  }

  if (presses[3]) {
    analogWrite(VIBE_THREE, 255 * scale);
  } else {
    analogWrite(VIBE_THREE, 0);
  }

  if (presses[4]) {
    analogWrite(VIBE_FOUR, 255 * scale);
  } else {
    analogWrite(VIBE_FOUR, 0);
  }

  if (presses[5]) {
    analogWrite(VIBE_FIVE, 255 * scale);
  } else {
    analogWrite(VIBE_FIVE, 0);
  }
  
  bool buttons_clear = !(presses[0] | presses[1] | presses[2] |
                         presses[3] | presses[4] | presses[5]);

  if (buttons_clear) {
    for (int i = 0; i < 6; i++) {
      presses[i] = false;
    }
  }

  return buttons_clear;
}

int match() {
  bool found_match = true;
  for (int i = 0; i < 53; i++) {
    for (int j = 0; j < 6; j++) {
      if (presses[j] != braille_grid[i][j]) {
        found_match = false;
        break;
      }
    }

    if (found_match) {
      return i;
    }

    found_match = true;
  }
  return -1; // unable to find
}

int true_presses() {
  int count = 0;
  for (int i = 0; i < 6; i++) {
    count += presses[i];
  }
  return count;
}

int last_count = 0;
char last_char = '\0';
long vibe_start_time = 0;

// turn off all vibrations
void turnOffAll() {
  digitalWrite(VIBE_ZERO, LOW);
  digitalWrite(VIBE_ONE, LOW);
  digitalWrite(VIBE_TWO, LOW);
  digitalWrite(VIBE_THREE, LOW);
  digitalWrite(VIBE_FOUR, LOW);
  digitalWrite(VIBE_FIVE, LOW);
  delay(200);
}

// turn on specific character pattern on 6 dot array
void turnOnChr(const bool *chr) {
  float fos = .5;
  if (chr[0]) analogWrite(VIBE_ZERO, (int)(255 * fos));
  if (chr[1]) analogWrite(VIBE_ONE, (int)(255 * fos));
  if (chr[2]) analogWrite(VIBE_TWO, (int)(255 * fos));
  if (chr[3]) analogWrite(VIBE_THREE, (int)(255 * fos));
  if (chr[4]) analogWrite(VIBE_FOUR, (int)(255 * fos));
  if (chr[5]) analogWrite(VIBE_FIVE, (int)(255 * fos));

  delay(500);
  turnOffAll();
}

void turnOnStr(String str) {
  str.toUpperCase();
  for (int i = 0; i < str.length(); i++) {
    switch(str[i]) {
      case 'A':
        turnOnChr(braille_grid[0]);
        break;
      case 'B':
        turnOnChr(braille_grid[1]);
        break;
      case 'C':
        turnOnChr(braille_grid[2]);
        break;
      case 'D':
        turnOnChr(braille_grid[3]);
        break;
      case 'E':
        turnOnChr(braille_grid[4]);
        break;
      case 'F':
        turnOnChr(braille_grid[5]);
        break;
      case 'G':
        turnOnChr(braille_grid[6]);
        break;
      case 'H':
        turnOnChr(braille_grid[7]);
        break;
      case 'I':
        turnOnChr(braille_grid[8]);
        break;
      case 'J':
        turnOnChr(braille_grid[9]);
        break;
      case 'K':
        turnOnChr(braille_grid[10]);
        break;
      case 'L':
        turnOnChr(braille_grid[11]);
        break;
      case 'M':
        turnOnChr(braille_grid[12]);
        break;
      case 'N':
        turnOnChr(braille_grid[13]);
        break;
      case 'O':
        turnOnChr(braille_grid[14]);
        break;
      case 'P':
        turnOnChr(braille_grid[15]);
        break;
      case 'Q':
        turnOnChr(braille_grid[16]);
        break;
      case 'R':
        turnOnChr(braille_grid[17]);
        break;
      case 'S':
        turnOnChr(braille_grid[18]);
        break;
      case 'T':
        turnOnChr(braille_grid[19]);
        break;
      case 'U':
        turnOnChr(braille_grid[20]);
        break;
      case 'V':
        turnOnChr(braille_grid[21]);
        break;
      case 'W':
        turnOnChr(braille_grid[22]);
        break;
      case 'X':
        turnOnChr(braille_grid[23]);
        break;
      case 'Y':
        turnOnChr(braille_grid[24]);
        break;
      case 'Z':
        turnOnChr(braille_grid[25]);
        break;
      case '0':
        turnOnChr(braille_grid[26]);
        break;
      case '1':
        turnOnChr(braille_grid[27]);
        break;
      case '2':
        turnOnChr(braille_grid[28]);
        break;
      case '3':
        turnOnChr(braille_grid[29]);
        break;
      case '4':
        turnOnChr(braille_grid[30]);
        break;
      case '5':
        turnOnChr(braille_grid[31]);
        break;
      case '6':
        turnOnChr(braille_grid[32]);
        break;
      case '7':
        turnOnChr(braille_grid[33]);
        break;
      case '8':
        turnOnChr(braille_grid[34]);
        break;
      case '9':
        turnOnChr(braille_grid[35]);
        break;
      case '.':
        turnOnChr(braille_grid[36]);
        break;
      case ',':
        turnOnChr(braille_grid[37]);
        break;
      case ';':
        turnOnChr(braille_grid[38]);
        break;
      case ':':
        turnOnChr(braille_grid[39]);
        break;
      case '/':
        turnOnChr(braille_grid[40]);
        break;
      case '?':
        turnOnChr(braille_grid[41]);
        break;
      case '!':
        turnOnChr(braille_grid[42]);
        break;
      case '@':
        turnOnChr(braille_grid[43]);
        break;
      case '#':
        turnOnChr(braille_grid[44]);
        break;
      case '+':
        turnOnChr(braille_grid[45]);
        break;
      case '-':
        turnOnChr(braille_grid[46]);
        break;
      case '*':
        turnOnChr(braille_grid[47]);
        break;
      case '\"':
        turnOnChr(braille_grid[48]);
        break;
      case '\'':
        turnOnChr(braille_grid[49]);
        break;
      case '<':
        turnOnChr(braille_grid[50]);
        break;
      case '>':
        turnOnChr(braille_grid[51]);
        break;
      case '(':
        turnOnChr(braille_grid[52]);
        break;
      case ')':
        turnOnChr(braille_grid[53]);
        break;
      default:
        break;
    }
  }
}

void loop() {
  bool clear = do_read();
  int index = match();
  int cnt = true_presses();

  if (cnt > last_count) {
    last_count = cnt;
    if (index > -1) {
      last_char = characters[index];
    } else {
      last_char = '\0';
    }
  }

  if (cnt == 0 && last_count != 0) {

    if (last_char != '\0') {
      Serial.print("Keypress: ");
      Serial.println(last_char);
    }   

    last_count = 0;
    last_char = '\0';
  }

  // read data from Bluetooth
  String text = "";
  while (Serial.available()) {
    text += char(Serial.read());
  }

  // display text
  turnOnStr(text);
}