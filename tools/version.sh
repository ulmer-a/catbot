#! /bin/bash

if [ -z "$1" ]; then
    echo "usage: version.sh <output.h>"
    exit 1
fi

vpath=$1

bot_name="millibot"
bot_maj_version="1"
bot_min_version=`git rev-list --count main`
bot_author="Alexander Ulmer"
bot_build_date=`date --utc --rfc-3339=date`

echo "#pragma once" > $vpath
echo >> $vpath
echo "// Don't change this file. It is auto-generated." >> $vpath
echo >> $vpath
echo "#define BOT_NAME \"$bot_name\"" >> $vpath
echo "#define BOT_VERSION \"v$bot_maj_version.$bot_min_version\"" >> $vpath
echo "#define BOT_AUTHOR \"$bot_author\"" >> $vpath
echo "#define BOT_BUILD_DATE \"$bot_build_date\"" >> $vpath
