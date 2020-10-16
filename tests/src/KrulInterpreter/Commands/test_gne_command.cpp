#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class GneCommandTests : public ::testing::Test
{
    public:
        GneCommandTests() = default;
};

TEST_F(GneCommandTests, gne_request_with_label)
{
    // Arrange
    const std::string krulInput = "6\n5\n>loop\ngne\n:loop\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST_F(GneCommandTests, gne_request_with_number)
{
    // Arrange
    const std::string krulInput = "6\n5\n4\ngne\n\\text\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST_F(GneCommandTests, gne_equal_does_no_jump)
{
    // Arrange
    const std::string krulInput = "5\n5\n6\ngne\n3\n3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(6, krulProgram.memory.getInstructionIndex());
}

TEST_F(GneCommandTests, gne_not_equal_does_jump)
{
    // Arrange
    const std::string krulInput = "6\n5\n6\ngne\n3\n3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(7, krulProgram.memory.getInstructionIndex());
}