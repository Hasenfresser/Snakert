/** \file   Snakert.hpp
 *  \author Hasenfresser
 *  \date   18-05-24
 *  \brief  Header file of "Snakert".
 *
 *  An open source clone of classic "Snake".
 */

#pragma once

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Constants.hpp"

/** \brief  Namespace of "Snakert"
 */
namespace Snakert {

class Snakert {
private:

protected:

    /** \brief  Initializes game
     *
     *  \return void
     */
    static void initGame();

    /** \brief  Creates new game
     *
     *  \return void
     */
    static void newGame();

    /** \brief  Reshapes window
     *
     *  \return void
     */
    static void reshape();

    /** \brief  Displays GUI
     *
     *  \return void
     */
    static void display();

    /** \brief  Event handling when windows is reshaped
     *
     *  \param  p_iWidth int: new window width
     *  \param  p_iHeight int: new window height
     *  \return void
     */
    static void reshapeEvent(int p_iWidth, int p_iHeight);

    /** \brief  Event handling when mouse click event happened
     *
     *  \param  p_iButton int: pressed mouse button
     *  \param  p_iState int: state of pressed mouse button
     *  \param  p_iX int: X position of mouse cursor
     *  \param  p_iY int: Y position of mouse cursor
     *  \return void
     */
    static void mouseClickEvent(int p_iButton, int p_iState, int p_iX, int p_iY);


    /** \brief  Event handling when keyboard event happened
     *
     *  \param  p_cKey unsigned char: pressed key
     *  \param  p_iX int: X position of mouse cursor
     *  \param  p_iY int: Y position of mouse cursor
     *  \return void
     */
    static void keyboardEvent(unsigned char p_ucKey, int p_iX, int p_iY);

public:

    /** \brief  Default constructor
     *
     *  \param  p_iArgC int
     *  \param  P_piArgV[] char*
     */
    Snakert(int p_iArgC, char *p_pcArgV[]);

    /** \brief  Default destructor
     */
    ~Snakert();
};

}
