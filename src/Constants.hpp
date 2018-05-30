/** \file   Constants.hpp
 *  \author Hasenfresser
 *  \date   18-05-30
 *  \brief  Editable constants of "Snakert".
 */

#include   <string>

const   int         MIN_PIXEL_PER_BLOCK     =   32;                                     /**< Minimum pixel per square block */
const   int         MIN_PIXEL_LEFT_BORDER   =   32;                                     /**< Minimum pixels at left border */
const   int         MIN_PIXEL_RIGHT_BORDER  =   32;                                     /**< Minimum pixels at right border */
const   int         MIN_PIXEL_TOP_BORDER    =   64;                                     /**< Minimum pixels at top border */
const   int         MIN_PIXEL_BOT_BORDER    =   32;                                     /**< Minimum pixels at bottom border */

const   int         DEFAULT_BLOCKS_HOR      =   20;                                     /**< Default horizontal blocks of field */
const   int         DEFAULT_BLOCKS_VERT     =   16;                                     /**< Default vertical blocks of field */

const   std::string GAME_NAME               =   "Snakert";                              /**< Name of the game */
const   std::string GAME_VERSION            =   "0.1uc";                                /**< Version of the game */
const   std::string WINDOW_TITLE            =   GAME_NAME + " (" + GAME_VERSION + ')';  /**< Combined window title */
