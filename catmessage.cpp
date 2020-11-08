#include <vector>

#include "catbot.h"

static std::vector<const char*>messages = {
  "Was geht ab, %s?",
  "%s ist mein Ehrenbrudi!",
  "Läuft bei dir, %s!",
  "Miau, %s!",
  "%s, gib mir Milchile!",
  "Hey %s, kannst du mich streicheln?",
  nullptr
};

const std::string getRandomMessage(const std::string& name)
{
  char buf[100];
  int msg = rand() % messages.size();
  sprintf(buf, messages[msg], name.c_str());
  return std::string(buf);
}
