#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class GgtCommandTests : public ::testing::Test
{
    public:
        GgtCommandTests() = default;
};

TEST_F(GgtCommandTests, ggt_request_with_label)
{
    // Arrange
    const std::string krulInput = "4\n5\n>loop\nggt\n:loop";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgtCommandTests, ggt_request_with_number) {
    // Arrange
    const std::string krulInput = "4\n5\n4\nggt\n\\text";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgtCommandTests, ggt_equal_does_not_jump)
{
    // Arrange
    const std::string krulInput = "5\n5\n6\nggt\n3\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(6, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgtCommandTests, ggt_greater_does_jump)
{
    // Arrange
    const std::string krulInput = "5\n8\n6\nggt\n3\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(6, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgtCommandTests, ggt_less_does_not_jump)
{
    // Arrange
    const std::string krulInput = "8\n5\n6\nggt\n3\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(7, krulProgram.memory.getInstructionIndex());
}

TEST_F(GgtCommandTests, ggt_with_string_as_argument)
{
    // Todo: Throw exception.
}

TEST_F(GgtCommandTests, ggt_non_existing_position)
{
    // Todo: Throw exception.
}

TEST_F(GgtCommandTests, ggt_with_negative_number)
{
    // Todo: Throw exception.
}

TEST_F(GgtCommandTests, ggt_with_no_argument)
{
    // Todo: Throw exception.
}