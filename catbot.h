#pragma once

#include <string>
#include <tgbot/tgbot.h>

void subscribeCommands(TgBot::Bot& bot);

const std::string getVersionInfo();
const std::string getRandomCatPicPath();
const std::string getRandomMessage(const std::string& name);
