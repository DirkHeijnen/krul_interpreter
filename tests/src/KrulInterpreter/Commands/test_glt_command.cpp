#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class GltCommandTests : public ::testing::Test
{
    public:
        GltCommandTests() = default;
};

TEST(GltCommandTests, glt_request_with_label)
{
    // Arrange
    const std::string krulInput = "5\n4\n>loop\nglt\n:loop\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST(GltCommandTests, glt_request_with_number)
{
    // Arrange
    const std::string krulInput = "5\n4\n4\nglt\n\\text\\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.getInstructionIndex());
}

TEST(GltCommandTests, glt_equal_does_no_jump)
{
    // Arrange
    const std::string krulInput = "5\n5\n6\nglt\n3\n3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(6, krulProgram.memory.getInstructionIndex());
}

TEST(GltCommandTests, glt_greater_does_no_jump)
{
    // Arrange
    const std::string krulInput = "5\n8\n6\nglt\n3\n3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(7, krulProgram.memory.getInstructionIndex());
}

TEST(GltCommandTests, glt_less_does_jump)
{
    // Arrange
    const std::string krulInput = "8\n5\n6\nglt\n3\n3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(6, krulProgram.memory.getInstructionIndex());
}

TEST(GltCommandTests, glt_with_string_as_argument)
{
    // Todo: Throw exception.
}

TEST(GltCommandTests, glt_non_existing_position)
{
    // Todo: Throw exception.
}

TEST(GltCommandTests, glt_with_negative_number)
{
    // Todo: Throw exception.
}

TEST(GltCommandTests, glt_with_no_argument)
{
    // Todo: Throw exception.
}