#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>


void drowPoit(int x, int y, int depth){
  glPushMatrix();
   glColor3d(0,0,50);
   glBegin(GL_POLYGON);
     glVertex2i(x,y);
     glVertex2i(x+depth,y);
     glVertex2i(x,y+depth);
     glVertex2i(x+depth,y+depth);
   glEnd();
  glPopMatrix();
}
void drowLineEq(int x1, int y1, int x2, int y2)
{
  if(x1 > x2)
  {
    int aux = x1; x1 = x2; x2 = aux;
    aux=y1; y1=y2; y2=aux;
  }
  double a = (double)(y2-y1)/(double)(x2-x1);
  for(int i = x1; i < x2; i++)
  {
    int ypoint = (int)(y1 + a*(double)(i-x1));
    drowPoit(i, ypoint, 2);
  }
}
void drowCircunferenceSegmentLineEq(int x, int y, int r, int quadrant){
  glPushMatrix();
  glTranslated(x, y, 0);
  if(quadrant == 1) {
    for(int i = 0; i < r; i++){
      int ypoint = floor(sqrt(r*r - i*i));
      drowPoit(i, ypoint, 2);
    }
  }
  if(quadrant == 2) {
    for(int i = 0; i < r; i++){
      int ypoint = floor(sqrt(r*r - i*i));
      drowPoit(-i, ypoint, 2);
    }
  }
  if(quadrant == 3) {
    for(int i = 0; i < r; i++){
      int ypoint = floor(-sqrt(r*r - i*i));
      drowPoit(-i, ypoint, 2);
    }
  }
  if(quadrant == 4) {
    for(int i = 0; i < r; i++){
      int ypoint = floor(-sqrt(r*r - i*i));
      drowPoit(i, ypoint, 2);
    }
  }
  glPopMatrix();
}
void drowFullCircunferenceLineEq(int x, int y, int r){
    for(int i = 1; i  <= 4; i++) drowCircunferenceSegmentLineEq(x, y, r, i);
}

void drowLineMidPoint(int x1, int y1, int x2, int y2){
  if(x1 > x2)
  {
    int aux = x1; x1 = x2; x2 = aux;
    aux=y1; y1=y2; y2=aux;
  }
  int dx, dy, incE, incNE, d, x, y;
  dx = x2-x1;
  dy = y2-y1;
  d = 2*dy - dx;
  incE = 2*dy;
  incNE = 2*(dy-dx);
  x = x1;
  y = y1;
  glPushMatrix();
  drowPoit(x, y, 2);
  while(x < x2){
    if(d <= 0){
      d += incE;
      x++;
    }else{
      d += incNE;
      x+=1;
      y+=1;
    }
    drowPoit(x, y, 2);
  }
  glPopMatrix();
}
void drowMidPointCircle(int x1, int y1, int r, int quadrant){
  glPushMatrix();
  glTranslated(x1, y1, 0);
  if(quadrant == 1){
    int x, y;
    float d;

    x = 0;
    y = r;
    d = 5/4 - r;

    drowPoit(x, y, 2);
    drowPoit(y, x, 2);
    while(y > x){
      if(d < 0){
        d += 2*x+3;
        x++;
      }else{
        d += 2*(x-y)+5;
        x++;
        y--;
      }
      drowPoit(x, y, 2);
      drowPoit(y, x, 2);
    }
  }
  if(quadrant == 2){
    int x, y;
    float d;

    x = 0;
    y = r;
    d = 5/4 - r;

    drowPoit(-x, y, 2);
    drowPoit(-y, x, 2);
    while(y > x){
      if(d < 0){
        d += 2*x+3;
        x++;
      }else{
        d += 2*(x-y)+5;
        x++;
        y--;
      }
      drowPoit(-x, y, 2);
      drowPoit(-y, x, 2);
    }
  }
  if(quadrant == 4){
    int x, y;
    float d;

    x = 0;
    y = r;
    d = 5/4 - r;

    drowPoit(x, -y, 2);
    drowPoit(y, -x, 2);

    while(y > x){
      if(d < 0){
        d += 2*x+3;
        x++;
      }else{
        d += 2*(x-y)+5;
        x++;
        y--;
      }
      drowPoit(x, -y, 2);
      drowPoit(y, -x, 2);
    }
  }
  if(quadrant == 3){
    int x, y;
    float d;

    x = 0;
    y = r;
    d = 5/4 - r;

    drowPoit(-y, -x, 2);
    drowPoit(-x, -y, 2);
    while(y > x){
      if(d < 0){
        d += 2*x+3;
        x++;
      }else{
        d += 2*(x-y)+5;
        x++;
        y--;
      }
      drowPoit(-y, -x, 2);
      drowPoit(-x, -y, 2);
    }
  }
  glPopMatrix();
}
void drowFullCircunferenceMidPoint(int x, int y, int r)
{
  for(int i = 1; i <= 4; i++) drowMidPointCircle(x, y, r, i);
}
