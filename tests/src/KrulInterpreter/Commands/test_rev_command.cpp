#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class RevCommandTests : public ::testing::Test
{
    public:
        RevCommandTests() = default;
};

TEST_F(RevCommandTests, rev_single_time)
{
    // Arrange
    const std::string krulInput = "\\test\nrev\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("tset", krulProgram.memory.stack->takeString());
}

TEST_F(RevCommandTests, rev_twice_is_original_string)
{
    // Arrange
    const std::string krulInput = "\\test\nrev\nrev\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("test", krulProgram.memory.stack->takeString());
}

TEST_F(RevCommandTests, rev_single_time_with_number)
{
    // Arrange
    const std::string krulInput = "42\nrev\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("24", krulProgram.memory.stack->takeString());
}

TEST_F(RevCommandTests, rev_single_time_with_emty_string)
{
    // Arrange
    const std::string krulInput = "\\\nrev\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("", krulProgram.memory.stack->takeString());
}

TEST_F(RevCommandTests, rev_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "rev\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}