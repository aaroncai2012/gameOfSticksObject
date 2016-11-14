#include "game_session.h"

#include <iostream>
#include <memory>

#include "game_configuration.h"
#include "player.h"
#include "utilities.h"

namespace gameofsticks {

Session::Session(Configuration& options) :
          game_setup_(options) {
  for (std::string p : game_setup_.GetPlayerNames()) {
    players_.push_back(std::unique_ptr<gameofsticks::Player> (new Player(p)));
  }
}

void Session::PrintSessionStats() {
  game_setup_.PrintConfiguration();

  for (int i = 0; i < players_.size(); ++i) {
    std::cout << players_[i] << std::endl;
  }
}

}  // namespace gameofsticks
