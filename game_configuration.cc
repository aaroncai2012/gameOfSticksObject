#include "game_configuration.h"

#include <string>
#include <vector>

#include "utilities.h"

namespace gameofsticks {

Configuration::Configuration(int argc, char* argv[]) {
  if (argc == 1) {
    ConfigureAllDefaults();
    return;
  }
}

void Configuration::PrintConfiguration() {
  std::cout << "Game type:        " << game_type_ << std::endl;
  std::cout << "Players:          " << players_ << std::endl;
  std::cout << "Valid Moves:      " << valid_moves_ << std::endl;
  std::cout << "Number of Sticks: " << sticks_number_ << std::endl << std::endl;
}

std::vector<std::string> Configuration::GetPlayerNames() {
  return players_;
}

void Configuration::ConfigureAllDefaults() {
  game_type_     = GameType::AI_V_AI;
  players_       = {"Bob", "Alice"};
  valid_moves_   = {1, 2, 3};
  sticks_number_ = 20;
}

}  // namespace gameofsticks
