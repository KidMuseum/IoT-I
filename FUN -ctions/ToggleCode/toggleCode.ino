//
int toggleButton = D3;

int toggleButtonState = LOW;
int lasttoggleButtonState = LOW;
int currenttoggleButtonState = LOW;

void setup(){
  //Initialize the pins as "INPUT_PULLUP"s. This makes it so that you don't need to have a pull up resistor in your
  //circuit

  pinMode(toggleButton, INPUT_PULLUP);
}


int toggle() {
  currenttoggleButtonState = digitalRead(startButton);
  if (currenttoggleButtonState == LOW && lasttoggleButtonState == HIGH){
    if(toggleButtonState == HIGH)
      toggleButtonState = LOW;

    else
      toggleButtonState = HIGH;
  }

  lasttoggleButtonState = currenttoggleButtonState;
  return toggleButtonState;
}
