/* --------------------------------------------------------------------
 * gls01.c
 * イベントの発生を理解するプログラム
 * -------------------------------------------------------------------- */

/* ヘッダファイル */
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int NUM_ENE = 10;

double V[10] = {0.06, 0.03, 0.02, 0.05, 0.055, 0.025, 0.04, 0.065, 0.03, 0.035};

int Rotate = 0;

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
|  説明：1枚のグラフィック描画イベント処理
|  引数：なし
|  戻値：なし
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
|  説明：タイマー（設定時間経過）イベント処理
|  引数：int timerID    イベントが発生したタイマーの識別ID
|  戻値：なし
***********************************************************/
void timer(int timerID)
{
  Rotate += 2;
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
    //printf("%lf\n",R[i]);
    if(R[i] < 0.18){
      die_flag = 1;
      //printf("当たった\n");
    }
  }

  glutPostRedisplay();
  glutTimerFunc(20, timer, 0);

}


/***********************************************************
|  関数：keyboard()
|  説明：キーボードが押された時のイベント処理
|  引数：unsigned char key  押されたキーの文字コード
|  引数：int x              キーが押されたときのマウスポインタのX座標
|  引数：int y              キーが押されたときのマウスポインタのY座標
|  戻値：なし
***********************************************************/
void keyboard(unsigned char key, int x, int y )
{
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
|  説明：マウスのボタン操作時のイベント処理
|  引数：int button     操作したマウスボタンの番号
|  引数：int state      操作の種類 GLUT_DOWN（押す）かGLUT_UP（離す）
|  引数：int x          キーが押されたときのマウスポインタのX座標
|  引数：int y          キーが押されたときのマウスポインタのY座標
|  戻値：なし
***********************************************************/
void mouseButton(int button, int state, int x, int y )
{
  if(state == GLUT_DOWN){
    switch(button){
    
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
|  関数：mouseDrag()
|  説明：画面上でマウスがドラッグされた時のイベント処理
|  引数：int x          現在のマウスポインタのX座標
|  引数：int y          現在のマウスポインタのY座標
|  戻値：なし
***********************************************************/
void mouseDrag(int x, int y)
{
}


/***********************************************************
|  関数：myInit()
|  説明：ウインドウ表示と描画設定の初期化
|  引数：char *windowTitle      ウインドウのタイトルバーに表示する文字列
|  戻値：なし
***********************************************************/
void myInit (char *windowTitle)
{
    /* OpenGLウインドウ作成までの初期化 */
    glutInitWindowPosition(1000, 0);                   /* ウインドウ表示位置 */
    glutInitWindowSize(1000, 1000);                   /* ウインドウサイズ */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);   /* 描画モード */
    mainWindow = glutCreateWindow(windowTitle);                  /* ウインドウの表示 */
    glClearColor (0.8, 0.8, 0.8, 0.0);              /* 画面消去色の設定 */

    /* イベント発生時に呼び出す関数の登録 */
    glutKeyboardFunc(keyboard);         /* キーボードを押した時 */
    glutMouseFunc   (mouseButton);      /* マウスボタンを押した時*/
    glutMotionFunc  (mouseDrag);        /* マウスドラッグした時 */
    glutTimerFunc   (15, timer, 0);   /* 15(ms)経過時 */
    glutDisplayFunc (display);          /* 画面表示 */
}


/***********************************************************
|  関数：main()
|  説明：メイン関数
|  引数：int argc       実行時引数の数
|  引数：char** argv    実行時引数の内容（文字列配列）
|  戻値：int            0:正常終了
***********************************************************/
int main(int argc, char** argv)
{
    /* 初期化 */
    Ctime = clock();
    glutInit(&argc, argv);  /* OpenGL の初期化 */
    myInit(argv[0]);        /* ウインドウ表示と描画設定の初期化 */

    /* イベント処理ループ */
    glutMainLoop(); 

    /* プログラム終了 */
    return( 0 );
}

