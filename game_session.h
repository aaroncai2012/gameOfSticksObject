#ifndef GAMEOFSTICKS_GAMESESSION_H_
#define GAMEOFSTICKS_GAMESESSION_H_

#include <string>
#include <memory>

#include "player.h"

namespace gameofsticks {

// different game types that can be played
enum GameType {
  PLAYER_V_PLAYER,
  PLAYER_V_AI,
  AI_V_AI
};

// represents a game played between two players
class Session {
  public:
    Session(GameType type, 
            std::vector<std::string> listOfNames,
            std::vector<int> sticksAllowed = {1, 2, 3},
            int sticksNumber = 20);
 

    void PrintSessionStats();
    void PrintTestStats();

  private:
    std::string ToString(GameType type);

    GameType game_type_;
    std::vector<std::unique_ptr<gameofsticks::Player>> players_;
    int sticksNumber_;
    std::vector<int> sticksAllowed_;
};

}

#endif  // GAMEOFSTICKS_GAMESESSION_H_
