#include "foo.h"
#include <gtest/gtest.h>

TEST(FooTest, ConstructorTest) {
    Foo foo("TestName");
    EXPECT_EQ(foo.GetName(), "TestName") << "The name should match the value passed to the constructor.";
}

TEST(FooTest, GetNameTest) {
    Foo foo("AnotherName");
    EXPECT_EQ(foo.GetName(), "AnotherName") << "GetName should return the correct name.";
}

TEST(FooTest, PrintTest) {
    Foo foo("PrintName");

    EXPECT_NO_THROW(foo.Print()) << "Print should not throw exceptions.";
}
