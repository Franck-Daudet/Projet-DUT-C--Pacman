#ifndef GETCH_H
#define GETCH_H

/*!
 * \file getch.h
 * \brief the getch function
 * \author Franck Daudet
 * \version 1.0
 * \date 07/01/21
 */


//https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @return (voir exemple)
 */

int getch(void)
{
  struct termios oldattr, newattr;
  int ch;
  tcgetattr( STDIN_FILENO, &oldattr );
  newattr = oldattr;
  newattr.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
  return ch;
}

#endif // GETCH_H
