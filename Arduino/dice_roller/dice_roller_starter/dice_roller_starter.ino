const int dice_roll = 0;

int led_pin1 = 12;
int led_pin2 = 11;
int led_pin3 = 10;
int led_pin4 = 9;
int led_pin5 = 8;
int led_pin6 = 7;

void setup() {
  Serial.begin(9600);

  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT);
}

void loop() {
  dice_roll = random(6);

  if (dice_roll == 0) {
    digitalWrite(led_pin1, HIGH);
  } else if (dice_roll == 1) {
    digitalWrite(led_pin2, HIGH);
  } else if (dice_roll == 2) {
    digitalWrite(led_pin3, HIGH);
  } else if (dice_roll == 3) {
    digitalWrite(led_pin4, HIGH);
  } else if (dice_roll == 4) {
    digitalWrite(led_pin5, HIGH);
  } else if (dice_roll == 5) {
    digitalWrite(led_pin6, HIGH);
  }

  // turn on for one second
  delay(1000);

  // reset LEDs
  digitalWrite(led_pin1, LOW);
  digitalWrite(led_pin2, LOW);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
}