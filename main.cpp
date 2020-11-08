#include <cstdio>
#include <memory>
#include <pthread.h>
#include <tgbot/tgbot.h>

#include "catbot.h"

int main()
{
  const char* token = getenv("TOKEN");
  if (token == nullptr)
  {
    fprintf(stderr, "usage: api-token environment variable not set!\n");
    return 1;
  }

  srand(time(nullptr));

  TgBot::Bot bot(token);
  subscribeCommands(bot);

  try
  {
    printf("Bot: %s\n", bot.getApi().getMe()->username.c_str());
    TgBot::TgLongPoll longPoll(bot);
    bot.getApi().deleteWebhook();

    while (true)
    {
      longPoll.start();
    }
  }
  catch (TgBot::TgException& e)
  {
    fprintf(stderr, "error: %s\n", e.what());
    return 1;
  }
  return 0;
}
