#include <iostream>
#include <pwd.h>
#include "gtest/gtest.h"

int main(int argc, char **argv)
{
	char buf[1024];
	std::cout << getcwd(buf, sizeof(buf)) << "\n";
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}