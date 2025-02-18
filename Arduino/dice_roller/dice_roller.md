---
title: Week 4
---

# Dice Roller

## Background

<iframe style="background: black; margin-top:25px; padding-bottom:25px;" src="https://www.youtube-nocookie.com/embed/Q2bSSRIU0WQ?autoplay=0&amp;showinfo=0&amp;rel=0&amp;modestbranding=1&amp;playsinline=1" width="1920" height="1080" allowfullscreen uk-responsive uk-video="automute: true; autoplay: false"></iframe>

One of the popular analog electronics projects is to make an electric LED dice roller using **Integrated Circuits** (ICs) like a **555 timer** to "roll the dice", and a **counter** to count through a range of numbers. Both of these together act somewhat like a `random()` function.

Seen for some as a rite of passage for electronics tinkerers, we can create a simple version of a dice roller with the Arduino using what we already know.

So far we know how to:

- Hook up any number of LED outputs (We have a max number of 22 I/O pins). A dice has 6 possibilities. So we can use 6 LED digital outputs using `digitalWrite()`.
- Hooking up and reading from a button input using `digitalRead()`.
- Using the random() function to get a random number between 1 and 6.

## Wiring the LEDs

Let's start with wiring the 6 LEDs.

<div>
<img src="./images/dice_roller1.png" width=500 style=""></img>
</div>

<span><p style="text-align:center; color: #aeaeae"><i>6 LED outputs with Uno in TinkerCAD</i></p></span>

<div>
<img src="./images/dice_roller2.png" width=500 style=""></img>
</div>

<span><p style="text-align:center; color: #aeaeae"><i>6 LED outputs with Nano in Fritzing</i></p></span>

In these images I hooked up LEDs to pins 7 to 12.

```c
int led_pin1 = 12;
int led_pin2 = 11;
int led_pin3 = 10;
int led_pin4 = 9;
int led_pin5 = 8;
int led_pin6 = 7;

void setup() {
    pinMode(led_pin1, OUTPUT);
    pinMode(led_pin2, OUTPUT);
    pinMode(led_pin3, OUTPUT);
    pinMode(led_pin4, OUTPUT);
    pinMode(led_pin5, OUTPUT);
    pinMode(led_pin6, OUTPUT);
}

void loop() {
    digitalWrite(led_pin1, HIGH);
    digitalWrite(led_pin2, HIGH);
    digitalWrite(led_pin3, HIGH);
    digitalWrite(led_pin4, HIGH);
    digitalWrite(led_pin5, HIGH);
    digitalWrite(led_pin6, HIGH);
}
```

To test that all LEDs work we can manually make the state of all the used pins `HIGH` to light them all up.

<div>
<img src="./images/dice_roller3.png" width=500 style=""></img>
</div>

Again we can alternate the states to make sure that they do what we expect them to do.

```c
void loop() {
    digitalWrite(led_pin1, HIGH);
    digitalWrite(led_pin2, LOW);
    digitalWrite(led_pin3, HIGH);
    digitalWrite(led_pin4, LOW);
    digitalWrite(led_pin5, HIGH);
    digitalWrite(led_pin6, LOW);
}
```

<div>
<img src="./images/dice_roller4.png" width=500 style=""></img>
</div>

## Adding randomness and using the Serial Monitor

Now that we have LEDs. Let's try to randomly light up only one of the LEDs on every loop cycle.

First I will set aside the previous code with the LEDs for now to isolate just the randomness part.

We can create a variable called `dice_roll` that will hold the value of our generated random number. We can initialize it with a value of 0.

```c
int dice_roll = 0;
```

Next, within the `loop()` function, we can assign this variable a new random number each time the loop function runs.

```c
void loop() {
    dice_roll = random(6);
}
```

It would be nice to see each new random number. We can use the Serial Monitor for that. To start the use of the Serial Monitor we use `Serial.begin(9600)` in the `setup()` function.

```c
void setup() {
    Serial.begin(9600);
}
```

To print the value of `dice_roll`, we use `Serial.println()`.

```c
int dice_roll = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    dice_roll = random(6);

    // print the value of dice_roll to Serial Monitor
    Serial.println(dice_roll);
}
```

The last thing would be to add a `delay()` so that it prints and generates a new number after a certain amount of time. Let's say it should print a random number every second.

```c
delay(1000);
```

<ul uk-accordion style='pading-bottom: 5vh'> <li class='uk-close'>
<a id='code-file' class='uk-accordion-title' href='#'>Print Random Value to Serial Monitor</a>
<div class='uk-accordion-content' style='padding-bottom:20px; margin-bottom:20px'>

```c
int dice_roll = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    dice_roll = random(6);

    // print the value of dice_roll to Serial Monitor
    Serial.println(dice_roll);

    // add a delay so that it prints only after every second
    delay(1000);
}
```

What we should be seeing in the Serial Monitor is something like this:

<div>
<img src="./images/dice_roller5.png" width=400 style=""></img>
</div>

<span><p style="text-align:center; color: #aeaeae"><i>Printing Values 0-5</i></p></span>

</div>

---

## If Statements

Before we can combine both ideas together, we need to introduce something called **if statements**, or **conditional statements**.

If statements look a little similar to functions:

```c
if (condition) {
    // code in here is executed if condition is TRUE

}
```

Anything in the curly brackets is considered to be in that `if statement`, and only executes if the condition is `TRUE`.

For example:

- if the dice_roll value is equal to 1 -> light up led_pin1
- if the dice_roll value is equal to 2 -> light up led_pin2
- and so on

We can start with testing in the Serial Monitor:

```c
if (dice_roll == 0) {
    Serial.print("Dice Roll is 0");
}

```

This conditon `if (dice_roll == 0)` translates to english as: "If dice_roll value is 0, then ... {print 'Dice Roll is 0'}".

Let's test.

```c
int dice_roll = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    dice_roll = random(6);

    if (dice_roll == 0) {
        Serial.println("Dice Roll is 0");
    }

    // print the value of dice_roll to Serial Monitor
    Serial.println(dice_roll);

    // add a delay so that it prints only after every second
    delay(1000);
}
```

<div>
<img src="./images/dice_roller6.png" width=300 style=""></img>
</div>

We can also add an `else{}` after the `if(){}` in the case that we want it to do something if the condition is NOT true or FALSE:

```c
int dice_roll = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    dice_roll = random(6);

    if (dice_roll == 0) {
        Serial.print("Dice Roll is 0");
    } else {
        // print the value of dice_roll to Serial Monitor
        Serial.println(dice_roll);
    }

    // add a delay so that it prints only after every second
    delay(1000);
}
```

<div>
<img src="./images/dice_roller7.png" width=300 style=""></img>
</div>

The last part of possible thing we can add is an `else if` to more conditions after the initial condition is checked:

```c
void loop() {
    dice_roll = random(6);

    if (dice_roll == 0) {
        Serial.println("Dice Roll is 0");
    } else if (dice_roll == 1) {
        Serial.println("Dice Roll is 1");
    } else {
        Serial.println("Not 2 or 0");
    }
}
```

We  can do this for each of the 6 (or 7) possibilities.

```c
void loop() {
    dice_roll = random(6);

    if (dice_roll == 0) {
        Serial.println("Dice Roll is 0");
    } else if (dice_roll == 1) {
        Serial.println("Dice Roll is 1");
    } else if (dice_roll == 2) {
        Serial.println("Dice Roll is 2");
    } else if (dice_roll == 3) {
        Serial.println("Dice Roll is 3");
    } else if (dice_roll == 4) {
        Serial.println("Dice Roll is 4");
    } else if (dice_roll == 5) {
        Serial.println("Dice Roll is 5");
    } else {
        Serial.println("Not in range");
    }
}
```

This block translates to english as: "if dice_roll value is 0, print 'Dice Roll is 0', else if dice_roll value is 1, print 'Dice Roll is 1. ... and so on".

<div>
<img src="./images/dice_roller8.png" width=300 style=""></img>
</div>

## Randomly Light up One LED

Now we can combine all ideas together.

We can simply replace all the `Serial.println()` lines with `digitalWrite()` lines:

```c
int dice_roll = 0;

int led_pin1 = 12;
int led_pin2 = 11;
int led_pin3 = 10;
int led_pin4 = 9;
int led_pin5 = 8;
int led_pin6 = 7;

void setup() {
    Serial.begin(9600);
}

void loop() {
    dice_roll = random(6);

    pinMode(led_pin1, OUTPUT);
    pinMode(led_pin2, OUTPUT);
    pinMode(led_pin3, OUTPUT);
    pinMode(led_pin4, OUTPUT);
    pinMode(led_pin5, OUTPUT);
    pinMode(led_pin6, OUTPUT);

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
    } else {
        Serial.println("Not in range");
    }

    // add a delay so that it prints only after every second
    delay(1000);
}
```

Uploading this code reveals a problem. LEDs start to light up one by one but they never turn off. We need to turn off all the remaining lights off each loop. The tedious, hard-coded way is to do this:

```c
int dice_roll = 0;

int led_pin1 = 12;
int led_pin2 = 11;
int led_pin3 = 10;
int led_pin4 = 9;
int led_pin5 = 8;
int led_pin6 = 7;

void setup() {
    Serial.begin(9600);
}

void loop() {
    dice_roll = random(6);

    pinMode(led_pin1, OUTPUT);
    pinMode(led_pin2, OUTPUT);
    pinMode(led_pin3, OUTPUT);
    pinMode(led_pin4, OUTPUT);
    pinMode(led_pin5, OUTPUT);
    pinMode(led_pin6, OUTPUT);

    if (dice_roll == 0) {
        digitalWrite(led_pin1, HIGH);
        digitalWrite(led_pin2, LOW);
        digitalWrite(led_pin3, LOW);
        digitalWrite(led_pin4, LOW);
        digitalWrite(led_pin5, LOW);
        digitalWrite(led_pin6, LOW);
    } else if (dice_roll == 1) {
        digitalWrite(led_pin2, HIGH);
        digitalWrite(led_pin1, LOW);
        digitalWrite(led_pin3, LOW);
        digitalWrite(led_pin4, LOW);
        digitalWrite(led_pin5, LOW);
        digitalWrite(led_pin6, LOW);
    } else if (dice_roll == 2) {
        digitalWrite(led_pin3, HIGH);
        digitalWrite(led_pin1, LOW);
        digitalWrite(led_pin2, LOW);
        digitalWrite(led_pin4, LOW);
        digitalWrite(led_pin5, LOW);
        digitalWrite(led_pin6, LOW);
    } else if (dice_roll == 3) {
        digitalWrite(led_pin4, HIGH);
        digitalWrite(led_pin1, LOW);
        digitalWrite(led_pin2, LOW);
        digitalWrite(led_pin3, LOW);
        digitalWrite(led_pin5, LOW);
        digitalWrite(led_pin6, LOW);
    } else if (dice_roll == 4) {
        digitalWrite(led_pin5, HIGH);
        digitalWrite(led_pin1, LOW);
        digitalWrite(led_pin2, LOW);
        digitalWrite(led_pin3, LOW);
        digitalWrite(led_pin4, LOW);
        digitalWrite(led_pin6, LOW);
    } else if (dice_roll == 5) {
        digitalWrite(led_pin6, HIGH);
        digitalWrite(led_pin1, LOW);
        digitalWrite(led_pin2, LOW);
        digitalWrite(led_pin3, LOW);
        digitalWrite(led_pin4, LOW);
        digitalWrite(led_pin5, LOW);
    } else {
        Serial.println("Not in range");
    }

    // add a delay so that it prints only after every second
    delay(1000);
}
```

Uploading this code shows that it works as we wanted, but the amount of lines of code quickly grew and became overwhelming.

## The Challenge

See if you can figure out how to write this code yourself. I'll be helping along and giving hints.

## The Starting Code

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

## Adding State Change Detection

Check out the `StateChangeDetection` example.

**File** > **Examples** > **Digital** > **StateChangeDetection**

```c
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
int led_pin7;
int led_pin8;
int led_pin9;

void setup() {
    Serial.begin(9600);
    pinMode(button_pin, INPUT);
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop() {

    buttonState = digitalRead(button_pin);

    // This block of code from StateChangeDetection example
    if (buttonState != lastButtonState) {
        // if the state has changed, increment the counter
        if (buttonState == HIGH) {
            Serial.println("on");
            dice_roll = random(9) + 1;
            Serial.println(dice_roll);
        } else {
            // if the current state is LOW then the button went from on to off:
            Serial.println("off");
            dice_roll = 0;
        }
        // Delay a little bit to avoid bouncing
        delay(50);
    }
    lastButtonState = buttonState;


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
