---
title: Week 4
---

# Dice Roller

## Background

<iframe style="background: black; margin-top:25px; padding-bottom:25px;" src="https://www.youtube-nocookie.com/embed/Q2bSSRIU0WQ?autoplay=0&amp;showinfo=0&amp;rel=0&amp;modestbranding=1&amp;playsinline=1" width="1920" height="1080" allowfullscreen uk-responsive uk-video="automute: true; autoplay: false"></iframe>

One of the classic analog electronics projects was to make a dice roller using **Integrated Circuits** (ICs) like the 555 timer.

We technically know everything (almost everything) to get a very basic version of a dice roller by:

- Hooking up 9 LED outputs.
- Hooking up a button input.
- Using the random() function to get a random number between 1 and 9.

The last thing to learn is something called an `if statement`.

## If statements

Look at Arduino documentation: [https://docs.arduino.cc/built-in-examples/control-structures/ifStatementConditional/](https://docs.arduino.cc/built-in-examples/control-structures/ifStatementConditional/).

## The Challenge

See if you can figure out how to write this code yourself. I'll be helping along and giving hints.

## The Starting Codee

```c
int dice_roll = 1;

void setup() {
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    dice_roll = random(9) + 1;

    if (dice_roll == 1) {
        Serial.println("You rolled a 1");
        digitalWrite(13, HIGH);
    }
    if (dice_roll == 2) {
        Serial.println("You rolled a 2");
        digitalWrite(12, HIGH);
    }
    if (dice_roll == 3) {
        Serial.println("You rolled a 3");
        digitalWrite(11, HIGH);
    }
    if (dice_roll == 4) {
        Serial.println("You rolled a 4");
        digitalWrite(10, HIGH);
    }
    if (dice_roll == 5) {
        Serial.println("You rolled a 5");
        digitalWrite(9, HIGH);
    }
    if (dice_roll == 6) {
        Serial.println("You rolled a 6");
        digitalWrite(8, HIGH);
    }
    if (dice_roll == 7) {
        Serial.println("You rolled a 7");
        digitalWrite(7, HIGH);
    }
    if (dice_roll == 8) {
        Serial.println("You rolled a 8");
        digitalWrite(6, HIGH);
    }
    if (dice_roll == 9) {
        Serial.println("You rolled a 9");
        digitalWrite(5, HIGH);
    }

    Serial.println(dice_roll);
    delay(1000);

    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
}

```
