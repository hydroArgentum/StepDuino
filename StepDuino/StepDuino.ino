//Modifier definitions.
#define LEFT_CTRL 0x01
#define LEFT_SHIFT 0x02
#define LEFT_ALT 0x04
#define LEFT_GUI 0x08
#define RIGHT_CTRL 0x10
#define RIGHT_SHIFT 0x20
#define RIGHT_ALT 0x40
#define RIGHT_GUI 0x80

//Special keyboard definitions.
#define RIGHT_ARROW 0x4F
#define LEFT_ARROW 0x50
#define DOWN_ARROW 0x51
#define UP_ARROW 0x52
#define ESC 0x29
#define F1 0x3A
#define F2 0x3B
#define F3 0x3C
#define F4 0x3D
#define F5 0x3E
#define F6 0x3F
#define F7 0x40
#define F8 0x41
#define F9 0x42
#define F10 0x43
#define F11 0x44
#define F12 0x45
#define PRTSCR 0x46
#define SCRLK 0x47
#define DEL 0x4C
#define INS 0x49
#define END 0x4D
#define HOME 0x4A
#define PGDN 0x4E
#define PGUP 0x4B
#define BACKSPC 0x2A
#define TAB 0x2B
#define ENTER 0x28
#define SPC 0x2C
#define MUTE 0x7F
#define VOL_UP 0x80
#define VOL_DOWN 0x81

//Pin definitions.
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5

//Define important constants.
#define KEY_A 0x04
#define KEY_S 0x16
#define KEY_K 0x0E
#define KEY_L 0x0F

/* The keyboard buffer is eight bytes.
 * The first byte represent modifiers.
 * We can assign multiple modifiers by
 * adding them together.
 * The second byte is not used.
 * The next six bytes represent a maximum
 * of six simultaneous keyboard presses.*/
uint8_t keyboardbuffer[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  //Setup serial.
  Serial.begin(9600);
  //Set input pins with pull-up resistor.
  pinMode(PIN_2, INPUT_PULLUP);
  pinMode(PIN_3, INPUT_PULLUP);
  pinMode(PIN_4, INPUT_PULLUP);
  pinMode(PIN_5, INPUT_PULLUP);
}

void loop() {
  if (PIND & 0x04){
    keyboardbuffer[3] = 0;
  }
  else{
    keyboardbuffer[3] = KEY_A;
  }
  if (PIND & 0x08){
    keyboardbuffer[4] = 0;
  }
  else{
    keyboardbuffer[4] = KEY_S;
  }
  if (PIND & 0x10){
    keyboardbuffer[5] = 0;
  }
  else{
    keyboardbuffer[5] = KEY_K;
  }
  if (PIND & 0x20){
    keyboardbuffer[6] = 0;
  }
  else{
    keyboardbuffer[6] = KEY_L;
  }
  Serial.write(keyboardbuffer, 8);
}
