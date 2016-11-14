#ifndef GAMEOFSTICKS_PLAYER_H_
#define GAMEOFSTICKS_PLAYER_H_

#include <string>
#include <vector>

namespace gameofsticks {

class Player {
  public:
    Player(std::string name);

    std::vector<std::vector<int>> GetMemory();

    std::string name_;

  private:
    std::vector<std::vector<int>> memory_;
};

}  // namespace gameofsticks

#endif  // GAMEOFSTICKS_PLAYER_H_
