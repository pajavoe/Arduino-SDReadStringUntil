

void WriteReplaceFromSD(String replaceString, String FileName, char PinStartPoint[], char PinEndPoint) {
  //String replaceString - text instead, String FileName - name of File,
  //String PinStartPoint - keyword from where to start replacing, String PinEndPoint - character where to end replacing
  //A replacement between characters can only have the length of characters that were present before
  //End of a line replacements can be as long as wanted (PinEndPoint = '\n')
  File myFile;
  File myFile1;
  char cr;
  int seekCounter = 0;
  if (!SD.begin(10)) {
    //Error("Error 001: SD Card initialization failed!");
    while (1);
  }
  myFile = SD.open(FileName); //open file in read mode
  if (myFile) {
    while (myFile.available()) {
      int pos = 0;
      while (1) {
        cr = myFile.read();
        seekCounter++;
        if (cr ==  PinStartPoint[pos]) { //check if in serched array
          if (pos == strlen(PinStartPoint) - 1) {
            break;
          }
          pos++; // jumps to next character
        }
        else {
          pos = 0;//reset if not found
        }
      }
      break;
    }
  }
  else {// if the file didn't open, print an error:
    //Error("Error 003: SD Card error opening File");
  }
  myFile.close(); // close the file
  myFile = SD.open(FileName, FILE_READ); //open file type in write mode
  int count = 0;
  while (1) {
    myFile.seek(seekCounter + count);
    cr = myFile.read();
    if (cr ==  '\n') { //check if in serched array
      break;
    }
    else {//goes through file and deletes all characters in range
      myFile.close();
      myFile = SD.open(FileName, (O_READ | O_WRITE)); //open file type in write mode
      myFile.seek(seekCounter + count);
      myFile.print('\0'); //remove character
      myFile.close();
      myFile = SD.open(FileName, FILE_READ); //open file type in write mode
    }
    count++;
  }
  myFile.close(); // close the file
  myFile = SD.open(FileName, (O_READ | O_WRITE)); //open file type in write mod
  myFile.seek(seekCounter);
  myFile.print(replaceString);//print the replacement string
  myFile.close(); // close the file
}
