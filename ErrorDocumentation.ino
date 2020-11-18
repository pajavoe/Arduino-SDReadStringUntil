void Error(String errorMessage, bool SDWrite = true); //call at start of programm to enable optional var


void Error(String errorMessage, bool SDWrite) {
  //String errorMessage - message to be send to Serial device and written on SD Card,
  //optional bool SDWrite - write on SD
  //call to safe/display Errors
  int currentTime = (millis() / 1000);
  if (SDCardDocumentation && SDWrite) {
    writeOnSD(ErrorFile,  (String(currentTime) + "-" + errorMessage));//SD documentation
  }
  String SerialErrorMessage = ("S0x¿SE"  + String(currentTime) + "-" + errorMessage); //error Syntax for Mastermodule
  sendSerial(SerialErrorMessage);//Serial documentation
  ErrorBlinkOn = true; // turn on error blink-LED
}
