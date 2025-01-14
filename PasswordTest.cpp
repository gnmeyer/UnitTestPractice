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

TEST(PasswordTest, has_empty_password) {
	Password my_password;
	bool value = my_password.has_mixed_case("\0");
	ASSERT_FALSE(value == false);
}

TEST(PasswordTest, all_lower_case) {
	Password my_password;
	bool value = my_password.has_mixed_case("testpass");
	ASSERT_FALSE(value == false);
}

// TEST(PasswordTest, is_underscore_mixedcase) {
// 	Password my_password;
// 	bool value = my_password.has_mixed_case("Test_Password");
// 	ASSERT_TRUE(value == true);
// }

// TEST(PasswordTest, not_underscore_mixedcase) {
// 	Password my_password;
// 	bool value = my_password.has_mixed_case("Test_password");
// 	ASSERT_TRUE(value == true);
// }


/* Authenticate Cases */
TEST(PasswordTest, is_blank_password) {
	Password my_password;
	bool value = my_password.authenticate("");
	ASSERT_FALSE(value == false);
}

TEST(PasswordTest, is_not_old_password) {
	Password my_password;
	bool value = my_password.authenticate("NewPassword");
	ASSERT_TRUE(value == true);
}

TEST(PasswordTest, is_old_password) {
	Password my_password;
	bool value = my_password.authenticate("ChicoCA-95929");
	ASSERT_FALSE(value == false);
}