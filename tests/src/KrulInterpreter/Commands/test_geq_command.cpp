#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class GeqCommandTests : public ::testing::Test
{
    public:
        GeqCommandTests() = default;
};

TEST_F(GeqCommandTests, geq_request_with_label)
{
    // Arrange
    const std::string krulInput = "5\n5\n>loop\ngeq\n:loop\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST_F(GeqCommandTests, geq_request_not_equal_does_no_jump)
{
    // Arrange
    const std::string krulInput = "6\n5\n6\ngeq\n3\n3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(6, krulProgram.memory.getInstructionIndex());
}

TEST_F(GeqCommandTests, geq_equal_does_jump)
{
    // Arrange
    const std::string krulInput = "5\n5\n6\ngeq\n3\n3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(7, krulProgram.memory.getInstructionIndex());
}