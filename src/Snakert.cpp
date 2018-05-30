/** \file   Snakert.cpp
 *  \author Hasenfresser
 *  \date   18-05-30
 *  \brief  Header file of "Snakert".
 */

#pragma     once

#include    "Snakert.hpp"

#include    <ctime>
#include    <iostream>  // TODO (Hasenfresser#1): Delete if not longer needed

namespace Snakert {

// Static variables
bool    s_bFullscreen   =   false;

int     s_iResHor       =   0;      /**< Horizontal resolution of window */
int     s_iResVert      =   0;      /**< Vertical resolution of window */

int     s_iResHorOld    =   0;      /**< Old horizontal resolution of window if not fullscreen */
int     s_iResVertOld   =   0;      /**< Old vertical resolution of window if not fullscreen */

int     s_iLeftBorder   =   0;      /**< Left border pixels */
int     s_iRightBorder  =   0;      /**< Right border pixels */
int     s_iTopBorder    =   0;      /**< Top border pixels */
int     s_iBotBorder    =   0;      /**< Bot border pixels */

int     s_iBlocksHor    =   0;      /**< Number of horizontal blocks */
int     s_iBlocksVert   =   0;      /**< Number of vertical blocks */

int     s_iArgC         =   0;      /**< Number of arguments */
char**  s_pcArgV        =   NULL;   /**< Pointer to argument list */

void Snakert::initGame() {
    // Calculate blocks, window and field sizes
    s_iBlocksHor    =   DEFAULT_BLOCKS_HOR;
    s_iBlocksVert   =   DEFAULT_BLOCKS_VERT;

    s_iLeftBorder   =   MIN_PIXEL_LEFT_BORDER;
    s_iRightBorder  =   MIN_PIXEL_RIGHT_BORDER;
    s_iTopBorder    =   MIN_PIXEL_TOP_BORDER;
    s_iBotBorder    =   MIN_PIXEL_BOT_BORDER;

    s_iResHorOld    =   s_iLeftBorder                           +
                        s_iBlocksHor    *   MIN_PIXEL_PER_BLOCK +
                        s_iRightBorder;

    s_iResVertOld   =   s_iTopBorder                            +
                        s_iBlocksVert   *   MIN_PIXEL_PER_BLOCK +
                        s_iBotBorder;

    // Init GLUT
    glutInit(&s_iArgC,  s_pcArgV);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowSize(s_iResHor,   s_iResVert);
    glutCreateWindow(WINDOW_TITLE.c_str());
    glClearColor(0.0,   0.0,    0.0,    0.0 );
    gluOrtho2D(0,   s_iResHor,  0,  s_iResVert);

    glutDisplayFunc(display);
    glutMouseFunc(mouseClickEvent);
    glutKeyboardFunc(keyboardEvent);
    glutReshapeFunc(reshapeEvent);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,   GL_ONE_MINUS_SRC_ALPHA);

    glutMainLoop();
}

void Snakert::newGame() {

}

void Snakert::reshape() {
    if(!s_bFullscreen) {
        s_iResHorOld    =   glutGet(GLUT_WINDOW_WIDTH);
        s_iResVertOld   =   glutGet(GLUT_WINDOW_HEIGHT);
    }

    s_iResHor       =   glutGet(GLUT_WINDOW_WIDTH);
    s_iResVert      =   glutGet(GLUT_WINDOW_HEIGHT);

    int iResHor     =   s_iBlocksHor    *   MIN_PIXEL_PER_BLOCK +   MIN_PIXEL_LEFT_BORDER   +   MIN_PIXEL_RIGHT_BORDER;
    int iResVert    =   s_iBlocksVert   *   MIN_PIXEL_PER_BLOCK +   MIN_PIXEL_TOP_BORDER    +   MIN_PIXEL_BOT_BORDER;

    if(s_iResHor    <   iResHor     or  s_iResVert   <   iResVert        ) {
        if(s_iResHor    <   iResHor )
            s_iResHor   =   iResHor;

        if(s_iResVert   <   iResVert    )
            s_iResVert  =   iResVert;

        glutReshapeWindow(s_iResHor,    s_iResVert);
    }

    int iFieldHor   =   0;  /**< Actual horizontal field resolution*/
    int iFieldVert  =   0;  /**< Actual vertical field resolution */

    std::cout << "Resolution:\t"    <<  s_iResHor << " " << s_iResVert << std::endl;

    iFieldHor       =   s_iResHor   -   MIN_PIXEL_LEFT_BORDER   -   MIN_PIXEL_RIGHT_BORDER;
    iFieldVert      =   s_iResVert  -   MIN_PIXEL_TOP_BORDER    -   MIN_PIXEL_BOT_BORDER;

    std::cout << "Field (orig):\t"  <<  iFieldHor << " " << iFieldVert << std::endl;

    iFieldHor       =   iFieldHor   /   s_iBlocksHor    *   s_iBlocksHor;
    iFieldVert      =   iFieldVert  /   s_iBlocksVert   *   s_iBlocksVert;

    std::cout << "Field (fixed):\t" <<  iFieldHor << " " << iFieldVert << std::endl;

    s_iLeftBorder   =   (double)MIN_PIXEL_LEFT_BORDER   /   (   MIN_PIXEL_LEFT_BORDER   +   MIN_PIXEL_RIGHT_BORDER  )   *   (   s_iResHor   -   iFieldHor   )   +   0.5;
    s_iRightBorder  =   s_iResHor   -   iFieldHor   - s_iLeftBorder;

    s_iTopBorder    =   (double)MIN_PIXEL_TOP_BORDER    /   (   MIN_PIXEL_TOP_BORDER    +   MIN_PIXEL_BOT_BORDER    )   *   (   s_iResVert  -   iFieldVert  )   +   0.5;
    s_iBotBorder    =   s_iResVert  -   iFieldVert  - s_iTopBorder;

    std::cout << "Left/Right:\t"    <<  s_iLeftBorder << " " << s_iRightBorder << std::endl;
    std::cout << "Top/Bot:\t"    <<  s_iTopBorder << " " << s_iBotBorder << std::endl << std::endl;
}

void Snakert::display() {
    std::cout   <<                  s_iLeftBorder   <<  "   "   <<                  s_iBotBorder  <<  std::endl;
    std::cout   <<                  s_iLeftBorder   <<  "   "   <<  s_iResVert  -   s_iTopBorder  <<  std::endl;
    std::cout   <<  s_iResHor   -   s_iRightBorder  <<  "   "   <<  s_iResVert  -   s_iTopBorder  <<  std::endl;
    std::cout   <<  s_iResHor   -   s_iRightBorder  <<  "   "   <<                  s_iBotBorder  <<  std::endl << std::endl;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor4f(1.0,  1.0,    1.0,    1.0 );

        glVertex2i(                 s_iLeftBorder,                  s_iBotBorder);
        glVertex2i(                 s_iLeftBorder,  s_iResVert  -   s_iTopBorder);
        glVertex2i(s_iResHor    -   s_iRightBorder, s_iResVert  -   s_iTopBorder);
        glVertex2i(s_iResHor    -   s_iRightBorder,                 s_iBotBorder);
    glEnd();

    glFlush();
}

void Snakert::reshapeEvent(int p_iWidth, int p_iHeight) {
    reshape();
}

void Snakert::mouseClickEvent(int p_iButton, int p_iState, int p_iX, int p_iY) {

}

void Snakert::keyboardEvent(unsigned char p_ucKey,  int p_iX,   int p_iY) {
    if(p_ucKey  == 'p') {   // TODO (Hasenfresser:2) Global variable
        s_bFullscreen   =   !s_bFullscreen;

        if(s_bFullscreen)
            glutFullScreen();
        else
            glutReshapeWindow(s_iResHorOld, s_iResVertOld);
    }

}

Snakert::Snakert(int p_iArgC, char *p_pcArgV[]) {
    srand(time(NULL));

    s_iArgC     =   p_iArgC;
    s_pcArgV    =   p_pcArgV;

    initGame();
}

Snakert::~Snakert() { }

}
