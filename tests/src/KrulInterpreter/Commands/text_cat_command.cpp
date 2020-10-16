#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class CatCommandTests : public ::testing::Test
{
    public:
        CatCommandTests() = default;
};

TEST_F(CatCommandTests, cat_with_strings)
{
    // Arrange
    const std::string krulInput = "\\test\n\\run\ncat\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("testrun", krulProgram.memory.stack->takeString());
}

TEST_F(CatCommandTests, cat_with_numbers)
{
    // Arrange
    const std::string krulInput = "12\n34\ncat\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("1234", krulProgram.memory.stack->takeString());
}

TEST_F(CatCommandTests, cat_with_string_and_number)
{
    // Arrange
    const std::string krulInput = "\\test\n34\ncat\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("test34", krulProgram.memory.stack->takeString());
}

TEST_F(CatCommandTests, cat_with_nothing)
{
    // Arrange
    const std::string krulInput = "cat\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}