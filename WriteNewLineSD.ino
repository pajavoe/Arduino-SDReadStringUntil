
void writeOnSD(String FileName, String Text) {
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
