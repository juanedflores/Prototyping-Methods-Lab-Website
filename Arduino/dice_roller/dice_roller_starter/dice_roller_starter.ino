int dice_roll = 0;
int buttonState = 0;

const int button_pin = 2;


const int led_pin1 = 12;
const int led_pin2 = 11;
const int led_pin3 = 10;
const int led_pin4 = 9;
const int led_pin5 = 8;
const int led_pin6 = 7;
const int led_pin7 = 6;

void display_dice() {
  if (dice_roll == 0) {
    digitalWrite(6, HIGH);
  } else if (dice_roll == 1) {
    digitalWrite(12, HIGH);
    digitalWrite(7, HIGH);
  } else if (dice_roll == 2) {
    digitalWrite(12, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
  } else if (dice_roll == 3) {
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(7, HIGH);
  } else if (dice_roll == 4) {
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
  } else if (dice_roll == 5) {
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
  }
}

void reset_dice() {
  // reset LEDs
  digitalWrite(led_pin1, LOW);
  digitalWrite(led_pin2, LOW);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
  digitalWrite(led_pin7, LOW);
}

void setup() {
  pinMode(button_pin, INPUT);
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT);
  pinMode(led_pin7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(button_pin);

  if (buttonState == HIGH) {
    dice_roll = random(6);

    display_dice();
    delay(100);

  } else {
    display_dice();
    Serial.println(dice_roll);
  }
}