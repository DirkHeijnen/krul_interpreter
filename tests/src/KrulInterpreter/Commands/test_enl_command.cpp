#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class EnlCommandTests : public ::testing::Test
{
    public:
        EnlCommandTests() = default;
};

TEST_F(EnlCommandTests, enl_with_string)
{
    // Arrange
    const std::string krulInput = "\\test\nenl\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("test\n", krulProgram.memory.stack->takeString());
}

TEST_F(EnlCommandTests, enl_with_number)
{
    // Arrange
    const std::string krulInput = "123\nenl\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("123\n", krulProgram.memory.stack->takeString());
}

TEST_F(EnlCommandTests, enl_with_empty_string)
{
    // Arrange
    const std::string krulInput = "\\\nenl\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("\n", krulProgram.memory.stack->takeString());
}

TEST_F(EnlCommandTests, enl_with_nothing)
{
    // Arrange
    const std::string krulInput = "enl\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}