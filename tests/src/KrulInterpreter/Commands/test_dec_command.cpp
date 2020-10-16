#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class DecCommandTests : public ::testing::Test
{
    public:
        DecCommandTests() = default;
};

TEST_F(DecCommandTests, dec_positive_number)
{
    // Arrange
    const std::string krulInput = "20\ndec\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(19, krulProgram.memory.stack->takeInt());
}

TEST_F(DecCommandTests, dec_negative_number)
{
    // Arrange
    const std::string krulInput = "20\nneg\ndec\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-21, krulProgram.memory.stack->takeInt());
}

TEST_F(DecCommandTests, dec_positive_number_chain)
{
    // Arrange
    const std::string krulInput = "20\ndec\ndec\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(18, krulProgram.memory.stack->takeInt());
}

TEST_F(DecCommandTests, dec_negative_number_chain)
{
    // Arrange
    const std::string krulInput = "20\nneg\ndec\ndec\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-22, krulProgram.memory.stack->takeInt());
}

TEST_F(DecCommandTests, dec_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "dec\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}