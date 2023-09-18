#include <Arduino.h>
#include <config.h>
#include <FastLED.h>

#pragma region INITIALIZATIONS
CRGB TURN_SIGNAL_STRIP[TS_LED_NUMBER];
CRGB STOP_SIGNAL_STRIP[SS_LED_NUMBER];
CRGB RUN_SIGNAL_STRIP[RS_LED_NUMBER];

void timeLoop (unsigned long int startMillis, unsigned long int interval) { // delay substitute function
  while (millis() - startMillis < interval) {}
}
void SetupInit(){
  pinMode(TURNS_OUTPUT_PIN,OUTPUT);
  pinMode(STOPS_OUTPUT_PIN,OUTPUT);
  pinMode(RUNS_OUTPUT_PIN,OUTPUT);

  pinMode(TURNS_INPUT_PIN,INPUT);
  pinMode(STOPS_INPUT_PIN,INPUT);
  pinMode(RUNS_INPUT_PIN,INPUT);

  FastLED.addLeds<LED_TYPE, TURNS_OUTPUT_PIN, COLOR_ORDER>(TURN_SIGNAL_STRIP, TS_LED_NUMBER).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, STOPS_OUTPUT_PIN, COLOR_ORDER>(STOP_SIGNAL_STRIP, SS_LED_NUMBER).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, RUNS_OUTPUT_PIN, COLOR_ORDER>(RUN_SIGNAL_STRIP, RS_LED_NUMBER).setCorrection(TypicalLEDStrip);

  fill_solid(TURN_SIGNAL_STRIP,TS_LED_NUMBER,CRGB::Black);
  fill_solid(STOP_SIGNAL_STRIP,SS_LED_NUMBER,CRGB::Black);
  fill_solid(RUN_SIGNAL_STRIP,RS_LED_NUMBER,CRGB::Black);
}
#pragma endregion INITIALIZATIONS

#pragma region ANIMATIONS

void StartupAnimation(){

}

#pragma endregion ANIMATIONS

#pragma region MAIN_FUNCTIONS
void setup() {
  SetupInit();
  StartupAnimation();
}
void loop() {
  
}
#pragma endregion MAIN_FUNCTIONS