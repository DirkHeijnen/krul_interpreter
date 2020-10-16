#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class AbsCommandTests : public ::testing::Test
{
    public:
        AbsCommandTests() = default;
};

TEST_F(AbsCommandTests, abs_with_positive_number)
{
    // Arrange
    const std::string krulInput = "20\nabs\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(20, krulProgram.memory.stack->takeInt());
}

TEST_F(AbsCommandTests, abs_with_negative_number)
{
    // Arrange
    const std::string krulInput = "20\nneg\nabs\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(20, krulProgram.memory.stack->takeInt());
}

TEST_F(AbsCommandTests, abs_with_zero)
{
    // Arrange
    const std::string krulInput = "0\nabs\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.stack->takeInt());
}

TEST_F(AbsCommandTests, abs_number_with_string)
{
    // Arrange
    const std::string krulInput = "\\hello\nabs\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IllegalArgumentException);
}

TEST_F(AbsCommandTests, abs_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "abs\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}