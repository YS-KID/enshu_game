/* ヘッダファイル */
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int NUM_ENE = 4;//敵の数(1~10体)

double V[10] = {0.06, 0.03, 0.02, 0.05, 0.055, 0.025, 0.04, 0.065, 0.03, 0.035};//敵の速度

int Rotate = 0;

//Cubeの位置
double Cube_x = -0.5;
double Cube_y = -0.5;
double Cube_z = 0.0;


float Vy = 0.0;
int jump = 0;
int jcount;

float xtime = 0.0;
float ytime = 0.0;

int mainWindow;

long t,Ctime;

double enemy_x[10] = {-5.0};
double enemy_y[10] = {-2.0, 0.0, 1.0, 1.0, -2.0, 1.0, 1.5, 2.0, 0.8, 0.3};


double R[10];

int die_flag = 2;


/**********************************************************
|  関数：display()
***********************************************************/
void display(void)
{

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Cubeの初期位置
  glPushMatrix ();  
     
  glTranslatef(Cube_x,Cube_y,Cube_z);
  glRotatef(Rotate,1.0,0,1.0);
  glColor3f(0.0, 0.0, 0.0);   
  glutWireSphere (0.1,10.0,10.0);

  glPopMatrix ();


  //床の初期位置
  glPushMatrix ();
  
  glTranslatef(0.0, -0.61, 0.0);
  glColor3f(1.0, 0.0, 0.0);
  glScalef(2.0, 0.01, 1.0);
  glutSolidCube(1.0);

  glPopMatrix ();


  //経過時間の表示
  glPushMatrix ();

  t = clock();
  glRasterPos3f(0.7, -0.8, 1.0f);
  glColor3d(1.0, 1.0, 1.0);
  char a[256];
  sprintf(a, "%.1lf", (t - Ctime)/10000.0);
  char *c = a;
  if(t - Ctime > 300000.0){
    die_flag = 3;
  }

  while(*c){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *c);
    c++;
  }

  glPopMatrix ();

  //敵の位置
  for(int i = 0; i < NUM_ENE; i++){
    glPushMatrix ();   
    glColor3f( 0.0,0.0,1.0 ); 
    glScalef(0.25, 0.25, 0.25);
    glRotatef(-90,0.0,1.0,0.0);
    glTranslatef(0.0,enemy_y[i],enemy_x[i]);
    glRotatef(Rotate*3, 0.0, 0.0, 1.0);
    glutWireCone(0.25,0.5,10,2);
    glPopMatrix ();
  }


  //YouLose画面
  if(die_flag == 1){
    Ctime = clock();
    for(int i = 0; i < NUM_ENE; i++){
      enemy_x[i] = -5.0; 
      Cube_y = -0.5;    
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(0.0,0.0,1.0); 
    glRasterPos3f(-0.15, 0.0, 1.0f);
    char *b = "YOU LOSE!!";
    while(*b){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *b);
      b++;
    }
    glRasterPos3f(0.5, -0.8, 1.0f);
    char *c = "press 'r' to replay";
    while(*c){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *c);
      c++;
    }
    glRasterPos3f(0.5, -0.9, 1.0f);
    char *d = "press 'q' to exit";
    while(*d){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *d);
      d++;
    }
    glPopMatrix ();
    enemy_y[0] = -2.0;
    enemy_y[1] = 0.0;
    enemy_y[2] = 1.0;
    enemy_y[3] = 1.0;
    enemy_y[4] = -2.0;
    enemy_y[5] = 1.0;
    enemy_y[6] = 1.5;
    enemy_y[7] = 2.0;
    enemy_y[8] = 0.8;
    enemy_y[9] = 0.3;
    
  }
  //YouWin画面
  if(die_flag == 2){
    Ctime = clock();
    for(int i = 0; i < NUM_ENE; i++){
      enemy_x[i] = -5.0; 
      Cube_y = -0.5;    
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1.0,0.0,0.0); 
    glRasterPos3f(-0.25, 0.0, 1.0f);
    char *b = "Press 's' to start.";
    while(*b){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *b);
      b++;
    }
    glPopMatrix ();
  }
  //Start画面
  if(die_flag == 3){
    Ctime = clock();
    for(int i = 0; i < NUM_ENE; i++){
      enemy_x[i] = -5.0; 
      Cube_y = -0.5;    
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1.0,0.0,0.0); 
    glRasterPos3f(-0.15, 0.0, 1.0f);
    char *b = "YOU WIN!!";
    while(*b){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *b);
      b++;
    }
    glRasterPos3f(0.5, -0.8, 1.0f);
    char *c = "press 'r' to replay";
    while(*c){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *c);
      c++;
    }
    glRasterPos3f(0.5, -0.9, 1.0f);
    char *d = "press 'q' to exit";
    while(*d){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *d);
      d++;
    }
    glPopMatrix ();
    enemy_y[0] = -2.0;
    enemy_y[1] = 0.0;
    enemy_y[2] = 1.0;
    enemy_y[3] = 1.0;
    enemy_y[4] = -2.0;
    enemy_y[5] = 1.0;
    enemy_y[6] = 1.5;
    enemy_y[7] = 2.0;
    enemy_y[8] = 0.8;
    enemy_y[9] = 0.3;
    
  }

  glutSwapBuffers();
}


/***********************************************************
|  関数：timer(int timerID)
***********************************************************/
void timer(int timerID)
{
  //Cubeの角速度
  Rotate += 2;
;
  if(Rotate > 360){
     Rotate -= 360;
  }
  
  //jumpの制御
  if(jump == 1){

    Cube_y  += Vy;
    Vy -= 0.003;

    if(Cube_y < -0.5){
      Cube_y = -0.5;
      jump = 0;
      jcount = 0;
    }
  }

  
  //敵の移動
  for(int i = 0; i < NUM_ENE; i++){
    enemy_x[i] += V[i];
    if(enemy_x[i] > 5.0){
      enemy_x[i] = -5.0;
      if(i!=0){
      enemy_y[i] = 4.0*((rand()%11)/10.0) - 2.0;
      }else{
      enemy_y[i] = (rand()%11)/20.0 - 2.0;
      } 
      //printf("%d\n",rand()/RAND_MAX);
    }
  }

  //敵とのあたり判定
  for(int i = 0; i < NUM_ENE; i++){
    R[i] = sqrt(pow(Cube_x-(-enemy_x[i]/3.5),2) + pow(Cube_y-enemy_y[i]/4.0,2));
    if(R[i] < 0.18){
      die_flag = 1;
    }
  }

  glutPostRedisplay();
  glutTimerFunc(20, timer, 0);

}


/***********************************************************
|  関数：keyboard()
***********************************************************/
void keyboard(unsigned char key, int x, int y )
{

  //keyboardで画面を切り替えるための旗を切り替える
  static int count = 0;
  switch(key){                                                                          
    case 'r':
      die_flag = 0;
      break;
    case 's':
      die_flag = 0;
      break;
    case 'q':
      glutDestroyWindow(mainWindow);
      break;
    default :
      break;
  }

} 


/***********************************************************
|  関数：mouseButton()
***********************************************************/
void mouseButton(int button, int state, int x, int y )
{
  if(state == GLUT_DOWN){
    switch(button){
    
    //左クリックでjump_flagを立てる
    case GLUT_LEFT_BUTTON:
      jcount++;
      if(jcount < 3){
        Vy = 0.065;
        jump = 1;
      }
      break;

    }
  }

}

/***********************************************************
|  関数：myInit()
***********************************************************/
void myInit (char *windowTitle)
{
    /* OpenGLウインドウ作成までの初期化 */
    glutInitWindowPosition(1000, 0);                   
    glutInitWindowSize(800, 800);                    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);   
    mainWindow = glutCreateWindow(windowTitle);     
    glClearColor (0.8, 0.8, 0.8, 0.0);              

    /* イベントが発生した時に呼び出す関数の登録 */
    glutKeyboardFunc(keyboard);
    glutMouseFunc   (mouseButton);
    glutTimerFunc   (15, timer, 0);
    glutDisplayFunc (display);
}


/***********************************************************
|  関数：main()
***********************************************************/
int main(int argc, char** argv)
{
    /* 初期化 */
    Ctime = clock();
    glutInit(&argc, argv);  
    myInit(argv[0]);        

    /* イベント処理ループ */
    glutMainLoop(); 

    /* プログラム終了 */
    return( 0 );
}

