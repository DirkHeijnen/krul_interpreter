#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class ModCommandTests : public ::testing::Test
{
    public:
        ModCommandTests() = default;
};

TEST_F(ModCommandTests, mod_request_with_positive_numbers)
{
    // Arrange
    const std::string krulInput = "20\n8\nmod\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(4, krulProgram.memory.stack->takeInt());
}

TEST_F(ModCommandTests, mod_request_with_negative_numbers)
{
    // Arrange
    const std::string krulInput = "20\nneg\n8\nneg\nmod\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-4, krulProgram.memory.stack->takeInt());
}

TEST_F(ModCommandTests, mod_request_with_positive_and_negative_numbers)
{
    // Arrange
    const std::string krulInput = "20\nneg\n8\nmod\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-4, krulProgram.memory.stack->takeInt());
}

TEST_F(ModCommandTests, mod_request_chained_correct_result)
{
    // Arrange
    const std::string krulInput = "20\n8\nmod\n3\nmod\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(1, krulProgram.memory.stack->takeInt());
}

TEST_F(ModCommandTests, mod_number_with_string)
{
    // Arrange
    const std::string krulInput = "\\hello\nmod\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    ASSERT_THROW(krulProgram.execute(), IllegalArgumentException);
}

TEST_F(ModCommandTests, mod_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "mod\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}

TEST_F(ModCommandTests, mod_by_zero)
{
    // Arrange
    const std::string krulInput = "40\n0\nmod\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), DivideByZeroException);
}