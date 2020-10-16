#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class DupCommandTests : public ::testing::Test
{
    public:
        DupCommandTests() = default;
};

TEST_F(DupCommandTests, dup_single_time)
{
    // Arrange
    const std::string krulInput = "\\test\ndup\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("test", krulProgram.memory.stack->takeString());
    ASSERT_EQ("test", krulProgram.memory.stack->takeString());
}

TEST_F(DupCommandTests, dup_multiple_times)
{
    // Arrange
    const std::string krulInput = "\\test\ndup\ndup\ndup\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("test", krulProgram.memory.stack->takeString());
    ASSERT_EQ("test", krulProgram.memory.stack->takeString());
    ASSERT_EQ("test", krulProgram.memory.stack->takeString());
}

TEST_F(DupCommandTests, dup_with_number)
{
    // Arrange
    const std::string krulInput = "12\ndup\ndup\ndup\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("12", krulProgram.memory.stack->takeString());
    ASSERT_EQ("12", krulProgram.memory.stack->takeString());
}

TEST_F(DupCommandTests, dup_with_empty_string)
{
    // Arrange
    const std::string krulInput = "\\\ndup\ndup\ndup\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("", krulProgram.memory.stack->takeString());
    ASSERT_EQ("", krulProgram.memory.stack->takeString());
    ASSERT_EQ("", krulProgram.memory.stack->takeString());
}

TEST_F(DupCommandTests, dup_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "dup\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}