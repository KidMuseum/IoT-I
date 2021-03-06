//As always we first assign the pins to variables
//Add the buzzer pin
int button = D0;
int buzzer = D1;

//then we store the state of the button using a variables
int buttonState;

//Add our musical arrays here
int melody[] = { 100, 100, 100, 100, 100, 100, 100, 100};
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};// note durations: 4 = quarter note, 8 = eighth note, etc.:

void setup(){
//Then initialize all the pins on your board as INPUTs or OUTPUTs
pinMode(button, INPUT_PULLUP);
pinMode(buzzer, OUTPUT);

//now we can suscribe to the event that we posted
//when it sees that the message has been published we can tell it to run a handler function
Particle.subscribe("KM/Elvin/bell", handleDoorbellSound);
}

void loop(){
//Now we get to start sending messages to the cloud!
//first we read the button
  buttonState = digitalRead(button);
  if(buttonState == LOW)
//This tells us if the button is pressed(LOW) then send the publish
//this message for every particle in the world to see
//The reason the message is so long is because there are tons of messages flying
//around and we need to make ours as unique as possible
    Particle.publish ("KM/Elvin/bell");
//Test it here with the kids what you'll get is a lot of publishes with one push!
//its important to have a delay after the publish so that you only send one
    delay(2500);
}

//Now we are going to make a function to receive that message
//First add the buzzer pins and initialize them
//Then we'll make a program that plays the doorbell noise

void doDoorbellSound(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(buzzer, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzer);
  }
}

void handleDoorbellSound(const char *event, const char *data){

  doDoorbellSound();

}
