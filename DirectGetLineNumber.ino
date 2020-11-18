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


unsigned int getSetLineNumbers(File myFile, int lengthLine) {//if line lnegth is known
  //not Tested!
  unsigned int lineNumbers = 0;
  bool linePresent = true;
  while (linePresent) {
    linePresent = myFile.seek(lineNumbers); //seeks through file until not available
    if (linePresent) {
      lineNumbers++;
    }
    else {
      linePresent = false;
    }
  }
  lineNumbers /= lengthLine;
  return lineNumbers;
}
