String findCharacters(char toFind[], File myFile) {
  //returns the String read from start till given end-string
  String returnString = "";
  boolean readBuf = true;
  char cr ; 
  int pos = 0;
  while (readBuf) {
    cr = myFile.read();
    returnString += cr;
    if (cr ==  toFind[pos]) { //check if in serched array
      if (pos == sizeof(toFind)) {
        readBuf = false;
      }
      pos++; // jump to next character
    }
    else {
      pos = 0;//reset if not found
    }
  }
  return returnString;
}

/* Call like following:
while (myFile.available()) {
      char Find[3] = "ASD";//string from where to start with 
      char Find1[3] = "ing";//string from where to end 
      findCharacters(Find, myFile);//serach for start string(dont display/safe)
      Serial.println(findCharacters(Find1, myFile));//give out string in betweeen
      break;
    }
*/
