/** \file   Snakert.cpp
 *  \author Hasenfresser
 *  \date   18-05-24
 *  \brief  Header file of "Snakert".
 */

#pragma once
#include    "Snakert.hpp"

#include    <ctime>
#include    <iostream>  // TODO (Hasenfresser#1): Delete if not longer needed

namespace Snakert {

// Static variables
bool    s_bFullscreen   =   false;

int     s_iResHor       =   0;      /**< Horizontal resolution of window */
int     s_iResVert      =   0;      /**< Vertical resolution of window */

int     s_iArgC         =   0;      /**< Number of arguments */
char**  s_pcArgV        =   NULL;   /**< Pointer to argument list */

void Snakert::initGame() {
    s_iResHor   =   MIN_PIXEL_LEFT_BORDER                   +
                    DEFAULT_BLOCKS_HOR  *   PIXEL_PER_BLOCK +
                    MIN_PIXEL_RIGHT_BORDER;

    s_iResVert  =   MIN_PIXEL_TOP_BORDER                    +
                    DEFAULT_BLOCKS_VERT *   PIXEL_PER_BLOCK +
                    MIN_PIXEL_BOT_BORDER;

    // Init GLUT
    glutInit(&s_iArgC,  s_pcArgV);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(s_iResHor,   s_iResVert);
    glutCreateWindow(WINDOW_TITLE.c_str());

    gluOrtho2D(0,   s_iResHor,  0,  s_iResVert);
    glutMouseFunc(mouseClickEvent);
    glutKeyboardFunc(keyboardEvent);
    glutReshapeFunc(reshapeEvent);
    glutDisplayFunc(display);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,   GL_ONE_MINUS_SRC_ALPHA);

    // glutFullScreen();


    glutMainLoop();
}

void Snakert::newGame() {

}

void Snakert::reshape() {
    if(s_bFullscreen)
        glutFullScreen();
    else
        glutReshapeWindow(s_iResHor,    s_iResVert);
}

void Snakert::display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glVertex2i(MIN_PIXEL_LEFT_BORDER,                   s_iResVert  -   MIN_PIXEL_TOP_BORDER);
        glVertex2i(s_iResHor    -   MIN_PIXEL_LEFT_BORDER,  s_iResVert  -   MIN_PIXEL_TOP_BORDER);
        glVertex2i(s_iResHor    -   MIN_PIXEL_LEFT_BORDER,  MIN_PIXEL_BOT_BORDER);
        glVertex2i(MIN_PIXEL_LEFT_BORDER,                   MIN_PIXEL_BOT_BORDER);

        //glColor4dv( 1.0,    1.0,    1.0 );
    glEnd();

    /*
    glBegin(GL_QUADS);
        glVertex2i(MIN_PIXEL_LEFT_BORDER,   MIN_PIXEL_TOP_BORDER);
        glVertex2i(MIN_PIXEL_LEFT_BORDER,   MIN_PIXEL_TOP_BORDER);
        glVertex2i(MIN_PIXEL_LEFT_BORDER,   MIN_PIXEL_TOP_BORDER);
        glVertex2i(MIN_PIXEL_LEFT_BORDER,   MIN_PIXEL_TOP_BORDER);

        glColor4dv( 1.0,    1.0,    1.0 );
    glEnd();
    */

    glFlush();
}

void Snakert::reshapeEvent(int p_iWidth, int p_iHeight) {
    reshape();
}

void Snakert::mouseClickEvent(int p_iButton, int p_iState, int p_iX, int p_iY) {

}

void Snakert::keyboardEvent(unsigned char p_ucKey,  int p_iX,   int p_iY) {
    if(p_ucKey  == 'p')
        s_bFullscreen   =   !s_bFullscreen;

    reshape();
}

Snakert::Snakert(int p_iArgC, char *p_pcArgV[]) {
    srand(time(NULL));

    s_iArgC     =   p_iArgC;
    s_pcArgV    =   p_pcArgV;

    initGame();
}

Snakert::~Snakert() { }

}
