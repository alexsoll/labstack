#include "..\Calculator\calculator.cpp"
#include "gtest.h"

TEST(TCalculator, can_create_object) {

	ASSERT_NO_THROW(TCalculator C("2+2"));

}

TEST(TCalculator, false_check_when_opening_brackets_more_then_closing_breackets) {

	TCalculator C("((4-1*3)");
	EXPECT_EQ(0, C.check());
}

TEST(TCalculator, false_check_when_closing_brackets_more_then_opening_breackets) {

	TCalculator C("(3+6)*6)");
	EXPECT_EQ(0, C.check());
}

TEST(TCalculator, false_check_when_the_first_symbol_is_closing_breacket) {

	TCalculator C(")((3+6*6)");
	EXPECT_EQ(0, C.check());
}

TEST(TCalculator, false_check_when_the_last_symbol_is_opening_breacket) {

	TCalculator C("(3-3*6))(");
	EXPECT_EQ(0, C.check());
}

TEST(TCalculator, throw_when_try_topostfix_incorrect_string) {

	TCalculator C(")4-2)(");
	ASSERT_ANY_THROW(C.topostfix());
}

TEST(TCalculator, can_add_two_elements)
{
	TCalculator C("2+3");
	C.topostfix();
	EXPECT_EQ(5, C.calculate()); 
}

TEST(TCalculator, can_multiply_two_elements)
{
	TCalculator C("2*3");
	C.topostfix();
	EXPECT_EQ(6, C.calculate()); 
}

TEST(TCalculator, can_subtrack_two_elements)
{
	TCalculator C("4-3");
	C.topostfix();
	EXPECT_EQ(1, C.calculate()); 
}

TEST(TCalculator, can_devide_two_elements)
{
	TCalculator C("4/2");
	C.topostfix();
	EXPECT_EQ(2, C.calculate()); 
}

TEST(TCalculator, priority_of_operations_is_observed)
{
	TCalculator C("4+1-2*12/2^2");
	C.topostfix();
	EXPECT_EQ(-1, C.calculate()); 
}

TEST(TCalculator, throw_when_try_to_calculate_incorrect_string) {

	TCalculator C(")2+3)(");
	ASSERT_ANY_THROW(C.calculate());
}

