String readVal(){
  myString = "";
  char keyPressed = Teclado1.getKey();
  while (keyPressed != '#'){
    keyPressed = Teclado1.getKey();
    if ((keyPressed != NO_KEY) && (keyPressed != '#')) {
      myString.concat(keyPressed);
      lcd.setCursor(pos_col,pos_fil);lcd.print(myString);
      
      }   
    }  
  return(myString);  
  }

void keypadEvent(KeypadEvent key) {
switch (Teclado1.getState()) {
case PRESSED:
if (key == '#') {
Serial.println(text);
text = "";
// key '#' sets the end of the text.
if (last_character != ' ') {
text += last_character;
}
endtext = true;
} else {
if (key == last_key_pressed) {
/* If the same key is pressed several times, with an interval of less than 2 seconds,
* it is considered "looking for the next character".
* If the interval is of more than 2 seconds, it is considered a new character
*/
difference = millis() - latter_time;
latter_time = millis();
if (difference > 2000) {
text += last_character;
byte indice;
/* For keys A, B, C and D, corresponding positions 10 to 14 of the keys array,
* the way of calculating the index is, when converting to integer,
* substracting the ASCII corresponding to '7', that leaves A as 10, B as 11, and so on.
*/
if (key > '9') {
indice = key - '7';
} else {
indice = key - '0';
}
last_character = letters[indice][0];
Serial.print("caracter: ");
Serial.println(last_character);
num_times_pressed = 1;
} else {
byte indice;
if (key > '9') {
indice = key - '7';
} else {
indice = key - '0';
}
last_character = letters[indice][num_times_pressed % 4];
Serial.print("caracter: ");
Serial.println(last_character);
num_times_pressed++;
}
} else {
last_key_pressed = key;
if (last_character != ' ') {
text += last_character;
}
byte indice;
if (key > '9') {
indice = key - '7';
} else {
indice = key - '0';
}
last_character = letters[indice][0];
Serial.print("caracter: ");
Serial.println(last_character);
num_times_pressed = 1;
latter_time = millis();
}
}
break;
}
}
