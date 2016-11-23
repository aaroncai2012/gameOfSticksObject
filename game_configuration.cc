#include "game_configuration.h"

#include <string>
#include <vector>
#include <algorithm>

#include "utilities.h"

namespace gameofsticks {

Configuration::Configuration(int argc, char* argv[]) {
  if (argc == 1) {
    ConfigureAllDefaults();
    return;
  }
  else { 
    dumpOptions(argc, argv);
  }
}

void Configuration::dumpOptions(int size, char* inputs[]) {
  for(int i = 0; i < size-1; ++i) {
    options_.emplace_back(inputs[i+1]);
  }
}

bool Configuration::isHelp() {
  if(std::find(options_.begin(), options_.end(), "-h") != options_.end()) {
    std::cout << "Options to customize the game:" << std::endl
              << "Include -n and a number to set the number of sticks" << std::endl
              << "Include -p and a name to add a player by that name" << std::endl
              << "Include -g and pvp, pva, or ava" << std::endl;
    std::cout << std::endl;
    return true;
  }
  return false;
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
