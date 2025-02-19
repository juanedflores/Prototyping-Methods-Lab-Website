---
heading: Button
---

# Button

## How does a button work?

The button is just a simple way of completing or breaking a circuit with the simple act of "pushing" or "pressing" a button.

You could just manually join or unjoin two bare wires together to do this, but a button makes this a convenient way to interface (interact) with a circuit.

Often electronics kits come with a cheap tactile button that looks like this:

<div>
<img src="./images/button.png" width=400 style=""></img>
</div>

But it can take many forms and sizes.

<div>
<img src="./images/buttons.jpg" width=400 style=""></img>
</div>

Take a look at <a href="https://teenage.engineering/">Teenage Engineering</a>'s pocket operator products that use a similar looking tactile button.

<iframe style="background: black; margin-top:25px; padding-bottom:25px;" src="https://player.vimeo.com/video/935417234?h=6ec9ce8838?autoplay=1&loop=1" width="1920" height="1080" allowfullscreen uk-responsive uk-video="automute: true; autoplay: true; loop: true"></iframe>
And a case that would cover the look of those buttons:

<div>
<img src="https://images.prismic.io/teenageengineering/83dc95b0-467b-4637-a60c-df6f4833505f_ca-x_yellow.png?auto=compress,format&w=2000" width=600 style=""></img>
</div>

---

## Pinout

### Switches

First it might help to explain that a button is essentially a push **switch**.

The schematic symbol of a generic switch is intuitive. This shows a switch that is open, meaning that the circuit is broken. Current _CANNOT_ pass through the wire.

<div>
<img src="./images/switch_open.svg" width=400 style="border: none;"></img>
</div>

This symbol shows the switch closed, meaning that the circuit is complete. Current _CAN_ pass through the wire.

<div>
<img src="./images/switch_closed.svg" width=400 style="border: none; padding-top:20px; padding-bottom:20px"></img>
</div>

This is how an On-Off switch works. It is a **toggle** switch.

<div>
<img src="./images/switch.jpeg" width=400 style=""></img>
</div>


### Toggle vs. Push

Try interacting with the switch in this simulation showing a simple led-resistor circuit with a generic switch. (You may need to click the "RUN / Stop" button)

<iframe style="padding-top:25px;" id="circuitFrame" src="../../CircuitJS/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgoqoQFMBaMMAKADcRsEUQAWOTtxBo8UMf2pUp0BCwDOgniIoZCw-GKoAzAIYAbOXRZhCPBKvWjza-lR4ATOroCuegC4M9de+E1RYrABOKjYCXDy2YmDwLEA" width="800" height="550" uk-responsive></iframe>

The next simulation is using a push switch instead (push button). Notice the difference.

<iframe style="padding-top:25px;" id="circuitFrame" src="../../CircuitJS/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgoqoQFMBaMMAKADcRsEUQAWOTtxBo8UMf2pUp0BCzCEeCDIWH4KyvgJ4ATOgDMAhgFcANgBcGJutvBjpkVgCd1K-lS483YsPBYBnQR4RF1VRKggzRyM6FiA
" width="800" height="550" uk-responsive></iframe>

As you can see, the circuit is complete ONLY so long as the button is pressed.

The schematic symbol for a push button looks a bit different but makes sense when you think about it.

<div>
<img src="./images/button_schematic.png" width=500 style=""></img>
</div>

The two wires on the left and right are connected when the plate above them is pushed down.

### The button pins

The button has 4 pins which makes this a bit confusing.

<div>
<img src="./images/pinout.gif" width=300 style=""></img>
</div>

Here is a screenshot in Fritzing to show that the pins in red are connected whether the button is pressed or not. Same with the blue pins. They are **internally connected**.

<div>
<img src="./images/fritzing.jpg" width=400 style=""></img>
</div>

This means that when you press the button, the red and blue pins are connected together. It might seem hard to know which pins are internally connected. If you extend the legs as if the button was a squished bug on a flat surface, the legs point away from the button. The pins that follow the same line are internally connected.

---

## Circuit Demonstration

Let's do a circuit that turns an LED on when we press the button without any programming.

<div>
<img src="./images/button_analog.png" width=400 style=""></img>
</div>

First I connect the button so that it crosses over the middle of the breadboard. It might be easier to think of this middle line as a river, and the button as a bridge. Also notice that with the legs extended they resemble more like a bridge.

Next I placed an LED on one side of the button, with one leg (the cathode) connected to the right side of the bridge.

On the left side of the bridge I placed the current limiting resistor for the LED. This is connected to ground.

<div>
<img src="./images/button_analog2.png" width=400 style=""></img>
</div>

The last step would be to connect the positive rail to the <span style="color:red">**anode**</span>.

Pressing the button should now light up the LED. This is because when you press the button, you are **completing the circuit**. When you release, you are **breaking** the circuit.

<div>
<img src="./images/tinkercad1.png" width=600 style=""></img>
</div>

By the way, because we have power going through each side of the power rails, an alternative way of wiring this is like this:

<div>
<img src="./images/tinkercad2.png" width=600 style=""></img>
</div>

Do you see why this completes the circuit?

---

## The Button Sketch

Go to:

**File** > **Examples** > **02.Digital** > **Button**

This is `Button.ino`.

Of course we should always look at the link provided in the block comment:

[https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button)

<div>
<img src="https://docs.arduino.cc/static/fb8449b4834dfbbf3c03223c8bc3e5b5/29114/schematic.png" width=100% style=""></img>
</div>

It is using the UNO, but the wiring is pretty much the same.

We are connecting one side of the switch to (+) (In our case, 3.3V).

<div>
<img src="./images/button_sketch1.png" width=400 style=""></img>
</div>

And the other side to a 10k Ohm Resistor.

<blockquote class="warning">
<span class="uk-label uk-label-warning">Warning</span>
<p>The images show a resistor with color bands of a 220 ohm resistor, but it should be 10k.</p>
</blockquote>

<div>
<img src="./images/10k.png" width=100% style=""></img>
</div>

<div>
<img src="./images/button_sketch2.png" width=400 style=""></img>
</div>

This other side of the button is ALSO connected to digital pin 2.

<div>
<img src="./images/button_sketch3.png" width=400 style=""></img>
</div>

Lastly, the other side of the resistor is connected to **Ground**.

<div>
<img src="./images/button_sketch4.png" width=400 style=""></img>
</div>

Pressing the button should turn on the built-in LED. You can confirm this by connecting an LED to pin 13 like how we did in the Blink example.

---

## In TinkerCAD

In TinkerCAD, it comes with some premade circuits with the Arduino Code.

You can find it in the dropbar menu on the right hand side:

<div>
<img src="./images/tinkercad_categories.png" width=400 style=""></img>
</div>

This is the Button example:

<div>
<img src="./images/tinker_cad_button2.png" width=100% style=""></img>
</div>

Redrawn to fit in a breadboard like we did with the Nano:

<div>
<img src="./images/tinker_cad_button.png" width=100% style=""></img>
</div>

To find the code editor:

<div>
<img src="./images/tinkercad_code.png" width=400 style=""></img>
</div>

The first thing you will see is a block code editor similar to the [Scratch Programming Language](https://scratch.mit.edu/).

<div>
<img src="./images/scratch.png" width=500 style=""></img>
</div>

To go to the text version of the code, like what we would see in the Arduino IDE. Select "Text" from this dropbar menu:

<div>
<img src="./images/text.png" width=500 style=""></img>
</div>

You can enter the **Button** example here: 

<div>
<img src="./images/text2.png" width=500 style=""></img>
</div>

And click "Start Simulation" to see if it works by pushing the button.

