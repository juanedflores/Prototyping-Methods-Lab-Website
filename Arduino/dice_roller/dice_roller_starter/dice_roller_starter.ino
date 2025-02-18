int dice_roll = 1;
int buttonState = 0;
int lastButtonState = 0;

// input
int button_pin = 2;

// output
int led_pin1;
int led_pin2;
int led_pin3;
int led_pin4;
int led_pin5;
int led_pin6;

void setup() {
  Serial.begin(9600);
  pinMode(button_pin, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {

  buttonState = digitalRead(button_pin);


  if (dice_roll == 1) {
    Serial.println("You rolled a 1");
    digitalWrite(12, HIGH);
  }
  if (dice_roll == 2) {
    Serial.println("You rolled a 2");
    digitalWrite(11, HIGH);
  }
  if (dice_roll == 3) {
    Serial.println("You rolled a 3");
    digitalWrite(10, HIGH);
  }
  if (dice_roll == 4) {
    Serial.println("You rolled a 4");
    digitalWrite(9, HIGH);
  }
  if (dice_roll == 5) {
    Serial.println("You rolled a 5");
    digitalWrite(8, HIGH);
  }
  if (dice_roll == 6) {
    Serial.println("You rolled a 6");
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
  }
}
