#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>

struct point {
	double x, y;
};
std::istream& operator>>(std::istream& is, point& p) {
	return is >> p.x >> p.y;
}
std::ostream& operator<< (std::ostream& os, const point& p) {
	return os << '(' << p.x << ", " << p.y << ')';
}

int main()
{
	std::ifstream f("points.txt");
	std::istream_iterator<point> in(f), ends;
  //ends: defautni s null pointerom kako bi znao da je došao do kraja
	std::list<point> c;
	std::copy(in, ends, std::back_inserter(c));
  //std::back_inserter(c) nadodaje prostor za element u listi c

	std::ostream_iterator<point> os(std::cout, "\n"); // \n - separator
	std::copy(c.cbegin(), c.cend(), os);
  //cbegin, cend: c je const
  //os je target iterator

}
