#include <GL/glut.h> 
 
static GLfloat spin = 0.0; /* g�c quay hi?n t?i c?a h�nh ch? nh?t */ 
 
void init(void)  
{ 
   glClearColor (0.0, 0.0, 0.0, 0.0); 
   glShadeModel (GL_FLAT); 
} 
 
void display(void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT); 
   glPushMatrix(); 
   glRotatef(spin, 0.0, 0.0, 1.0);  /* xoay m?t g�c spin quanh tr?c z */ 
   glColor3f(1.0, 1.0, 1.0); /* thi?t l?p m�u v? cho hcn (m�u tr?ng) */ 
   glRectf(-25.0, -25.0, 25.0, 25.0); /* v? hcn */ 
   glPopMatrix(); 
   glutSwapBuffers();  /* th?c hi?n vi?c ho�n d?i 2 buffer */ 
} 
 
void spinDisplay(void) 
{ 
   spin = spin + 2.0;  /* xoay th�m 2 deg cho m?i l?n l?p */ 
   if (spin > 360.0) 
      spin = spin - 360.0; 
   glutPostRedisplay();  /* th�ng b�o cho chuong tr�nh r?ng: c?n ph?i th?c 
hi?n vi?c v? l?i */ 
} 
 
/* c�c thao t�c c?n l�m khi c?a s? b? thay d?i k�ch thu?c */ 
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
      case GLUT_LEFT_BUTTON:  /* khi nh?n chu?t tr�i */ 
         if (state == GLUT_DOWN) 
            glutIdleFunc(spinDisplay); /* khi chuong tr�nh dang trong tr?ng 
th�i idle (kh�ng ph?i x? l� g� c?) th� s? th?c hi?n h�m spinDisplay */ 
         break; 
      case GLUT_MIDDLE_BUTTON:  /* khi nh?n n�t gi?a */ 
         if (state == GLUT_DOWN) 
            glutIdleFunc(NULL); 
                     break; 
      default: 
         break; 
   } 
} 
 
/* h�m main c?a chuong tr�nh */ 
int main(int argc, char** argv) 
{ 
   glutInit(&argc, argv); 
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);  /* khai b�o vi?c s? d?ng 
ch? d? double buffer */ 
   glutInitWindowSize (250, 250);  
   glutInitWindowPosition (100, 100); 
   glutCreateWindow ("spinning rectangle"); 
   init (); 
   glutDisplayFunc(display);  
   glutReshapeFunc(reshape); /* dang k� h�m reshape cho s? ki?n c?a s? b? 
thay d?i k�ch thu?c */ 
   glutMouseFunc(mouse); /* dang k� h�m mouse cho s? ki?n v? chu?t */ 
   glutMainLoop(); 
   return 0; 
} 
