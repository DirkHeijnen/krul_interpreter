#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class IncCommandTests : public ::testing::Test
{
    public:
        IncCommandTests() = default;
};

TEST_F(IncCommandTests, inc_positive_number)
{
    // Arrange
    const std::string krulInput = "20\ninc\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(21, krulProgram.memory.stack->takeInt());
}

TEST_F(IncCommandTests, inc_negative_number)
{
    // Arrange
    const std::string krulInput = "20\nneg\ninc\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-19, krulProgram.memory.stack->takeInt());
}

TEST_F(IncCommandTests, inc_chain_with_positive_number)
{
    // Arrange
    const std::string krulInput = "20\ninc\ninc\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(22, krulProgram.memory.stack->takeInt());
}

TEST_F(IncCommandTests, inc_chain_with_negetive_number)
{
    // Arrange
    const std::string krulInput = "20\nneg\ninc\ninc\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-18, krulProgram.memory.stack->takeInt());
}

TEST_F(IncCommandTests, inc_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "inc\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}