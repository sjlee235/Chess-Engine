/******************************************************************************/
/* uci.cpp                                                                    */
/* Seung Jae (Ryan) Lee                                                       */
/******************************************************************************/

#include <iostream>
#include <sstream>
#include <string>

#include "evaluation.h"
#include "board.h"

void main() {
     // The line of command read
     std::string command;
     // A word from command
     std::string token;
     
     Board board;
     Board savedBoard[MAX_MOVENUMBER];
     int saveIndex = 0;

     while (1) {
          // 0. INITIALIZE
          token.clear();

          // 1. GET INPUT FROM UCI
          std::getline(std::cin, command);
          std::istringstream is(command);
          is >> std::skipws >> token;

          // 2. ACT BASED ON INPUT
          if (token == "quit") {
               break;
          }
          else if (token == "uci") {
               std::cout << "id name Nageune\n";
               std::cout << "id author Seung Jae (Ryan) Lee\n";
               std::cout << "uciok\n";
          }
          else if (token == "isready") {
               std::cout << "readyok\n";
          }
          else if (token == "go") {
               Variation PV;
               rootAlphabeta(4, board, &PV, savedBoard, saveIndex);
               // TODO: Output Best Move
               // TODO: Check all options
          }
          
          // 3. UNIMPLEMENTED TOKENS
          else if (token == "debug") {}
          else if (token == "isready") {}
          else if (token == "setoption") {}
          else if (token == "register") {}
          else if (token == "ucinewgame") {}
          else if (token == "position") {}
          else if (token == "stop") {}
          else if (token == "ponderhit") {}

     }
}