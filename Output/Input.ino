#define BUTTON_ZERO A0
#define BUTTON_ONE A1
#define BUTTON_TWO A2
#define BUTTON_THREE A3
#define BUTTON_FOUR A4
#define BUTTON_FIVE A5

#define VIBE_ZERO 5 //3
#define VIBE_ONE 6 //5
#define VIBE_TWO 7
#define VIBE_THREE 8
#define VIBE_FOUR 9 //10
#define VIBE_FIVE 10 //11

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
  // delay(5000);
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

  // for (int i = 0; i < 53; i++) {
  //   Serial.print(i);
  //   Serial.print(" ");
  //   for (int j = 0; j < 6; j++) {
  //       Serial.print(braille_grid[i][j]);
  //       Serial.print(",");
  //   }
  //   Serial.print(characters[i]);
  //   Serial.println();
  // }
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
  
  // zero_press = digitalRead(BUTTON_ZERO);
  // one_press = digitalRead(BUTTON_ONE);
  // two_press = digitalRead(BUTTON_TWO);
  // three_press = digitalRead(BUTTON_THREE);
  // four_press = digitalRead(BUTTON_FOUR);
  // five_press = digitalRead(BUTTON_FIVE);
  presses[0] = digitalRead(BUTTON_ZERO);
  presses[1] = digitalRead(BUTTON_ONE);
  presses[2] = digitalRead(BUTTON_TWO);
  presses[3] = digitalRead(BUTTON_THREE);
  presses[4] = digitalRead(BUTTON_FOUR);
  presses[5] = digitalRead(BUTTON_FIVE);
  
  bool buttons_clear = !(presses[0] | presses[1] | presses[2] |
                         presses[3] | presses[4] | presses[5]);

  // bool buttons_clear = !(zero_press | one_press | two_press | three_press |
  //                  four_press | five_press);

  if (buttons_clear) {
    for (int i = 0; i < 6; i++) {
      presses[i] = false;
    }
    // zero_press = false;
    // one_press = false;
    // two_press = false;
    // three_press = false;
    // four_press = false;
    // five_press = false;
  }

  return buttons_clear;
}

int match() {
  bool found_match = true;
  for (int i = 0; i < 53; i++) {
    for (int j = 0; j < 6; j++) {
      if (presses[j] != braille_grid[i][j]) {
        // Serial.print(presses[j]);
        // Serial.print(" ");
        // Serial.print(braille_grid[i][j]);
        // Serial.print(",");
        found_match = false;
        break;
      }
    }
    // Serial.println();
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












void loop() {
  bool clear = do_read();

  // Serial.print(presses[0]);
  // Serial.print("  ");  
  // Serial.print(presses[1]);
  // Serial.print("  ");
  // Serial.print(presses[2]);
  // Serial.print("  ");
  // Serial.print(presses[3]);
  // Serial.print("  ");
  // Serial.print(presses[4]);
  // Serial.print("  ");
  // Serial.print(presses[5]);
  // Serial.print("  ");
  // Serial.print(clear ? "Clear    " : "Pressed  ");
  // // Serial.println();
  
  // presses[0] = true;
  // presses[1] = false;
  // presses[2] = true;
  // presses[3] = false;
  // presses[4] = false;
  // presses[5] = false;
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

  // Serial.print(index);
  // // Serial.println();
  // Serial.print(" ");
  // Serial.println((index >= 0) ? characters[index] : '\0');
}