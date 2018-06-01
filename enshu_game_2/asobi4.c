#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

int count = 1;

void keyboard(unsigned char key, int x, int y){
  
  switch(key){
    case 't':
      count++;
      glutPostRedisplay();
      break;
    default :
      break;
  }

}

void display(void){
  printf("%d\n",count);
  glClear(GL_COLOR_BUFFER_BIT);          /* 画面を消去 */
  glutSwapBuffers(); 

}

void timer(int timerID){
}

int main(int argc, char *argv[]){
  glutInitWindowPosition(500, 500);                   /* ウインドウ表示位置 */
  glutInitWindowSize(400, 400);                   /* ウインドウサイズ */
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);   /* 描画モード */
  glClearColor (0.0, 0.0, 0.0, 1.0);    

  glutInit(&argc, argv);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(1000, timer, 0);

  glutMainLoop();
  return 0;
}
