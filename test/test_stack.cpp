#include "..\Calculator\stack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, cant_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> s(10);
  ASSERT_NO_THROW(TStack<int> s1(s));
}

TEST(TStack, copied_TStack_is_equal_to_source_one) 
{
	TStack<int> s(10);
	TStack<int> s1(s);

	EXPECT_EQ(s1, s);
}

TEST(TStack, copied_TStack_has_its_own_memory)
{
	TStack<int> s(10);
	TStack<int> s1(s);
	EXPECT_NE(&s1 , &s);
}

TEST(TStack, can_get_number_of_elements_in_the_stack)
{
  TStack<int> s(4);
  s.push(1);
  EXPECT_EQ(1, s.getsize());
}

TEST(TStack, can_get_maxnumber_of_elements_in_the_stack)
{
  TStack<int> s(4);
  s.push(1);
  EXPECT_EQ(4, s.getmaxsize());
}

TEST(TStack, can_push_element_in_the_stack)
{
  TStack<int> s(4);
  ASSERT_NO_THROW(s.push(3));
}

TEST(TStack, can_pop_element_in_the_stack)
{
  TStack<int> s(4);
  s.push(1);
  ASSERT_NO_THROW(s.pop());
}

TEST(TStack, throws_when_push_element_in_the_full_stack)
{
  TStack<int> s(1);
  s.push(1);
  ASSERT_ANY_THROW(s.push(3));
}

TEST(TStack, throws_when_pop_element_in_the_empty_stack)
{
  TStack<int> s(1);
  ASSERT_ANY_THROW(s.pop());
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> s(4);
	ASSERT_NO_THROW(s = s);
}

TEST(TStack, can_clear_stack)
{
	TStack<int> s(4);
	s.clear();
	EXPECT_EQ(true, s.isempty());
}

TEST(TStack, throws_when_look_for_the_top_element_in_the_empty_stack)
{
  TStack<int> s(1);
  ASSERT_ANY_THROW(s.top());
}

TEST(TStack, can_look_top_element)
{
  TStack<int> s(1);
  s.push(5);
  EXPECT_EQ(5, s.top());
}