#include "player.h"

#include <iostream>
#include <string>
#include <vector>

namespace gameofsticks {

Player::Player(std::string name) {
  name_ = name;
  memory_ = std::vector<std::vector<int>>(20, std::vector<int>(3, 1));
}

std::vector<std::vector<int>> Player::GetMemory() {
  return memory_;
}

}  // namespace gameofsticks
