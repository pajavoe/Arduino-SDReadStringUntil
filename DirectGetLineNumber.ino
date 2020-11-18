unsigned int getLineNumbers(File myFile) {
  //not Tested not recommended! -> use extra file to document file length
  //reads the hole file to get to line number
  //-> if length of line is not known use getSetlineAt()
  unsigned int lineNumbers = 0;
  char cr;
  while (1) { //goes trough each line until not available
    cr = myFile.read();
    if (cr == '\n') {
      lineNumbers++;
    }
    if (cr == "") {
      break;
    }
  }
  return lineNumbers;
}


unsigned int getSetLineNumbers(File myFile, int lengthLine) {//if line length is known
  //not Tested!
  return myFile.seek(myFile.size())/lengthLine;
}
