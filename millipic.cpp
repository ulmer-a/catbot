#include "catbot.h"
#include <string>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

static std::vector<fs::path> jpgFiles;

static void scanDirectory(const fs::path& root, const std::string& ext)
{
  if (fs::exists(root) && fs::is_directory(root))
  {
    for (auto const& entry :
         fs::recursive_directory_iterator(root))
    {
      if (fs::is_regular_file(entry) &&
          entry.path().extension() == ext)
      {
        jpgFiles.emplace_back(entry.path().filename());
      }
    }
  }
}

const std::string getRandomCatPicPath()
{
  if (jpgFiles.size() == 0)
  {
    scanDirectory(".", ".jpg");

    if (jpgFiles.size() == 0)
      throw std::exception();
  }

  unsigned picsTotal = jpgFiles.size();
  unsigned pic = rand() % picsTotal;

  return jpgFiles[pic].string();
}
