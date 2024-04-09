#include <Joystick.h>

#define JOYSTICK_COUNT 3

Joystick_ Joystick[JOYSTICK_COUNT] = {
  Joystick_(0x03, JOYSTICK_TYPE_JOYSTICK, 2, 0, true, true, false, false, false, false, false, false, false, false, false),
  Joystick_(0x04, JOYSTICK_TYPE_JOYSTICK, 0, 0, false, false, true, true, false, false, false, true, false, false, false),
  Joystick_(0x05, JOYSTICK_TYPE_JOYSTICK, 0, 0, false, false, false, true, true, true, false, false, false, false, false)
};
int x, y, t, m, i, totalx, totaly,iy, totalt, it, totalm, im,  totalp, ip, p, totalf, iff, f, totalrd, ird, rd, totalri, iri, ri;
int lecturaX[10], lecturaY[10], lecturaT[10], lecturaM[10], lecturaP[10], lecturaRi[10], lecturaRd[10], lecturaF[10];
void setup() {
  // put your setup code here, to run once:
  Joystick[0].setXAxisRange(-127, 127);
  Joystick[0].setYAxisRange(-127, 127);
  Joystick[1].setZAxisRange(0, 1023);
  Joystick[1].setRxAxisRange(0, 1023);
  Joystick[1].setThrottleRange(0, 1023);
  Joystick[2].setRyAxisRange(-127, 127);
  Joystick[2].setRzAxisRange(-127, 127);
  Joystick[2].setRxAxisRange(-127, 127);
    for (int index = 0; index < JOYSTICK_COUNT; index++) {
    Joystick[index].begin();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  totalx = totalx - lecturaX[i];
  lecturaX[i] = analogRead(A0);
  totalx = totalx + lecturaX[i];
   i = i+1;
  if (i >= 10) {
  i = 0;
  x = totalx/10;
  }
  totaly= totaly - lecturaY[iy];
  lecturaY[iy] = analogRead(A1);
  totaly = totaly + lecturaY[iy];
    iy = iy+1;
   if (iy >= 10) {
  iy = 0;
  y = totaly/10;
  }
   totalt= totalt - lecturaT[it];
  lecturaT[it] = analogRead(A2);
  totalt = totalt + lecturaT[it];
    it = it+1;
   if (it >= 10) {
  it = 0;
  t = totalt/10;
  }
   totalm= totalm - lecturaM[im];
  lecturaM[im] = analogRead(A3);
  totalm = totalm + lecturaM[im];
    im = im+1;
   if (im >= 10) {
  im = 0;
  m = totalm/10;
  }

  totalp= totalp - lecturaP[ip];
  lecturaP[ip] = analogRead(A4);
  totalp = totalp + lecturaP[ip];
    ip = ip+1;
   if (ip >= 10) {
  ip = 0;
  p = totalp/10;
  }
  totalf= totalf - lecturaF[iff];
  lecturaF[iff] = analogRead(A5);
  totalf = totalf + lecturaF[iff];
    iff = iff+1;
   if (iff >= 10) {
  iff = 0;
  f = totalf/10;
  }

  totalrd= totalrd - lecturaRd[ird];
  lecturaRd[ird] = analogRead(A6);
  totalrd = totalrd + lecturaRd[ird];
    ird = ird+1;
   if (ird >= 10) {
  ird = 0;
  rd = totalrd/10;
  }

  totalri= totalri - lecturaRi[iri];
  lecturaRi[iri] = analogRead(A7);
  totalri = totalri + lecturaRi[iri];
    iri = iri+1;
   if (iri >= 10) {
  iri = 0;
  ri = totalri/10;
  }
 // x=analogRead(A0);
  //y = analogRead(A1);
//Serial.println(x);
  Joystick[0].setXAxis(map(x, 665, 990, -127, 127));
  Joystick[0].setYAxis(map(y, 1023, 0, -127, 127));
  Joystick[0].sendState();
  Joystick[1].setThrottle(t);
  Joystick[1].setRxAxis(m);
  Joystick[1].setZAxis(p);
   Joystick[1].sendState();
   Joystick[2].setRyAxis(map(rd, 914, 1023, -127, 127));
   Joystick[2].setRxAxis(map(ri, 870, 1023, -127, 127));
  Joystick[2].setRzAxis(map(f, 180, 795, -127, 127));
  Joystick[2].sendState();
}
