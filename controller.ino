

unsigned long startTime;
unsigned long endTime;

unsigned long frequency=0;
int inp=0;

void setup() {
  Serial.begin(9600);
  setupFFT();
  setupInput();
}

void loop() {
  frequency = findFreq();
  inp = convertFreqToInput(frequency);
  makeInput(inp);

}
