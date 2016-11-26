#include "game_configuration.h"

#include "utilities.h"

namespace gameofsticks {

Configuration::Configuration(int argc, char* argv[]) {
  ConfigureAllDefaults();  // assume all default configurations
  for (int i=1; i<argc; ++i) {
    if (std::strcmp(argv[i], "-h") == 0) {
      ShowHelp();
    }
    inputs_.emplace(argv[i]);
  }
  ConfigureFromInputs();  // override defaults with user inputs if any
  if (!CheckConfiguredCorrectly()) {
    std::cout << std::endl
              << "Error: incorrect usage with input configurations"
              << std::endl;
    ShowHelp();
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

void Configuration::ConfigureFromInputs() {
  while (!inputs_.empty()) {
    if (!ValidParam(inputs_.front())) {
      std::cout << std::endl
                << "Error: input parameter " << inputs_.front() << " invalid"
                << std::endl;
      ShowHelp();
      return;
    }

    std::string param = inputs_.front();
    inputs_.pop();
    std::queue<std::string> configs;
    while (!inputs_.empty() && !ValidParam(inputs_.front())) {
      configs.push(inputs_.front());
      inputs_.pop();
    }

    AddConfigurationToParam(param, configs);
  }
}

bool Configuration::ValidParam(const std::string &param) {
  return param[0] == '-';
}

void Configuration::AddConfigurationToParam(const std::string &param,
                                            std::queue<std::string> &configurations) {
  if (param == "-g") {
    if (configurations.front() == "AA") {
      game_type_ = GameType::AI_V_AI;
    } else if (configurations.front() == "AP") {
      game_type_ = GameType::PLAYER_V_AI;
    } else if (configurations.front() == "PP") {
      game_type_ = GameType::PLAYER_V_PLAYER;
    } else {
      std::cout << std::endl
                << "Error: invalid game type specified with -g"
                << std::endl;
      ShowHelp();
    }
    configurations.pop();
    if (!configurations.empty()) {  // we only allow one game type
      std::cout << std::endl
                << "Error: exactly 1 game type must be specified with -g"
                << std::endl;
      ShowHelp();
    }

  } else if (param == "-p") {
    if (!configured_players_) {
      players_.clear();
      configured_players_ = true;
    }
    while (!configurations.empty()) {
      players_.push_back(configurations.front());
      configurations.pop();
    }

  } else if (param == "-m") {
    if (!configured_valid_moves_) {
      valid_moves_.clear();
      configured_valid_moves_ = true;
    }
    while (!configurations.empty()) {
      valid_moves_.push_back(std::stoi(configurations.front()));
      configurations.pop();
    }

  } else if (param == "-s") {
    sticks_number_ = std::stoi(configurations.front());
    configurations.pop();
    if (!configurations.empty()) {  // we only allow one game type
      std::cout << std::endl
                << "Error: exactly 1 sticks number must be specified with -s"
                << std::endl;
      ShowHelp();
    }

  } else {
    std::cout << std::endl
              << "Error: invalid parameter " << param << " on input"
              << std::endl;
    ShowHelp();
  }
}

bool Configuration::CheckConfiguredCorrectly() {
  if (configured_players_) {
    if (game_type_ == GameType::PLAYER_V_AI && players_.size() < 1) {
      std::cout << std::endl
                << "Error: at least one player required with selected game type"
                << std::endl;
      return false;
    }
    if (game_type_ == GameType::PLAYER_V_PLAYER && players_.size() < 2) {
      std::cout << std::endl
                << "Error: at least two players required with selected game type"
                << std::endl;
      return false;
    }
  }
  if (configured_valid_moves_ && valid_moves_.empty()) {
    return false;
  }
  return true;
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
