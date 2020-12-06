#include "Reading.h"

std::ostream& operator<<(std::ostream& os, const Reading& r)
{
	return os << r.hour << ' ' << r.temperature;
}