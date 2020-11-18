
void writeOnSD(String FileName, String Text) {//write new Line
  //String FileName - name of File,String Text - text to write(see syntax)
  File myFile;
  if (!SD.begin(chipSelectPIN)) {//Initializing SD card
    Error("Error 001: SD Card initialization failed!", false);//see libraray, optinally just println()
    while (1);
  }
  myFile = SD.open(FileName, FILE_WRITE); //open file type in write mode
  if (myFile) {
    myFile.println(Text);
    myFile.close(); // close the file
  } else {
    // if the file didn't open, print an error:
    Error("Error 002: SD Card opening failed", false);//see libraray, optinally just println()
  }
}



void writeOnSDInLine(String FileName, String Text) {//write in old Line
  //String FileName - name of File,String Text - text to write(see syntax)
  //chipSelectPIN - pin where CS is connected to 
  File myFile;
  if (!SD.begin(chipSelectPIN)) {//Initializing SD card
    Error("Error 001: SD Card initialization failed!", false);
    while (1);
  }
  myFile = SD.open(FileName, FILE_WRITE); //open file type in write mode
  if (myFile) {
    myFile.print(Text); //onyl difference to writeOnSD()
    myFile.close(); // close the file
  } else {
    // if the file didn't open, print an error:
    Error("Error 002: SD Card opening failed", false);
  }
}
