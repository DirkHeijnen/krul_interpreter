#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class GgeCommandTests : public ::testing::Test
{
    public:
        GgeCommandTests() = default;
};

TEST_F(GgeCommandTests, gge_request_with_label)
{
    // Arrange
    const std::string krulInput = "4\n5\n>loop\ngge\n:loop";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgeCommandTests, gge_request_with_number)
{
    // Arrange
    const std::string krulInput = "4\n5\n4\ngge\n\\text";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgeCommandTests, gge_equal_does_jump)
{
    // Arrange
    const std::string krulInput = "5\n5\n6\ngge\n3\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(7, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgeCommandTests, gge_greater_does_jump)
{
    // Arrange
    const std::string krulInput = "5\n8\n6\ngge\n3\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(6, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgeCommandTests, gge_less_does_not_jump)
{
    // Arrange
    const std::string krulInput = "8\n5\n6\ngge\n3\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(7, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgeCommandTests, gge_with_string_as_argument)
{
    // Todo: Throw exception.
}

TEST_F(GgeCommandTests, gge_non_existing_position)
{
    // Todo: Throw exception.
}

TEST_F(GgeCommandTests, gge_with_negative_number)
{
    // Todo: Throw exception.
}

TEST_F(GgeCommandTests, gge_with_no_argument)
{
    // Todo: Throw exception.
}