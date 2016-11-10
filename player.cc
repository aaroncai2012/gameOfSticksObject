#include "player.h"

#include <iostream>
#include <string>
#include <vector>

namespace gameofsticks {

Player::Player(std::string name) {
  name_ = name;
  memory_ = std::vector<std::vector<int>>(20, std::vector<int>(3, 1));
}

void Player::PrintMemory() {
  std::cout << "Memory dump for Player: " << name_ << std::endl;
  for (std::vector<int> turn : memory_) {
    std::cout << "[ ";
    for (int choice : turn) {
      std::cout << choice << " ";
    }
    std::cout << "]" << std::endl;
  }
}

}
