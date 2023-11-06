/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, minimum_numbers) {
	Password my_password;
	int actual = my_password.psize("a123");
	ASSERT_TRUE(actual > 3);
}




TEST(PasswordTest, mixed_case) {
	Password my_password;
	bool value = my_password.has_mixed_case("Test");
	ASSERT_EQ(value, true);
}


TEST(PasswordTest, all_upper_case) {
	Password my_password;
	bool value = my_password.has_mixed_case("TEST");
	ASSERT_EQ(value, false);
}