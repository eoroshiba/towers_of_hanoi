#include "disc.h"
#include <sstream>
Disc::Disc()
{
}

Disc::Disc(int s)
{
	size = s;
}

Disc::~Disc()
{
}

int Disc::getSize()
{
	return size;
}

bool Disc::setSize(int s)
{
	size = s;
	return true;
}

std::string Disc::toString()
{
	std::stringstream stream;
  stream << size;
  return stream.str();
}

