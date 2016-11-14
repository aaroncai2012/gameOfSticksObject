#ifndef GAMEOFSTICKS_UTILITIES_H_
#define GAMEOFSTICKS_UTILITIES_H_

#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "game_configuration.h"
#include "player.h"

namespace gameofsticks {

inline std::string ToString(const GameType& type) {
  switch (type) {
    case GameType::PLAYER_V_PLAYER:
      return std::string("Player v. Player");
    case GameType::PLAYER_V_AI:
      return std::string("Player v. AI");
    case GameType::AI_V_AI:
      return std::string("AI v. AI");
  }
}

template<typename T>
inline std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
  s.put('[');
  char comma[3] = {'\0', ' ', '\0'};
  for( const auto& e : v) {
    s << comma << e;
    comma[0] = ',';
  }
  return s << ']';
}

inline std::ostream& operator<<(std::ostream& s, const GameType& t) {
  return s << ToString(t);
}

inline std::ostream& operator<<(std::ostream& s, const std::unique_ptr<Player>& p) {
  s << "Memory dump for player " << p -> name_ << std::endl;
  for (std::vector<int> turn : p -> GetMemory()) {
    s << turn << std::endl;
  }
  return s;
}

}  // namespace gameofsticks

#endif  // GAMEOFSTICKS_GAMESSION_H_
