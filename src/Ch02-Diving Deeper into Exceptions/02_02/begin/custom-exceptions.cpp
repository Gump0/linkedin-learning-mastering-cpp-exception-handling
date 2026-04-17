#include <iostream>
#include <stdexcept>
#include <string>
#include <iostream>

class InsufficientDiskSpaceException : public std::runtime_error
{
public:
  InsufficientDiskSpaceException(const std::string &msg) : std::runtime_error(msg) {}
};

void checkDiskSpace(unsigned long availableSpaceMB)
{
  const unsigned long requiredSpaceMB = 100; // how many megabytes we need.

  if (availableSpaceMB < requiredSpaceMB)
  {
    throw InsufficientDiskSpaceException("Insufficient disk space");
  }
}

int main()
{
  unsigned long spaceToTest[] = {120, 100, 69};

  for (unsigned long space : spaceToTest)
  {
    try
    {
      checkDiskSpace(space);
      std::cout << "Sufficient Disk Space: " << space << std::endl;
    }
    catch (const std::runtime_error &e)
    {
      std::cerr << "ERROR : " << e.what() << "Available space : " << space << "MB" << std::endl;
    }
  }

  return 0;
}