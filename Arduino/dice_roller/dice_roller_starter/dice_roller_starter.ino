int picked_led = 0;
int buttonState = 0;

const int button_pin = 2;

const int led_pin1 = 12;
const int led_pin2 = 11;
const int led_pin3 = 10;
const int led_pin4 = 9;
const int led_pin5 = 8;
const int led_pin6 = 7;

void setup() {
    pinMode(button_pin, INPUT);
    pinMode(led_pin1, OUTPUT);
    pinMode(led_pin2, OUTPUT);
    pinMode(led_pin3, OUTPUT);
    pinMode(led_pin4, OUTPUT);
    pinMode(led_pin5, OUTPUT);
    pinMode(led_pin6, OUTPUT);
}

void loop() {
    buttonState = digitalRead(button_pin);

    if (buttonState == HIGH) {
        picked_led = random(7, 13);

        // show random selections while pressed
        digitalWrite(picked_led, HIGH);
        delay(40);

        // reset LEDs
        digitalWrite(led_pin2, LOW);
        digitalWrite(led_pin3, LOW);
        digitalWrite(led_pin4, LOW);
        digitalWrite(led_pin5, LOW);
        digitalWrite(led_pin6, LOW);
        digitalWrite(led_pin1, LOW);
    } else {
        digitalWrite(picked_led, HIGH);
    }
}