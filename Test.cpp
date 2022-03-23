/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Dvir Biton>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "Direction.hpp"
#include "Notebook.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("Good input")
{
	Notebook n;
	n.write(0, 0, 0, Direction::Horizontal, "stam");
	CHECK((n.read(0, 0, 0, Direction::Horizontal, 4)) == ("stam"));
	n.write(30, 0, 0, Direction::Horizontal, "stam");
	CHECK((n.read(30, 0, 0, Direction::Horizontal, 4)) == ("stam"));
	n.write(31, 0, 0, Direction::Vertical, "stam");
	CHECK((n.read(31, 0, 0, Direction::Vertical, 4)) == ("stam"));
	CHECK((n.read(0, 6, 0, Direction::Horizontal, 4)) == ("____"));
	CHECK((n.read(0, 6, 0, Direction::Vertical, 4)) == ("____"));
	n.write(0, 1, 0, Direction::Horizontal, "abcd");
	CHECK(n.read(0, 1, 0, Direction::Horizontal, 4) == "abcd");
	n.erase(0, 2, 0, Direction::Horizontal, 4);
	CHECK((n.read(0, 2, 0, Direction::Horizontal, 3)) == ("~~~"));
	CHECK((n.read(0, 2, 0, Direction::Horizontal, 4)) == ("~~~~"));
	CHECK((n.read(0, 2, 0, Direction::Horizontal, 5)) == ("~~~~_"));
	CHECK((n.read(0, 0, 0, Direction::Vertical, 3)) == ("sa~"));
	CHECK((n.read(0, 0, 1, Direction::Vertical, 4)) == ("tb~_"));
	CHECK((n.read(0, 0, 2, Direction::Vertical, 2)) == ("ac"));
}
TEST_CASE("NOT THROW")
{
	Notebook n;
	CHECK_NOTHROW(n.erase(29, 99, 1, Direction::Horizontal, 2));
	CHECK_NOTHROW(n.erase(29, 99, 1, Direction::Vertical, 2));
}

TEST_CASE("bad input")
{
	Notebook n;
	for ( int i = 2; i < 20; i++)
	{
		CHECK_THROWS(n.erase(0, 0, 99, Direction::Horizontal, i)); // col + numofchars >= 100
	}
	CHECK_THROWS(n.erase(0, 0, 0, Direction::Horizontal, 101)); // col + numofchars >= 100
	CHECK_THROWS(n.read(0, 0, 51, Direction::Horizontal, 101)); // col + numofchars >= 100
}