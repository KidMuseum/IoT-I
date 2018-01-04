// Start by assigining your pins using variables

int bell = D1;
int button = D0;

//create a variable to tell us if our button is on or off
int buttonState;

//Create an array of notes to play consequtively and the timing between them

int melody[] = { 440, 494, 131};
int duration[] = {4, 4, 4};


void setup() {
  // initialize all your pins to either inputs or outputs. In this case the button is an input and the buzzer is an output
  pinMode(bell, OUTPUT);
  pinMode(button, INPUT);

  // We will subscribe to the particle cloud looking for a specific event
  Particle.subscribe("KM/Elvin/bell". handleRingDoorbell);
}

void loop() {

  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void handleRingDoorbell(){
  doRingDoorbell();
}

void doRingDoorbell() {

  for (int thisNote = 0; thisNote < 2; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);

}
