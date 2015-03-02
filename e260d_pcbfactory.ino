/*
  pcb factory is code modeled after code from http://www.instructables.com/id/Modification-of-the-Lexmark-E260-for-Direct-Laser--1/?ALLSTEPS
  its inteded to make the lexmark e260d into a pcb printer.
 */
/* todo fix pinout */

#define MFPS 5 // manual feed paper sensor
#define PIS 6  // paper in sensor
#define ES 4   // exit sensor

#define NMFPS 3 // our new manual feed paper sensor the X button // pin 3 // 1 when x pressed 0 when not
#define NPIS 2  // our new paper in sensor on center bracket // pin 2 // 1 when blocked 0 when not

volatile int pressed;
volatile int loaded;

void setup()
{
  Serial.begin(9600);
  Serial.println("starting up");
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
  delay(1000);
  
  digitalWrite(PIS, LOW);
  delay(1825);
  digitalWrite(ES, LOW);
  delay(950);
  digitalWrite(MFPS, HIGH);
  delay(825);
  digitalWrite(PIS, HIGH);
  delay(1875);
  digitalWrite(ES, HIGH);
  //  attachInterrupt(NMFPS, x_pressed, LOW);
  //  attachInterrupt(NPIS, page_in_slot, HIGH);
}

void loop()
{
  //  Serial.println("loop 1");
  //  pressed = digitalRead(NMFPS);
  pressed = Serial.available();
  if (pressed) {
    Serial.read();
    Serial.println("pressed");
    delay(10);
    pressed = 0;
    loaded = 0;
    digitalWrite(MFPS, LOW);
    while(digitalRead(NPIS)) {
    }
    //    pressed = Serial.available();
    //    loaded = digitalRead(NPIS);
    //    while (!pressed || !loaded) { // come back here later and add reset functionailty
    //      if (pressed) {
    //	Serial.read();
    //        digitalWrite(MFPS, HIGH);
    //	Serial.println("start over");
    //        return;
    //      }
      Serial.println("printing");
      digitalWrite(PIS, LOW);
      delay(1825);
      digitalWrite(ES, LOW);
      delay(950);
      digitalWrite(MFPS, HIGH);
      delay(825);
      digitalWrite(PIS, HIGH);
      delay(1875);
      digitalWrite(ES, HIGH);
      if(Serial.available()) {
      Serial.read(); }
      pressed = 0;
      loaded = 0;
      return;
    }
}



// /*
//   pcb factory is code modeled after code from http://www.instructables.com/id/Modification-of-the-Lexmark-E260-for-Direct-Laser--1/?ALLSTEPS
//   its inteded to make the lexmark e260d into a pcb printer.
//  */
// /* todo fix pinout */

// #define MFPS 5 // manual feed paper sensor
// #define PIS 6  // paper in sensor
// #define ES 4   // exit sensor

// #define NMFPS 1 // our new manual feed paper sensor the X button // pin 3
// #define NPIS 0  // our new paper in sensor on center bracket // pin 2

// volatile int pressed;
// volatile int loaded;

// void setup()
// {
//   Serial.begin(9600);
//   Serial.println("starting up");
//   pressed = 0;
//   loaded = 0;

//   pinMode(MFPS, OUTPUT);
//   pinMode(PIS, OUTPUT);
//   pinMode(ES, OUTPUT);

//   digitalWrite(MFPS, HIGH);
//   digitalWrite(PIS, HIGH);
//   digitalWrite(ES, HIGH);


//   attachInterrupt(NMFPS, x_pressed, LOW);
//   attachInterrupt(NPIS, page_in_slot, HIGH);
// }

// void loop()
// {
//   //  Serial.println("loop 1");
//   if (pressed) {
//     Serial.println("pressed");
//     pressed = 0;
//     delay(1000);
//     digitalWrite(MFPS, LOW);
//     while (!pressed || !loaded) { // come back here later and add reset functionailty
//       if (pressed) {
//         digitalWrite(MFPS, HIGH);
// 	Serial.println("start over");
//         return;
//       }
//       Serial.println("printing");
//       digitalWrite(PIS, LOW);
//       delay(1825);
//       digitalWrite(ES, LOW);
//       delay(950);
//       digitalWrite(MFPS, HIGH);
//       delay(825);
//       digitalWrite(PIS, HIGH);
//       delay(1875);
//       digitalWrite(ES, HIGH);

//       pressed = 0;
//       loaded = 0;
//     }
//   }
// }

// void x_pressed()
// {
//   pressed = 1;
//   Serial.println("pressed int");
// }

// void page_in_slot()
// {
//   loaded = 1;
//     Serial.println("in slot");
// }
