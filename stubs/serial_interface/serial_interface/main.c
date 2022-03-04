// serial_interface.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "serial_interface.h"

int main()
{
    SI_Rx_Handler();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
//   7. In the Solution Explorer,go to soultion file >right click>Retarget project (to sync project file in local PC)
//   8. In the Solution Explorer,go to soultion file >right click>Build.
//   9. Run program: Ctrl + F5 or Debug > Start Without Debugging menu

//  issues faced:
//  issue-1:during .sln file build
//  if you got any build error like "unresolved external symbol SI_Rx_Handler referenced in function main"
//  added and removed extern function declaration for SI_Rx_Handler in maini.c
//  i guess this happends because of file func declaration not recognition issue in VS tool at first time