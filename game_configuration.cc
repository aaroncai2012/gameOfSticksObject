#include "game_configuration.h"

#include "utilities.h"

namespace gameofsticks {

Configuration::Configuration(int argc, char* argv[]) {
  if (argc == 1) {  // configure w/ defaults if user doesn't configure anything
    ConfigureAllDefaults();
    return;
  }
  for (int i=1; i<argc; ++i) {
    if (std::strcmp(argv[i], "-h") == 0) {
      ShowHelp();  // show help message and exit
    }
    inputs_.emplace_back(argv[i]);
  }
}

void Configuration::PrintConfiguration() {
  std::cout << "Game type:        " << game_type_ << std::endl;
  std::cout << "Players:          " << players_ << std::endl;
  std::cout << "Valid Moves:      " << valid_moves_ << std::endl;
  std::cout << "Number of Sticks: " << sticks_number_ << std::endl << std::endl;
}

std::vector<std::string> Configuration::Players() {
  return players_;
}

void Configuration::ConfigureAllDefaults() {
  game_type_     = GameType::AI_V_AI;
  players_       = {"Bob", "Alice"};
  valid_moves_   = {1, 2, 3};
  sticks_number_ = 20;
}

void Configuration::ShowHelp() {
  std::cout <<
  std::endl << "Usage: ./bin/game.exe [-hgpms]"                                            <<
  std::endl << "            -h               : show help message"                          <<
  std::endl << "            -g <AA|AP|PP>    : game mode, can be"                          <<
  std::endl << "                               AA = AI v. AI"                              <<
  std::endl << "                               AP = AI v. Player"                          <<
  std::endl << "                               PP = Player v. Player"                      <<
  std::endl << "            -p <name>        : specify player name"                        <<
  std::endl << "            -m <valid moves> : # of sticks that can be picked up per move" <<
  std::endl << "            -s <sticks>      : # of sticks in the game"                    <<
  std::endl;

  std::exit(1);
}

}  // namespace gameofsticks
