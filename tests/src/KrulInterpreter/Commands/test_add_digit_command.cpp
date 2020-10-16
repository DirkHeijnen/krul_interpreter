#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class AddDigitCommandTests : public ::testing::Test
{
    public:
        AddDigitCommandTests() = default;
};

TEST_F(AddDigitCommandTests, add_single_digit)
{
    // Arrange
    const std::string krulInput = "1\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(1, krulProgram.memory.stack->takeInt());
}

TEST_F(AddDigitCommandTests, add_two_digits)
{
    // Arrange
    const std::string krulInput = "1\n2\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(2, krulProgram.memory.stack->takeInt());
    ASSERT_EQ(1, krulProgram.memory.stack->takeInt());
}

TEST_F(AddDigitCommandTests, add_multiple_number_digit)
{
    // Arrange
    const std::string krulInput = "123456789\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(123456789, krulProgram.memory.stack->takeInt());
}

TEST_F(AddDigitCommandTests, add_digit_zero)
{
    // Arrange
    const std::string krulInput = "0\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.stack->takeInt());
}

TEST_F(AddDigitCommandTests, added_digit_is_put_on_stack_as_string)
{
    // Arrange
    const std::string krulInput = "123\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    ASSERT_EQ("123", krulProgram.memory.stack->takeString());
}