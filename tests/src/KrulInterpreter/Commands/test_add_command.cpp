#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class AddCommandTests : public ::testing::Test
{
    public:
        AddCommandTests() = default;
};

TEST_F(AddCommandTests, add_request_correct_result)
{
    // Arrange
    const std::string krulInput = "3\n5\nadd\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(8, krulProgram.memory.stack->takeInt());
}

TEST_F(AddCommandTests, add_number_chained)
{
    // Arrange
    const std::string krulInput = "3\n5\nadd\n2\nadd\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(10, krulProgram.memory.stack->takeInt());
}

TEST_F(AddCommandTests, add_number_with_negative_number)
{
    // Arrange
    const std::string krulInput = "3\n5\nneg\nadd\n1\nadd\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-1, krulProgram.memory.stack->takeInt());
}

TEST_F(AddCommandTests, add_two_negative_numbers)
{
    // Arrange
    const std::string krulInput = "3\nneg\n5\nneg\nadd";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-8, krulProgram.memory.stack->takeInt());
}

TEST_F(AddCommandTests, add_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "add\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}

TEST_F(AddCommandTests, add_number_with_string)
{
    // Arrange
    const std::string krulInput = "\\hello\nadd\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    ASSERT_THROW(krulProgram.execute(), IllegalArgumentException);
}