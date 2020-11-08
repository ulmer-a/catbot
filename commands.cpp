#include <tgbot/tgbot.h>
#include <string>

#include "catbot.h"

void subscribeCommands(TgBot::Bot& bot)
{
  bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, "Hey ich bin die Milli!");
  });

  bot.getEvents().onCommand("minzi", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, getRandomMessage(message->from->firstName).c_str());
  });

  bot.getEvents().onCommand("milli", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, getRandomMessage(message->from->firstName).c_str(),
                             message->messageId);
  });

  bot.getEvents().onCommand("version", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, getVersionInfo().c_str());
  });

  bot.getEvents().onCommand("millipic", [&bot](TgBot::Message::Ptr message) {
    try {
      auto file = TgBot::InputFile::fromFile(getRandomCatPicPath(), "image/jpg");
      bot.getApi().sendPhoto(message->chat->id, file);
    } catch (std::exception& ex)
    {
      std::string msg = "Ups! ich hab grad eine "
                        "exception geschmissen: ";
      bot.getApi().sendMessage(message->chat->id, msg + ex.what());
    }
  });

  bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
    printf("%s %s: %s\n", message->from->firstName.c_str(),
           message->from->lastName.c_str(), message->text.c_str());
  });
}
