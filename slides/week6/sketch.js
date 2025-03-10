let angle = 0;
let speed = 0.1;
let l_wing_y_pos;
let r_wing_y_pos;
let wing_amplitude = 7;

function setup() {
  createCanvas(400, 400);
  angleMode(RADIANS);
  strokeWeight(3);
}

function draw() {
  background(220);

  r_wing_y_pos = sin(angle) * wing_amplitude + 200;
  l_wing_y_pos = sin(angle) * wing_amplitude + 200;

  line(200, 200, 180, l_wing_y_pos);
  line(200, 200, 220, r_wing_y_pos);

  angle += speed;

  // textSize(30);
  // text('y_pos: ' + round(y_pos, 2), 40, height - 50);
}
