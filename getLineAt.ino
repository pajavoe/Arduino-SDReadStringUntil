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

/* Call like following:
File myFile;
  myFile = SD.open("ErrorC.txt"); //open file in read mode
  Serial.println(printLineN(41, myFile));
  */
