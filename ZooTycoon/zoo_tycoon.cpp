/*********************************************************************
** Program Filename: zoo_tycoon.cpp
** Author: Katie Blickenstaff
** Date: 8/1/2020
** Description: Main .cpp file that contains main function
*********************************************************************/

#include "zoo.h"
#include "animal.h"
#include "monkey.h"
#include "sea_otter.h"
#include "sloth.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: main()
** Description: Main function to call the Zoo constructor and start the game
** Parameters: none
** Pre-Conditions: Game not started
** Post-Conditions: Game started
*********************************************************************/
int main(int argc, char const *argv[])
{
    bool play = true;
    while (play == true)
    {
        Zoo z;
        z.play_game();
        z.del_vector();
        play = z.play_again();
    }
}