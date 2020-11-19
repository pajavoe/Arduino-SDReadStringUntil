
String readFromSD(String FileName, char PinStartPoint[], char PinEndPoint[]) {
  //String FileName - name of File, String PinStartPoint - keyword from where to start
  //String PinEndPoint - keyword where to end
  //chipSelectPIN - pin where CS is connected to 
  File myFile;
  String ReadText;
  if (!SD.begin(chipSelectPIN)) {
    Error("Error 001: SD Card initialization failed!");
    while (1);
  }
  myFile = SD.open(FileName); //open file in read mode
  if (myFile) {
    while (myFile.available()) {
      //reads from SD from PinStartPoint to PinEndPoint
      findCharacters(PinStartPoint, myFile);
      ReadText = findCharacters(PinEndPoint, myFile);
      break;
    }
    myFile.close();// close the file:
  }
  else {
    // if the file didn't open, print an error:
    Error("Error 003: SD Card error opening File");
  }
  return ReadText;
}


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
      if (pos ==  strlen(toFind)-1) {
        readBuf = false;
      }
      pos++; // jumps to next character
    }
    else {
      pos = 0;//reset if not found
    }
  }
  return returnString;
}
