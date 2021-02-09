#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gl\glu.h>
//most systems include GL/glut.h others just glut.h
#include "gl\glut.h"
//#include <GL/glut.h>
#include <conio.h>
#include<locale.h>
#include<math.h>


//global olakrak de�i�kenleri tan�tt�yoruz
double ax,ay,xa,ya;
double bx,by,xb,yb;
double cx,cy,xc,yc;
double dx,dy;
double a,b,c,x,y;
int i,j,k;
double derece,radyan,v,z;
int flag = 0;
double t_cisim[3][3];
double k_cisim[3][3];
const double PI = 3.14159265;

//do�ruya g�re yans�tma fonskiyonu
void dogruya_gore_yansitma_x(){
	
	//verilen ��genin kordinatlar� ile matris olu�turuyoruz 
	double t_cisim[3][3] = { {ax, ay, 1}, {bx, by, 1}, {cx, cy, 1} };
	
	y = c/a;
	x = c/b;
	
	double k_t_oteleme[3][3];
	double k_t_dondurme[3][3];
	double k_t_yansitma[3][3];
	double t_k_dondurme[3][3];
	double t_k_oteleme[3][3];
	
	// oteleme matrisini tan�ml�yoruz 
	double t_oteleme[3][3] = { {1, 0, 0}, {0, 1, 0}, {x, 0, 1} };
	
	//��geni verilen do�ru fonksiyonuna g�re �teleme i�lemi yap�yoruz 
	//olu�an matrisi k_t_oteleme matrisine at�yoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=t_cisim[i][k]*t_oteleme[k][j];		
		    k_t_oteleme[i][j]=flag;
  }
}		
	// d�nd�rme matrisini tan�ml�yoruz
	double t_dondurme[3][3] = { {cos(radyan), -sin(radyan), 0}, {sin(radyan), cos(radyan), 0}, {0, 0, 1} };

	//��geni verilen fonksiyona g�re d�nd�rme i�lemi yap�yoruz 
	//olu�an matrisi k_t_dondurme matrisine at�yoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=k_t_oteleme[i][k]*t_dondurme[k][j];		
		    k_t_dondurme[i][j]=flag;
  }
}

	//yans�tma matrisini tan�ml�yoruz
	double t_yansitma[3][3] = { {1, 0, 0}, {0, -1, 0}, {0, 0, 1} };

	//��geni verilen fonksiyona g�re yans�tma i�lemi yap�yoruz
	//olu�an matrisi k_t_yansitma matrisine at�yoruz
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=k_t_dondurme[i][k]*t_yansitma[k][j];		
		    k_t_yansitma[i][j]=flag;
  }
}
	double k_dondurme[3][3] = { {cos(radyan), sin(radyan), 0}, {-sin(radyan), cos(radyan), 0}, {0, 0, 1} };
	
	//��geni verilen fonksiyona g�re d�nd�rme i�lemi yap�yoruz 
	//olu�an matrisi k_t_dondurme matrisine at�yoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=k_t_yansitma[i][k]*k_dondurme[k][j];		
		    t_k_dondurme[i][j]=flag;
  }
}
	double k_oteleme[3][3] = { {1, 0, 0}, {0, 1, 0}, {-x, 0, 1} };
	
	//��geni verilen do�ru fonksiyonuna g�re �teleme i�lemi yap�yoruz 
	//olu�an matrisi k_t_oteleme matrisine at�yoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=t_k_dondurme[i][k]*k_oteleme[k][j];		
		    t_k_oteleme[i][j]=flag;
  }
}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			k_cisim[i][j] = t_k_oteleme[i][j];
  }
}	
	dy = (100*b+c)/a;
	dx = (a*(-100)-c)/b;
	xa = k_cisim [0][0];
	ya = k_cisim [0][1];
	
	xb = k_cisim [1][0];
	yb = k_cisim [1][1];
	
	xc = k_cisim [2][0];
	yc = k_cisim [2][1];
	
	return xa,ya,xb,yb,xc,yc,dy,dx;
}

void dogruya_gore_yansitma_y(){
	
	//verilen ��genin kordinatlar� ile matris olu�turuyoruz 
	double t_cisim[3][3] = { {ax, ay, 1}, {bx, by, 1}, {cx, cy, 1} };
	double k_t_oteleme[3][3];
	double k_t_dondurme[3][3];
	double k_t_yansitma[3][3];
	double t_k_dondurme[3][3];
	double t_k_oteleme[3][3];
	
	// oteleme matrisini tan�ml�yoruz 
	double t_oteleme[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, y, 1} };
	
	//��geni verilen do�ru fonksiyonuna g�re �teleme i�lemi yap�yoruz 
	//olu�an matrisi k_t_oteleme matrisine at�yoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=t_cisim[i][k]*t_oteleme[k][j];		
		    k_t_oteleme[i][j]=flag;
  }
}		
	// d�nd�rme matrisini tan�ml�yoruz
	double t_dondurme[3][3] = { {cos(radyan), sin(radyan), 0}, {-sin(radyan), cos(radyan), 0}, {0, 0, 1} };

	//��geni verilen fonksiyona g�re d�nd�rme i�lemi yap�yoruz 
	//olu�an matrisi k_t_dondurme matrisine at�yoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=k_t_oteleme[i][k]*t_dondurme[k][j];		
		    k_t_dondurme[i][j]=flag;
  }
}

	//yans�tma matrisini tan�ml�yoruz
	double t_yansitma[3][3] = { {-1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	//��geni verilen fonksiyona g�re yans�tma i�lemi yap�yoruz
	//olu�an matrisi k_t_yansitma matrisine at�yoruz
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=k_t_dondurme[i][k]*t_yansitma[k][j];		
		    k_t_yansitma[i][j]=flag;
  }
}
	double k_dondurme[3][3] = { {cos(radyan), -sin(radyan), 0}, {sin(radyan), cos(radyan), 0}, {0, 0, 1} };
	
	//��geni verilen fonksiyona g�re d�nd�rme i�lemi yap�yoruz 
	//olu�an matrisi k_t_dondurme matrisine at�yoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=k_t_yansitma[i][k]*k_dondurme[k][j];		
		    t_k_dondurme[i][j]=flag;
  }
}
	double k_oteleme[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, -y, 1} };
	
	//��geni verilen do�ru fonksiyonuna g�re �teleme i�lemi yap�yoruz 
	//olu�an matrisi k_t_oteleme matrisine at�yoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=t_k_dondurme[i][k]*k_oteleme[k][j];		
		    t_k_oteleme[i][j]=flag;
  }
}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			k_cisim[i][j] = t_k_oteleme[i][j];
  }
}	


	dy = (100*b+c)/a;
	dx = (a*(-100)-c)/b;
	
	xa = k_cisim [0][0];
	ya = k_cisim [0][1];
	
	xb = k_cisim [1][0];
	yb = k_cisim [1][1];
	
	xc = k_cisim [2][0];
	yc = k_cisim [2][1];
	
	
	return xa,ya,xb,yb,xc,yc,dy,dx;
	
}

struct bezierNokta{
	double x;
	double y;
};
struct bezierNokta p_bir;
struct bezierNokta p_iki;
struct bezierNokta p_uc;

struct bezierNokta KontrolNoktaUretici(float u){
	float tempX,tempY;
	struct bezierNokta tempBezierNokta;
	tempX=(p_bir.x*u)+(p_iki.x*2*u*(1-u))+(p_uc.x*(pow(u,2)));
	tempY=(p_bir.y*u)+(p_iki.y*2*u*(1-u))+(p_uc.y*(pow(u,2)));
	tempBezierNokta.x=tempX;
	tempBezierNokta.y=tempY;
	
	return (tempBezierNokta);
	
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    int i=0;
    for(i=-10;i<=40;i++){
        glVertex3f(i,-40,0);
        glVertex3f(i,40,0);
    }
    for(i=-10;i<=40;i++){
        glVertex3f(-40,i,0);
        glVertex3f(40,i,0);
    }
 	glEnd();

	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
    glVertex3f(0,50,0);
    glVertex3f(0,-50,0);
    glEnd();
    
    glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
    glVertex3f(50,0,0);
    glVertex3f(-50,0,0);
	glEnd();
	
	glColor3f(0.0,0.5,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(ax,ay);
		glVertex2f(bx,by);
		glVertex2f(cx,cy);
	glEnd();
	
	
	glColor3f(0.0,0.5,1.0);
	float j=0;//hassasiyet
	glBegin(GL_LINES);
		glVertex2i(100,dy);
		glVertex2i(dx,-100);
	glColor3f(0.0,1.0,1.0);
	
	struct bezierNokta kontrolNokta;
	for(j=0;j<=1.05;j+=0.05){
	kontrolNokta=KontrolNoktaUretici(j);
		glVertex3f(kontrolNokta.x,kontrolNokta.y,1);
	}
	glEnd();
	
	//yans�ma i�lemine u�rayan ��gen
	glColor3f(0.0,0.5,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(xa,ya);
		glVertex2f(xb,yb);
		glVertex2f(xc,yc);
	glEnd();
	
	glFlush();
}



int main(int argc, char *argv[]){
	
	setlocale(LC_ALL, "Turkish");

	printf("A noktas�n�n x eksenini kesti�i noktay� giriniz: ");
	scanf("%lf",&ax);
	printf("A noktas�n�n y eksenini kesti�i noktay� giriniz: ");
	scanf("%lf",&ay);
	
	printf("B noktas�n�n x eksenini kesti�i noktay� giriniz: ");
	scanf("%lf",&bx);
	printf("B noktas�n�n y eksenini kesti�i noktay� giriniz: ");
	scanf("%lf",&by);
	
	printf("C noktas�n�n x eksenini kesti�i noktay� giriniz: ");
	scanf("%lf",&cx);
	printf("C noktas�n�n y eksenini kesti�i noktay� giriniz: ");
	scanf("%lf",&cy);
	
	

	printf("Do�runun fonksiyonunu giriniz(a veya b s�f�r girilemez) \n");
	printf("ay = bx+c --> a:");
	scanf("%lf",&a);
	printf("ay = bx+c --> b:");
	scanf("%lf",&b);
	printf("ay = bx+c --> c:");
	scanf("%lf",&c);
	

 	derece = b/a;
	radyan =derece * (180/PI);
	
	//verilen do�ruya g�re hesaplanan derece 45 ile  315 aras�nda ise do�ruya_g�re_yansitma_x fonksiyonu �a�r�lacak
	//de�ilse do�ruya_g�re_yansitma_y fonksiyonu �a�r�lacak
	
	if(radyan > 45 && radyan < 315){
		dogruya_gore_yansitma_x();
	}
	else{
		dogruya_gore_yansitma_y();
	}
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("SADIK OKTAY Bi�ici");
    
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0,20.0,-10.0,20.0,-1.0,1.0);
    
    
    glutDisplayFunc(display);
    glutMainLoop();
    
    
	return 0;
}