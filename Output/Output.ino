#include <math.h>
#include <stdint.h>

/*
  PennApps Fall 2015
  Braille Output onto Arduino Micro
*/

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

/* // pins of 6 dot array */
/* const int ONE = 5; */
/* const int TWO = 6; */
/* const int THREE = 7; */
/* const int FOUR = 8; */
/* const int FIVE = 9; */
/* const int SIX = 10; */

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
  /* pinMode(ONE, OUTPUT); */
  /* pinMode(TWO, OUTPUT); */
  /* pinMode(THREE, OUTPUT); */
  /* pinMode(FOUR, OUTPUT); */
  /* pinMode(FIVE, OUTPUT); */
  /* pinMode(SIX, OUTPUT); */
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
  Serial.begin(9600);
}

// turn off all vibrations
void turnOffAll() {
  digitalWrite(VIBE_ZERO, LOW);
  digitalWrite(VIBE_ONE, LOW);
  digitalWrite(VIBE_TWO, LOW);
  digitalWrite(VIBE_THREE, LOW);
  digitalWrite(VIBE_FOUR, LOW);
  digitalWrite(VIBE_FIVE, LOW);
  delay(20);
}

// turn on specific character pattern on 6 dot array
void turnOnChr(const boolean *chr) {
  float fos = .5;
  if (chr[0]) analogWrite(VIBE_ZERO, (int)(255 * fos));
  if (chr[1]) analogWrite(VIBE_ONE, (int)(255 * fos));
  if (chr[2]) analogWrite(VIBE_TWO, (int)(255 * fos));
  if (chr[3]) analogWrite(VIBE_THREE, (int)(255 * fos));
  if (chr[4]) analogWrite(VIBE_FOUR, (int)(255 * fos));
  if (chr[5]) analogWrite(VIBE_FIVE, (int)(255 * fos));

  /* int currentPin = ONE; */

  /* for (int i = 0; i < 6; i++) { */
  /*   if (chr[i]) digitalWrite(currentPin, HIGH); */
  /*   currentPin++; */
  /* } */
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

QueueList<boolean> button_zero_presses;
QueueList<boolean> button_one_presses;
QueueList<boolean> button_two_presses;
QueueList<boolean> button_three_presses;
QueueList<boolean> button_four_presses;
QueueList<boolean> button_five_presses;

char lookup(int8_t input) {
  switch(input) {
    case 0x30://A
      return 'A';
    case 0x28:
      return 'B';
    default:
      return 0;
  }
  //we've got to switch on the input and compare to every output
}

void bluetooth_send(char to_send) {
  Serial.println(String(to_send));
  return;
}

void loop() {
  /* I/O loop, needs to read first, then display if anything is left */
  // low will be the button is pressed
  
  boolean is_clear = true;
  int read = digitalRead(BUTTON_ZERO);
  if ((bool)read) {is_clear = false;} else {
  button_zero_presses.push((boolean)digitalRead(BUTTON_ZERO)); }
  
  read = digitalRead(BUTTON_ONE); 
  if ((bool)read) {is_clear = false;} else {
  button_one_presses.push((boolean)digitalRead(BUTTON_ONE)); }
  
  read = digitalRead(BUTTON_TWO);
  if ((bool)read) {is_clear = false;} else {
  button_two_presses.push((boolean)digitalRead(BUTTON_TWO)); }
  
  read = digitalRead(BUTTON_THREE);
  if ((bool)read) {is_clear = false;} else {
  button_three_presses.push((boolean)digitalRead(BUTTON_THREE)); }
  
  read = digitalRead(BUTTON_FOUR);
  if ((bool)read) {is_clear = false;} else {
  button_four_presses.push((boolean)digitalRead(BUTTON_FOUR)); }
  
  read = digitalRead(BUTTON_FIVE);
  if ((bool)read) {is_clear = false;} else {
  button_five_presses.push((boolean)digitalRead(BUTTON_FIVE)); }

  if (is_clear) {
    boolean character[6];
    
    //count the character as an input
    //average each of the queues
    float average = 0;
    float count = 0;
    while(!button_zero_presses.isEmpty()) {
      average += (int)button_zero_presses.pop();
      count++;
    }
    character[0] = !(boolean)(int)round(average);
  
    average = 0;
    count = 0;
    while(!button_one_presses.isEmpty()) {
      average += (int)button_one_presses.pop();
      count++;
    }
    character[1] = !(boolean)(int)round(average);
  
    average = 0;
    count = 0;
    while(!button_two_presses.isEmpty()) {
      average += (int)button_two_presses.pop();
      count++;
    }
    character[2] = !(boolean)(int)round(average);

    average = 0;
    count = 0;
    while(!button_three_presses.isEmpty()) {
      average += (int)button_three_presses.pop();
      count++;
    }
    character[3] = !(boolean)(int)round(average);
    
    average = 0;
    count = 0;
    while(!button_four_presses.isEmpty()) {
      average += (int)button_four_presses.pop();
      count++;
    }
    character[4] = !(boolean)(int)round(average);

    average = 0;
    count = 0;
    while(!button_five_presses.isEmpty()) {
      average += (int)button_five_presses.pop();
      count++;
    }
    character[5] = !(boolean)(int)round(average);

    //now that we have our array created, we need to figure out
    //what it is equivalent to. This will be done with bits
    int8_t char_int = 0;
    for (int i = 0; i < 6; i++) {
      char_int << 1;
      char_int += (int)character[i];
    }

    char input = lookup(char_int);
    if (input != 0) {
      bluetooth_send(input);
    }
  }

  // read data from Bluetooth
  String text = "";
  while (Serial.available()) {
    text += char(Serial.read());
  }
//  Serial.println(text);
  // display text
  turnOnStr(text);
}

int getDistance(int trigPin, int echoPin, int delayTime)
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(delayTime);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = microsecondsToInches(duration);
  return distance;
}

long microsecondsToInches(long duration)
{
  return duration / 74 / 2;
}
