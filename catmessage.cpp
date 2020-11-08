#include <vector>

#include "catbot.h"
#include "version.h"

static std::vector<const char*>messages = {
  "Was geht ab, %s?",
  "%s ist mein Ehrenbrudi!",
  "Läuft bei dir, %s!",
  "Miau, %s!",
  "%s, gib mir Milchile!",
  "Hey %s, kannst du mich streicheln?",
};

const std::string getRandomMessage(const std::string& name)
{
  char buf[100];
  int msg = rand() % messages.size();
  sprintf(buf, messages[msg], name.c_str());
  return std::string(buf);
}

const std::string getVersionInfo()
{
  return std::string(BOT_NAME " " BOT_VERSION "\n"
                     "built on " BOT_BUILD_DATE "\n"
                     "Written by " BOT_AUTHOR);
}
