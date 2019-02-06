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
