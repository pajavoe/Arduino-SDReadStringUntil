/* Write each time a new line is being added a charcter with writeOnSDInLine() to an extra file
when lnegth from main file is requierd  following  method can be called to get the amount of lines
*/
unsigned int getLineLength(unsigned int lineNumber, File myFile) {
  //counts the characters  in specific line number
  //recomenedet for extra file length read out
  char cr;
  unsigned int  LineLength = 0;
  if (lineNumber - 1 > 1) {
    getLineAt(lineNumber - 1, myFile);
  }
  while (1) {
    cr = myFile.read();
    if (cr == '\n') {
      break;
    }
    LineLength++;
  }
  return LineLength;
}
