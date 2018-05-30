/** \file   main.cpp
 *  \author Hasenfresser
 *  \date   18-05-25
 *  \brief  Main file of "Snakert".
 */

#include "src/Snakert.hpp"

/** \brief  main function of "Snakert"
 *
 *  \param  p_iArgC int
 *  \param  p_pArgV[] char*
 *  \return int Success state
 */
int main(int p_iArgC, char *p_pArgV[]) {
    Snakert::Snakert Game(p_iArgC, p_pArgV);

    return EXIT_SUCCESS;
}
