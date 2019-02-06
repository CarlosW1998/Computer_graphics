#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

const int width = 800, height = 600;

void drowHockeycourtLineEq(int x1, int y1, int x2, int y2){
  if(x1 < x2){
      int aux;aux = x1; x1 = x2; x2 = aux;
  }
  if(y1 < y2){
    int aux = y2, y2 = y1; y1 = aux;
  }
  int radiossegment = (x1-x2)/10;
  int middley = (y1+y2)/2, middlex = (x1+x2)/2;

   for(int i = y1-radiossegment; i > y2+radiossegment; i--)
   {
     drowPoit(x2, i, 2);
     drowPoit(x1, i, 2);
   }
   // Bordas do Campo
   drowCircunferenceSegmentLineEq(x2+radiossegment, y1-radiossegment, radiossegment, 2);
   drowCircunferenceSegmentLineEq(x1-radiossegment, y1-radiossegment, radiossegment, 1);
   drowCircunferenceSegmentLineEq(x2+radiossegment, y2+radiossegment, radiossegment, 3);
   drowCircunferenceSegmentLineEq(x1-radiossegment, y2+radiossegment, radiossegment, 4);
   drowLineEq(x2+radiossegment, y1, x1-radiossegment, y1);
   drowLineEq(x2+radiossegment, y2, x1-radiossegment, y2);
   // Linhas Do Campo
   drowLineEq(x2, y2+radiossegment, x1, y2+radiossegment);
   drowLineEq(x2, y1-radiossegment, x1, y1-radiossegment);
   drowLineEq(x2, middley, x1, middley);
   drowLineEq(x2, middley + (y1-middley)*(0.3), x1, middley + (y1-middley)*(0.3));
   drowLineEq(x2, middley - (y1-middley)*(0.3), x1, middley - (y1-middley)*(0.3));
   //CircunferenciasDoCampo
   drowFullCircunferenceLineEq(middlex + (x1-middlex)*0.6, middley - (y1-middley)*(0.6), radiossegment+radiossegment*0.3);
   drowFullCircunferenceLineEq(middlex - (x1-middlex)*0.6, middley - (y1-middley)*(0.6), radiossegment+radiossegment*0.3);
   drowFullCircunferenceLineEq(middlex - (x1-middlex)*0.6, middley + (y1-middley)*(0.6), radiossegment+radiossegment*0.3);
   drowFullCircunferenceLineEq(middlex + (x1-middlex)*0.6, middley + (y1-middley)*(0.6), radiossegment+radiossegment*0.3);
   // CirculosCentrais
   drowFullCircunferenceLineEq(middlex, middley, radiossegment+radiossegment*0.5);
   drowCircunferenceSegmentLineEq(middlex, y2+radiossegment, radiossegment, 1);
   drowCircunferenceSegmentLineEq(middlex, y2+radiossegment, radiossegment, 2);
   drowCircunferenceSegmentLineEq(middlex, y1-radiossegment, radiossegment, 3);
   drowCircunferenceSegmentLineEq(middlex, y1-radiossegment, radiossegment, 4);

}
void drowHockeycourtmidPoint(int x1, int y1, int x2, int y2){
  if(x1 < x2){
      int aux;aux = x1; x1 = x2; x2 = aux;
  }
  if(y1 < y2){
    int aux = y2, y2 = y1; y1 = aux;
  }
  int radiossegment = (x1-x2)/10;
  int middley = (y1+y2)/2, middlex = (x1+x2)/2;

   for(int i = y1-radiossegment; i > y2+radiossegment; i--)
   {
     drowPoit(x2, i, 2);
     drowPoit(x1, i, 2);
   }
   // Bordas do Campo
   drowMidPointCircle(x2+radiossegment, y1-radiossegment, radiossegment, 2);
   drowMidPointCircle(x1-radiossegment, y1-radiossegment, radiossegment, 1);
   drowMidPointCircle(x2+radiossegment, y2+radiossegment, radiossegment, 3);
   drowMidPointCircle(x1-radiossegment, y2+radiossegment, radiossegment, 4);
   drowLineMidPoint(x2+radiossegment, y1, x1-radiossegment, y1);
   drowLineMidPoint(x2+radiossegment, y2, x1-radiossegment, y2);
   // Linhas Do Campo
   drowLineMidPoint(x2, y2+radiossegment, x1, y2+radiossegment);
   drowLineMidPoint(x2, y1-radiossegment, x1, y1-radiossegment);
   drowLineMidPoint(x2, middley, x1, middley);
   drowLineMidPoint(x2, middley + (y1-middley)*(0.3), x1, middley + (y1-middley)*(0.3));
   drowLineMidPoint(x2, middley - (y1-middley)*(0.3), x1, middley - (y1-middley)*(0.3));
   //CircunferenciasDoCampo
   drowFullCircunferenceMidPoint(middlex + (x1-middlex)*0.6, middley - (y1-middley)*(0.6), radiossegment+radiossegment*0.3);
   drowFullCircunferenceMidPoint(middlex - (x1-middlex)*0.6, middley - (y1-middley)*(0.6), radiossegment+radiossegment*0.3);
   drowFullCircunferenceMidPoint(middlex - (x1-middlex)*0.6, middley + (y1-middley)*(0.6), radiossegment+radiossegment*0.3);
   drowFullCircunferenceMidPoint(middlex + (x1-middlex)*0.6, middley + (y1-middley)*(0.6), radiossegment+radiossegment*0.3);
   // CirculosCentrais
   drowFullCircunferenceMidPoint(middlex, middley, radiossegment+radiossegment*0.5);
   drowMidPointCircle(middlex, y2+radiossegment, radiossegment, 1);
   drowMidPointCircle(middlex, y2+radiossegment, radiossegment, 2);
   drowMidPointCircle(middlex, y1-radiossegment, radiossegment, 3);
   drowMidPointCircle(middlex, y1-radiossegment, radiossegment, 4);

}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0, 1.0, 0.0);
 // drowHockeycourtLineEq(300, 500, 500, 100);
 drowHockeycourtmidPoint(300, 500, 500, 100);
 glFlush();
}

void init()
{
  gluOrtho2D(0, width, 0, height);
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Input");
    init();
  glutDisplayFunc(display);
  // glutKeyboardFunc(keyboardHandler);
  // glutPassiveMotionFunc(passiveMotionHandler);
  // glutTimerFunc(10, scheduleUpdate, 1);
glutMainLoop();

 return 0;
}
