void serialOutput(){   // Decide How To Output Serial.
  switch(outputType){
    case PROCESSING_VISUALIZER:
      lcd.setCursor(0,1);
      lcd.print(BPM);
      break;
    default:
      break;
  }
}
void serialOutputWhenBeatHappens(){
  switch(outputType){
    case PROCESSING_VISUALIZER:    // find it here https://github.com/WorldFamousElectronics/PulseSensor_Amped_Processing_Visualizer
      lcd.setCursor(0,1);
      lcd.print(BPM);
      break;
    default:
      break;
  }
}
