# Telegram catbot

The Telegram cat bot can answer you if you mention her in group chats or write her
a private message. Furthermore, it can send you random cat pics from a folder on your PC.

## Building the Catbot

```
sudo apt install g++ make binutils cmake libssl-dev \
    libboost-system-dev libboost-filesystem-dev lizlib1g-dev

git clone https://github.com/reo7sp/tgbot-cpp
mkdir tgbot-cpp/build
cd tgbot-cpp/build
cmake ..
make -j8
sudo make install

git clone https://github.com/ulmer-a/catbot
mkdir catbot/build
cd catbot/build
cmake ..
make -j8
```

## Creating a chat bot

First read Telegram's introduction to Bots at https://core.telegram.org/bots. Then it's time
to create your bot and optain it's ID and API key. This can be done with the @BotFather in
Telegram (see the link).

## Compiling and installing TgBot lib for C++

Basically, the API provides a HTTPS connection where you can pass and receive some JSON
in order to talk with your clients.

I've used TgBot lib to make the whole thing a little easier, as I didn't want to mess with
curl and JSON requests directly. There are also other implementations for python & co available.

TgBot lib: https://github.com/reo7sp/tgbot-cpp 

I cloned the repo, compiled and installed the library, so I could use it in my own project. There
are some dependencies though, so make sure to take care of them, too.

The samples in the repu are very helpful as well.

## Programming the TgBot

From there you can just go ahead and write a program using TgLib, plug in your API key and
you're done. Make sure you link with `-lTgBot -lboost_system -lssl -lcrypto -lpthread`

See the project files for more info and examples on how to layout your program.

## Running the Bot

I run the program on a small Linux server that I have lying around. There's no port forwarding
etc. necessary, because its just a plain HTTPS connection.

Have fun!
