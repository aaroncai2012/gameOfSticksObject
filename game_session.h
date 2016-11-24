#ifndef GAMEOFSTICKS_GAMESESSION_H_
#define GAMEOFSTICKS_GAMESESSION_H_

#include <string>
#include <memory>

#include "game_configuration.h"
#include "player.h"

namespace gameofsticks {

// represents a game played between two players
class Session {
  public:
    Session(Configuration& options);

    void PrintSessionStats();

  private:
    Configuration game_setup_;
    std::vector<std::unique_ptr<gameofsticks::Player>> players_;
};

}  // namespace gameofsticks

#endif  // GAMEOFSTICKS_GAMESESSION_H_
