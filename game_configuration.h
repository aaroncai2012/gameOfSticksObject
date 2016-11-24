#ifndef GAMEOFSTICKS_CONFIGURATION_H_
#define GAMEOFSTICKS_CONFIGURATION_H_

#include <string>
#include <vector>

namespace gameofsticks {

// different game types that can be played
enum class GameType {
  PLAYER_V_PLAYER,
  PLAYER_V_AI,
  AI_V_AI
};

class Configuration {
  public:
    Configuration(int argc, char* argv[]);

    void PrintConfiguration();

    std::vector<std::string> Players();

  private:
    void ConfigureAllDefaults();

    void ShowHelp();
    void ConfigureFromInputs();

    std::vector<std::string>  inputs_;
    GameType                  game_type_;
    std::vector<std::string>  players_;
    std::vector<int>          valid_moves_;
    int                       sticks_number_;
};

}  // namespace gameofsticks

#endif  // GAMEOFSTICKS_CONFIGURATION_H_
