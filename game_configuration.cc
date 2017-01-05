#include "game_configuration.h"

#include <string>
#include <vector>
#include <algorithm>

#include "utilities.h"

namespace gameofsticks {

Configuration::Configuration(int argc, char* argv[]) {
  ConfigureAllDefaults();
  if (argc == 1) {
    return;
  }
  dumpOptions(argc, argv);
  configureOptions();

}

void Configuration::dumpOptions(int size, char* inputs[]) {
  for(int i = 0; i < size-1; ++i) {
    options_.emplace_back(inputs[i+1]);
  }
}

bool Configuration::isHelp() {
  if(std::find(options_.begin(), options_.end(), "-h") != options_.end()) {
    printHelp();
    return true;
  }
  return false;
}

void Configuration::printHelp() {
  std::cout << "Options to customize the game:" << std::endl
            << "Include -n and a number to set the number of sticks" << std::endl
            << "Include -p and a name to add a player by that name" << std::endl
            << "Include -g and pvp, pva, or ava" << std::endl
            << "Inlcude -m and numbers to specify valid moves" << std::endl;
  std::cout << std::endl;
}

void Configuration::configureOptions() {

  char last = ' ';
  bool hitP = false;
  bool hitM = false;
  for (int i = 0; i < options_.size(); ++i) {
    if (options_[i][0] == '-') {
      last = options_[i][1];
    }
    else {
      switch(last) {
        std::string::size_type sz;
        case 'n': 
          sticks_number_ = std::stoi(options_[i], &sz);
          break;
        case 'p': 
          if (!hitP) {
            players_.clear();
            hitP = true;
          }
          players_.emplace_back(options_[i]);
          break;
        case 'g': 
          setGameType(options_[i]);
          break;
        case 'm': 
          if (!hitM) {
            valid_moves_.clear();
            hitM = true;
          }
          valid_moves_.emplace_back(std::stoi(options_[i], &sz));
          break;
        default: 
          std::cout << "Bad Input" << std::endl;
          return;
      } 
    }
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

void Configuration::setGameType(std::string in) {
  if (in == "pvp") {
      game_type_ = GameType::PLAYER_V_PLAYER;
  }
  else if (in == "pva") {
      game_type_ = GameType::PLAYER_V_AI;
  }
  else if (in == "ava") {
      game_type_ = GameType::AI_V_AI;
  }
  else {
      std::cout << "Bad game type input" << std::endl;
  }
}

} // namespace gameofsticks
