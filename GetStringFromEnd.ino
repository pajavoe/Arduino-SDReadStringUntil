
String getLineFromEnd(unsigned int linefromEnd, File myFile, unsigned int ReflineNumber, File RefFile) {
  //ex. to get last line from myFile set linefromEnd = 0
  //unsigned int linefromEnd - (lastline - linefromEnd), File myFile - file to get line from,
  // unsigned int ReflineNumber - line where length of myFile is safed, File RefFile - length of myFile is safed
  //see library for explanation for referece file
  int myFileSize =  getLineLength(ReflineNumber, RefFile); //looks up reference file, where length of myFile is saved
  String output = getLineAt(myFileSize - linefromEnd, myFile); //gets line from myFile
  return output;
}


String getCharactersFromEnd(unsigned int charactersFromEnd, File myFile) {
  //unsigned int charactersFromEnd - charactersFromEnd, File myFile - file to get line from,
  // unsigned int ReflineNumber - line where length of myFile is safed, File RefFile - length of myFile is safed
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