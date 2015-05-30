/*
  pcb factory is code modeled after code from http://www.instructables.com/id/Modification-of-the-Lexmark-E260-for-Direct-Laser--1/?ALLSTEPS
  its inteded to make the lexmark e260d into a pcb printer.
 */
/* todo fix pinout */

#define MFPS 8 // manual feed paper sensor
#define PIS 9  // paper in sensor
#define ES 10   // exit sensor

#define NMFPS 11 // our new manual feed paper sensor the X button // pin 3 // 0 when x pressed 1 when not
#define NPIS 12  // our new paper in sensor on center bracket // pin 2 // 0 when blocked 1 when not

volatile int pressed;
volatile int loaded;

void setup()
{
  //  Serial.begin(9600);
  //  Serial.println("starting up");
  pressed = 0;
  loaded = 0;

  pinMode(MFPS, OUTPUT);
  pinMode(PIS, OUTPUT);
  pinMode(ES, OUTPUT);

  digitalWrite(MFPS, HIGH);
  digitalWrite(PIS, HIGH);
  digitalWrite(ES, HIGH);

  pinMode(NMFPS, INPUT);
  pinMode(NPIS, INPUT);
}

void loop()
{
  digitalWrite(MFPS, HIGH);
  digitalWrite(PIS, HIGH);
  digitalWrite(ES, HIGH);

  if (!digitalRead(NMFPS)) {
    delay(300);
    if (!digitalRead(NMFPS)) {
      //      Serial.println("button was pressed");
      button_pushed();
      return;
    }
  }

  delay(10);
}

void button_pushed()
{
  //  Serial.println("waiting for something to happen");
  delay(1000);
  digitalWrite(MFPS, LOW);

  while (1) {
    //    Serial.print("waiting to print pcb ");
    //    Serial.print(digitalRead(NMFPS));
    //    Serial.print(" ");
    //    Serial.println(digitalRead(NPIS));

    if (!digitalRead(NMFPS)) {
      return;
    }
    if (!digitalRead(NPIS)) {
      print_pcb();
      return;
    }
    //    delay(5);
  }

}
void print_pcb()
{
  //  Serial.println("printing pcb");
  digitalWrite(PIS, LOW);
  delay(1825);
  digitalWrite(ES, LOW);
  delay(950);
  digitalWrite(MFPS, HIGH);
  delay(825);
  digitalWrite(PIS, HIGH);
  delay(1875);
  digitalWrite(ES, HIGH);
  //  Serial.println("printed pcb");
  return;
}
