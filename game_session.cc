#include "game_session.h"

#include <iostream>
#include <memory>

namespace gameofsticks {

Session::Session(GameType type, 
                 std::vector<std::string> listOfNames,
                 std::vector<int> sticksAllowed,
                 int sticksNumber) :
                    game_type_(type),
                    sticksAllowed_(sticksAllowed),
                    sticksNumber_(sticksNumber) {
  for(int i = 0 ; i < listOfNames.size(); ++i) {
    players_.push_back(std::unique_ptr<gameofsticks::Player> (new Player(listOfNames[i])));
  } 
}

std::string Session::ToString(GameType type) {
  switch (type) {
    case GameType::PLAYER_V_PLAYER:
      return std::string("Player v. Player");
    case GameType::PLAYER_V_AI:
      return std::string("Player v. AI");
    case GameType::AI_V_AI:
      return std::string("AI v. AI");
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

  std::cout << "Game session of type [" << ToString(game_type_) << "] with players:" << std::endl;
  for(int i = 0; i < players_.size(); ++i) {
    std::cout << players_[i] -> name_ << std::endl;
    players_[i] -> PrintMemory();
  }
  PrintTestStats();
}

void Session::PrintTestStats() {
  std::cout << "Number of sticks: " << sticksNumber_ << std::endl;
  std::cout << "Sticks allowed: ";
  for(int i = 0; i < sticksAllowed_.size(); ++i) {
    std::cout << sticksAllowed_[i] << ' '; 
  }
  std::cout << std::endl;
}

}
