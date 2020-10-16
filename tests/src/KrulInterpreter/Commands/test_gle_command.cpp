#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class GleCommandTests : public ::testing::Test
{
    public:
        GleCommandTests() = default;
};

TEST_F(GleCommandTests, gle_request_with_label)
{
    // Arrange
    const std::string krulInput = "5\n4\n>loop\ngle\n:loop";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST_F(GleCommandTests, gle_request_with_number)
{
    // Arrange
    const std::string krulInput = "5\n4\n4\ngle\n\\text";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST_F(GleCommandTests, gle_equal_does_jump)
{
    // Arrange
    const std::string krulInput = "5\n5\n6\ngle\n3\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(7, krulProgram.memory.getInstructionIndex());
}

TEST_F(GleCommandTests, gle_greater_does_no_jump)
{
    // Arrange
    const std::string krulInput = "5\n8\n6\ngle\n3\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(7, krulProgram.memory.getInstructionIndex());
}

TEST_F(GleCommandTests, gle_less_does_jump)
{
    // Arrange
    const std::string krulInput = "8\n5\n6\ngle\n3\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(6, krulProgram.memory.getInstructionIndex());
}

TEST_F(GleCommandTests, gle_with_string_as_argument)
{
    // Todo: Throw exception.
}

TEST_F(GleCommandTests, gle_non_existing_position)
{
    // Todo: Throw exception.
}

TEST_F(GleCommandTests, gle_with_negative_number)
{
    // Todo: Throw exception.
}

TEST_F(GleCommandTests, gle_with_no_argument)
{
    // Todo: Throw exception.
}