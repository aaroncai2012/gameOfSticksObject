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
  /*
    if (player_one_ && player_two_) {
      std::cout << "Game session of type [" << ToString(game_type_) << "] with players:" << std::endl;
      std::cout << "    " << player_one_ -> name_ << std::endl;
      player_one_ -> PrintMemory();
      std::cout << "    " << player_two_ -> name_ << std::endl;
      player_two_ -> PrintMemory();
    } else {
      std::cout << "Game session incomplete." << std::endl;
    }
  */

  game_setup_.PrintConfiguration();

  for (int i = 0; i < players_.size(); ++i) {
    std::cout << players_[i] << std::endl;
  }
}

}  // namespace gameofsticks
