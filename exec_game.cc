#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>

#include "player.h"
#include "game_session.h"

int main(int argc, char* argv[]) {
  /*
      if (argc < 4) {
        std::cout << "Incorrect number of inputs " << std::endl;
        return 1;
      }
      int playerCount = std::atoi(argv[1]);
      int sticks_count = 0;
      if (argc > sticksCount+1){
        sticksCount = std::atoi(argv[playerCount + 2]);
      }
      std::vector<std::string> names_list;
      std::vector<int> sticks_allowed;
      for (int i = 2; i < playerCount + 2; ++i) {
        names_list.emplace_back(argv[i]);
      }
      for (int i = playerCount+3; i < argc; ++i) {
        sticks_allowed.emplace_back(std::atoi(argv[i]));
      }
  */

  gameofsticks::Configuration options(argc, argv);

  std::unique_ptr<gameofsticks::Session> the_game = std::unique_ptr<gameofsticks::Session>(
            new gameofsticks::Session(
                    options.GetGameType(),
                    options.GetPlayerNames(),
                    options.GetValidMoves(),
                    options.GetSticksNumber());

  the_game -> PrintSessionStats();
  
  return 0;
}
