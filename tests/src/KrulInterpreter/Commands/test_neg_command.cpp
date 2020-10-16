#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class NegCommandTests : public ::testing::Test
{
    public:
        NegCommandTests() = default;
};

TEST_F(NegCommandTests, neg_positive_number)
{
    // Arrange
    const std::string krulInput = "20\nneg\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-20, krulProgram.memory.stack->takeInt());
}

TEST_F(NegCommandTests, neg_negative_number)
{
    // Arrange
    const std::string krulInput = "20\nneg\nneg\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(20, krulProgram.memory.stack->takeInt());
}

TEST_F(NegCommandTests, neg_zero)
{
    // Arrange
    const std::string krulInput = "0\nneg\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.stack->takeInt());
}

TEST_F(NegCommandTests, neg_number_with_string)
{
    // Arrange
    const std::string krulInput = "\\hello\nneg\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    ASSERT_THROW(krulProgram.execute(), IllegalArgumentException);
}

TEST_F(NegCommandTests, neg_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "neg\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}