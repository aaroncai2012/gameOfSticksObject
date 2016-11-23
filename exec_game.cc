#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>

#include "player.h"
#include "game_session.h"

int main(int argc, char* argv[]) {
  gameofsticks::Configuration options(argc, argv);

  if(options.isHelp()) {
    return 0;
  }

  std::unique_ptr<gameofsticks::Session> the_game = 
          std::unique_ptr<gameofsticks::Session>(new gameofsticks::Session(options));

  the_game -> PrintSessionStats();
  
  return 0;
}
