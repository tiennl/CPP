#include <GL/glut.h> 
 
static GLfloat spin = 0.0; /* góc quay hi?n t?i c?a hình ch? nh?t */ 
 
void init(void)  
{ 
   glClearColor (0.0, 0.0, 0.0, 0.0); 
   glShadeModel (GL_FLAT); 
} 
 
void display(void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT); 
   glPushMatrix(); 
   glRotatef(spin, 0.0, 0.0, 1.0);  /* xoay m?t góc spin quanh tr?c z */ 
   glColor3f(1.0, 1.0, 1.0); /* thi?t l?p màu v? cho hcn (màu tr?ng) */ 
   glRectf(-25.0, -25.0, 25.0, 25.0); /* v? hcn */ 
   glPopMatrix(); 
   glutSwapBuffers();  /* th?c hi?n vi?c hoán d?i 2 buffer */ 
} 
 
void spinDisplay(void) 
{ 
   spin = spin + 2.0;  /* xoay thêm 2 deg cho m?i l?n l?p */ 
   if (spin > 360.0) 
      spin = spin - 360.0; 
   glutPostRedisplay();  /* thông báo cho chuong trình r?ng: c?n ph?i th?c 
hi?n vi?c v? l?i */ 
} 
 
/* các thao tác c?n làm khi c?a s? b? thay d?i kích thu?c */ 
void reshape(int w, int h) 
{ 
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); /* thay d?i viewport */ 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0); 
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
} 
void mouse(int button, int state, int x, int y)  
{ 
   switch (button) { 
      case GLUT_LEFT_BUTTON:  /* khi nh?n chu?t trái */ 
         if (state == GLUT_DOWN) 
            glutIdleFunc(spinDisplay); /* khi chuong trình dang trong tr?ng 
thái idle (không ph?i x? lý gì c?) thì s? th?c hi?n hàm spinDisplay */ 
         break; 
      case GLUT_MIDDLE_BUTTON:  /* khi nh?n nút gi?a */ 
         if (state == GLUT_DOWN) 
            glutIdleFunc(NULL); 
                     break; 
      default: 
         break; 
   } 
} 
 
/* hàm main c?a chuong trình */ 
int main(int argc, char** argv) 
{ 
   glutInit(&argc, argv); 
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);  /* khai báo vi?c s? d?ng 
ch? d? double buffer */ 
   glutInitWindowSize (250, 250);  
   glutInitWindowPosition (100, 100); 
   glutCreateWindow ("spinning rectangle"); 
   init (); 
   glutDisplayFunc(display);  
   glutReshapeFunc(reshape); /* dang ký hàm reshape cho s? ki?n c?a s? b? 
thay d?i kích thu?c */ 
   glutMouseFunc(mouse); /* dang ký hàm mouse cho s? ki?n v? chu?t */ 
   glutMainLoop(); 
   return 0; 
} 
