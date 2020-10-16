#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class MulCommandTests : public ::testing::Test
{
    public:
        MulCommandTests() = default;
};

TEST_F(MulCommandTests, mul_request_with_positive_numbers)
{
    // Arrange
    const std::string krulInput = "5\n10\nmul\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(50, krulProgram.memory.stack->takeInt());
}

TEST_F(MulCommandTests, mul_request_with_negative_numbers)
{
    // Arrange
    const std::string krulInput = "5\nneg\n3\nneg\nmul\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(15, krulProgram.memory.stack->takeInt());
}

TEST_F(MulCommandTests, mul_request_with_positive_and_negative_numbers)
{
    // Arrange
    const std::string krulInput = "5\n3\nneg\nmul\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-15, krulProgram.memory.stack->takeInt());
}

TEST_F(MulCommandTests, mul_request_chained_correct_result)
{
    // Arrange
    const std::string krulInput = "5\n10\nmul\n2\nmul\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(100, krulProgram.memory.stack->takeInt());
}

TEST_F(MulCommandTests, mul_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "mul\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}

TEST_F(MulCommandTests, mul_number_with_string)
{
    // Arrange
    const std::string krulInput = "\\hello\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IllegalArgumentException);
}