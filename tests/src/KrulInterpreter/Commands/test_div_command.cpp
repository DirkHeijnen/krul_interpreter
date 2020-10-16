#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class DivCommandTests : public ::testing::Test
{
    public:
        DivCommandTests() = default;
};

TEST_F(DivCommandTests, div_request_with_positive_numbers)
{
    // Arrange
    const std::string krulInput = "10\n5\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(2, krulProgram.memory.stack->takeInt());
}

TEST_F(DivCommandTests, div_request_with_positive_equal_numbers)
{
    // Arrange
    const std::string krulInput = "10\n10\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(1, krulProgram.memory.stack->takeInt());
}

TEST_F(DivCommandTests, div_request_with_small_result_scales_down_to_zero)
{
    // Arrange
    const std::string krulInput = "2\n20\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.stack->takeInt());
}

TEST_F(DivCommandTests, div_request_with_negative_equal_numbers)
{
    // Arrange
    const std::string krulInput = "10\nneg\n10\nneg\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(1, krulProgram.memory.stack->takeInt());
}

TEST_F(DivCommandTests, div_request_with_negative_different_numbers)
{
    // Arrange
    const std::string krulInput = "40\nneg\n10\nneg\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(4, krulProgram.memory.stack->takeInt());
}

TEST_F(DivCommandTests, div_request_with_positive_and_negative_different_numbers)
{
    // Arrange
    const std::string krulInput = "40\nneg\n10\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-4, krulProgram.memory.stack->takeInt());
}

TEST_F(DivCommandTests, div_request_chained_correct_result)
{
    // Arrange
    const std::string krulInput = "40\n4\ndiv\n2\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.stack->takeInt());
}

TEST_F(DivCommandTests, div_number_with_string)
{
    // Arrange
    const std::string krulInput = "\\hello\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    ASSERT_THROW(krulProgram.execute(), IllegalArgumentException);
}

TEST_F(DivCommandTests, div_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "div\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}

TEST_F(DivCommandTests, div_by_zero)
{
    // Arrange
    const std::string krulInput = "40\n0\ndiv\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), DivideByZeroException);
}