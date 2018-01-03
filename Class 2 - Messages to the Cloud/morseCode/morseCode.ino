//We need o start by assigning pins as always

int dashButton = D2;
int dotButton = D0;

void setup(){
  pinMode(dashbutton, INPUT_PULLUP);
  pinMode(dotbutton, INPUT_PULLUP);

  Particle.function("led", ledControl);
  Particle.subscribe("led",ledcontrol);
  // Make the variable 'ledValue' available through
  // the Particle cloud as 'brightness'
  Particle.variable("brightness", &ledValue, INT);
}

void loop(){

}

void ledControl() {



}

void handleDoorbellPush(const char *event, const char *data)
{
    doDingDong();

}
