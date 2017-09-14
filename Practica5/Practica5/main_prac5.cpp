//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Meneses Cornejo Kevin Osmar				******//
//*************		Reyes Arag�n Aurora					******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angCodo = 0.0f;
float angHombro = 0.0f;
float angMano = 0.0f;
float angPulgar1 = 0.0f;
float angPulgar2 = 0.0f;
float angInd1 = 0.0f;
float angInd2 = 0.0f;
float angInd3 = 0.0f;
float angMedi1 = 0.0f;
float angMedi2 = 0.0f;
float angMedi3 = 0.0f;
float angAnu1 = 0.0f;
float angAnu2 = 0.0f;
float angAnu3 = 0.0f;
float angMen1 = 0.0f;
float angMen2 = 0.0f;
float angMen3 = 0.0f;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner C�digo Aqu�.
	glPushMatrix();
	//hombro
	glRotatef(angHombro, 0.0, 0.0, 1.0);
		glPushMatrix();
			glScalef(0.5, 0.5, 1.0);
			glColor3f(0.0, 1.0, 1.0);
			prisma();
		glPopMatrix();

		//bicep
		
		glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
		glPopMatrix();
		//codo
		
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angCodo, 0.0, 0.0, 1.0);
		glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		//anteBrazo
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.75, 0.0);
		glScalef(0.5, 1.0, 1.0);
		prisma();
		glPopMatrix();

		//mano
		glTranslatef(0.0, -0.75, 0.0);
		glRotated(angMano, 0.0, 0.0, 1.0);
		glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.75, 0.0);
		glScalef(0.5, 0.5, 1.0);
		prisma();
		glPopMatrix();


		//pulgar
		glPushMatrix();
		glTranslatef(0.25, -0.75, 0.0);
		glRotatef(angPulgar1, 0.0, 0.0, 1.0);
		glTranslatef(0.1, 0.0, 0.0);
			
			glColor3f(0.0, 1.0, 1.0);
			glPushMatrix();
				glScalef(0.2, 0.1, 1.0);
				prisma();
			glPopMatrix();
			//parte 2
			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(angPulgar2, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.2, 0.1, 1.0);
			prisma();

		glPopMatrix();
		//INDICE
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
		glTranslatef(0.1, -0.35, 0.0);
		glRotatef(angInd1, 1.0, 0.0, 0.0);
		glTranslatef(0.1, 0.0, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glPushMatrix();
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
			//parte2
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angInd2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte3
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angInd3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
		glPopMatrix();

		//medio
		//glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
		glTranslatef(0.1, -0.35, 0.0);
		glRotatef(angMedi1, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glPushMatrix();
		glScalef(0.1, 0.2, 1.0);
		prisma();
		glPopMatrix();
		//parte2
		glTranslatef(0.0, -0.10, 0.0);
		glRotatef(angMedi2, 1.0, 0.0, 0.0);
		glTranslatef(-0.05, -0.10, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glPushMatrix();
		glScalef(0.1, 0.2, 1.0);
		prisma();
		glPopMatrix();
		//parte3
		glTranslatef(0.0, -0.10, 0.0);
		glRotatef(angMedi3, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.10, 0.0);
		glColor3f(1.0, 0.0, 0.0);
		glScalef(0.1, 0.2, 1.0);
		prisma();
		glPopMatrix();
		//anular
		//glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
		glTranslatef(0.1, -0.35, 0.0);
		glRotatef(angAnu1, 1.0, 0.0, 0.0);
		glTranslatef(-0.15, 0.0, 0.0);
		glColor3f(0.0, 1.0, 1.0);
		glPushMatrix();
		glScalef(0.1, 0.2, 1.0);
		prisma();
		glPopMatrix();
		//parte2
		glTranslatef(0.0, -0.10, 0.0);
		glRotatef(angAnu2, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.10, 0.0);
		glColor3f(1.0, 0.0, 1.0);
		glPushMatrix();
		glScalef(0.1, 0.2, 1.0);
		prisma();
		glPopMatrix();
		//parte3
		glTranslatef(0.0, -0.10, 0.0);
		glRotatef(angAnu3, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.10, 0.0);
		glColor3f(1.0, 1.0, 0.0);
		glScalef(0.1, 0.2, 1.0);
		prisma();
		glPopMatrix();
		//me�ique
		//glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
		glTranslatef(0.1, -0.35, 0.0);
		glRotatef(angMen1, 1.0, 0.0, 0.0);
		glTranslatef(-0.3, 0.0, 0.0);
		glColor3f(0.0, 1.0, 0.0);
		glPushMatrix();
		glScalef(0.1, 0.2, 1.0);
		prisma();
		glPopMatrix();
		//parte2
		glTranslatef(0.0, -0.10, 0.0);
		glRotatef(angMen2, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.10, 0.0);
		glColor3f(1.0, 1.0, 0.0);
		glPushMatrix();
		glScalef(0.1, 0.2, 1.0);
		prisma();
		glPopMatrix();
		//parte3
		glTranslatef(0.0, -0.10, 0.0);
		glRotatef(angMen3, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.10, 0.0);
		glColor3f(0.0, 1.0, 1.0);
		glScalef(0.1, 0.2, 1.0);
		prisma();
		glPopMatrix();
	

	glPopMatrix();

	
		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
	case '':
		angMen3 += 0.5f;
		break;
	case '':
		angMen3 -= 0.5f;
		break;

	case '':
		angMen2 += 0.5f;
		break;
	case '':
		angMen2 -= 0.5f;
		break;
	case 'm':
		angMen1 += 0.5f;
		break;
	case 'M':
		angMen1 -= 0.5f;
		break;
	case 'n':
		angAnu3 += 0.5f;
		break;
	case 'N':
		angAnu3 -= 0.5f;
		break;
	case 'b':
		angAnu2 += 0.5f;
		break;
	case 'B':
		angAnu2 -= 0.5f;
		break;
	case 'v':
		angAnu1 += 0.5f;
		break;
	case 'V':
		angAnu1 -= 0.5f;
		break;
	case 'c':
		angMedi3 += 0.5f;
		break;
	case 'C':
		angMedi3 -= 0.5f;
		break;
	case 'z':
		angMedi2 += 0.5f;
		break;
	case 'Z':
		angMedi2 -= 0.5f;
		break;
	case 'x':
		angMedi1 += 0.5f;
		break;
	case 'X':
		angMedi1 -= 0.5f;
		break;
	case 'j':
		angInd3 += 0.5f;
		break;
	case 'J':
		angInd3 -= 0.5f;
		break;
	case 'h':
		angInd2 += 0.5f;
		break;
	case 'H':
		angInd2 -= 0.5f;
		break;
	case 'g':
		angInd1 += 0.5f;
		break;
	case 'G':
		angInd1 -= 0.5f;
		break;
	case 'F':
		angPulgar2 += 0.5f;
		break;
	case 'f':
		angPulgar2 -= 0.5f;
		break;
	case 'k':
	case 'K':
		angPulgar1 += 0.5f;
		break;
	case 'l':
	case 'L':
		angPulgar1 -= 0.5f;
		break;
	case 'o':
	case 'O':
		angMano += 0.5f;
		break;
	case 'p':
	case'P':
		angMano -= 0.5f;
		break;
	case 'u':
	case 'U':
		angCodo += 0.5f;
		break;
	case 'i':
	case 'I':
		angCodo -= 0.5f;
		break;
		case 't':
		case 'T':
		angHombro += 0.5f;
		break;
		case 'y':
		case 'Y':
			angHombro -= 0.5f;
			break;
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



