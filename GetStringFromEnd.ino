String getLineFromEnd(unsigned int LineFromEnd, File myFile) {//prefered Way(no external File, excact Line readout, less dynamic storage usage)---------------------
  //unsigned int LineFromEnd - lines from end, File myFile - file opened in read mode
  //reads character from end until wanted line is found
  String reverseRead = "";
  String output = "";
  char cr;
  unsigned long Filesize = myFile.size();
  unsigned int countLine = 0;
  unsigned int countCharacter = 0;
  while (true) { //loops until Line amount has been reached
    myFile.seek(Filesize - countCharacter);//jumps to next charcter, read from end
    cr = myFile.read();
    if (cr == '\n') {
      countLine++;
    }
    if (LineFromEnd < countLine) {
      break;
    }
    else {
      reverseRead += cr;
    }
    countCharacter++;
  }
  for (int i = 0; i < reverseRead.length()-1; i++) { //unreverse the read input
    output += reverseRead[reverseRead.length() - i];
  }
  return output;
}

/* Call like Following
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  myFile = SD.open(FileName, FILE_READ);
  if (myFile) {
    Serial.println(getLineFromEnd(2 , myFile));
  }

*/



String getLineFromEnd(unsigned int linefromEnd, File myFile, unsigned int ReflineNumber, File RefFile) {//external File is needed
  //ex. to get last line from myFile set linefromEnd = 0
  //unsigned int linefromEnd - (lastline - linefromEnd), File myFile - file to get line from,
  // unsigned int ReflineNumber - line where length of myFile is safed, File RefFile - length of myFile is safed
  //see library for explanation for referece file
  int myFileSize =  getLineLength(ReflineNumber, RefFile); //looks up reference file, where length of myFile is saved
  String output = getLineAt(myFileSize - linefromEnd, myFile); //gets line from myFile
  return output;
}


String getCharactersFromEnd(unsigned int charactersFromEnd, File myFile) {//only possible for amount of characters possible - NOT LINE
  //unsigned int charactersFromEnd - charactersFromEnd, File myFile - file to get line from
  //see library for explanation for referece file
  String output = "";
  char cr;
  unsigned long Filesize = myFile.size();
  myFile.seek(Filesize-charactersFromEnd); //sets pointer
  for(int i =Filesize-charactersFromEnd; i <Filesize; i++) {
    cr = myFile.read();
    output += cr;
  }
  return output;
}
