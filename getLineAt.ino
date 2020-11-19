String getLineAt(unsigned int lineNumber, File myFile) {
  String output;
  char cr;
  for (unsigned int i = 0; i < (lineNumber - 1);) { //goes to the Line before searched one
    cr = myFile.read(); // reads the hole file -> better option: seek()
    if (cr == '\n') {
      i++;
    }
  }
  while (true) { //reads the line that is given
    cr = myFile.read();
    output += cr; //adds to output
    if (cr == '\n') {
      break;
    }
  }
  return output;
}

String getSetlineAt(unsigned int lineNumber, File myFile, int lengthLine) {
  //not Tested!
  //use this method if line length is known static
  String output;
  char cr;
  for (int Line = 0; Line < (lineNumber * lengthLine); Line += lengthLine)  {
    myFile.seek(Line);// jumps through each line until wanted
  }
  while (true) { //reads the line that is given
    cr = myFile.read();
    if (cr == '\n') {
      break;
    }
    output += cr; //adds to output
  }
  return output;
}

/* Call like following:
File myFile;
  myFile = SD.open("text.txt"); //open file in read mode
  Serial.println(getLineAt(41, myFile));
  */
