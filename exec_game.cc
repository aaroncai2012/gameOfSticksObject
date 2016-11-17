#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>

#include "player.h"
#include "game_session.h"

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cout << "Incorrect number of inputs " << std::endl;
    return 1;
  }
  int playerCount = std::atoi(argv[1]);
  int sticksCount = 0;
  if (argc > sticksCount+1){
    sticksCount = std::atoi(argv[playerCount + 2]);
  }
  std::vector<std::string> listOfNames;
  std::vector<int> sticksAllowed;
  for (int i = 2; i < playerCount + 2; ++i) {
    listOfNames.emplace_back(argv[i]);
  }
  for (int i = playerCount+3; i < argc; ++i) {
    sticksAllowed.emplace_back(std::atoi(argv[i]));
  }

  std::unique_ptr<gameofsticks::Session> the_game;
  if (sticksCount && !sticksAllowed.empty()) {
    the_game = std::unique_ptr<gameofsticks::Session>(
            new gameofsticks::Session(gameofsticks::GameType::PLAYER_V_PLAYER,
                                      listOfNames,
                                      sticksAllowed,
                                      sticksCount));
  
  } else {
    the_game = std::unique_ptr<gameofsticks::Session>(
            new gameofsticks::Session(gameofsticks::GameType::PLAYER_V_PLAYER, listOfNames));
  }

  the_game -> PrintSessionStats();
  
  return 0;
}
