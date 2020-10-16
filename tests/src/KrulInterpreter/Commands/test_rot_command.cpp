#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class RotCommandTests : public ::testing::Test
{
    public:
        RotCommandTests() = default;
};

TEST_F(RotCommandTests, rot_with_full_alphabet_upper_and_lower)
{
    // Arrange
    const std::string krulInput = "\\ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\nrot\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm", krulProgram.memory.stack->takeString());
}

TEST_F(RotCommandTests, rot_with_number_in_string)
{
    // Arrange
    const std::string krulInput = "\\123xyz\nrot\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("123klm", krulProgram.memory.stack->takeString());
}

TEST_F(RotCommandTests, rot_with_special_character_in_string)
{
    // Arrange
    const std::string krulInput = "\\1@#xyz\nrot\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("1@#klm", krulProgram.memory.stack->takeString());
}

TEST_F(RotCommandTests, rot_with_empty_string)
{
    // Arrange
    const std::string krulInput = "\\\nrot\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("", krulProgram.memory.stack->takeString());
}

TEST_F(RotCommandTests, rot_with_only_number)
{
    // Arrange
    const std::string krulInput = "12345\nrot\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("12345", krulProgram.memory.stack->takeString());
}

TEST_F(RotCommandTests, rot_with_nothing)
{
    // Arrange
    const std::string krulInput = "rot\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}