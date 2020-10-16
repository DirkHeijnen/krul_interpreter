#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class IdxCommandTests : public ::testing::Test
{
    public:
        IdxCommandTests() = default;
};

TEST_F(IdxCommandTests, idx_zero)
{
    // Arrange
    const std::string krulInput = "\\test\n0\nidx\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("t", krulProgram.memory.stack->takeString());
}

TEST_F(IdxCommandTests, idx_one)
{
    // Arrange
    const std::string krulInput = "\\test\n1\nidx\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("e", krulProgram.memory.stack->takeString());
}

TEST_F(IdxCommandTests, idx_two)
{
    // Arrange
    const std::string krulInput = "\\test\n2\nidx\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("s", krulProgram.memory.stack->takeString());
}

TEST_F(IdxCommandTests, idx_two_with_number)
{
    // Arrange
    const std::string krulInput = "123\n2\nidx\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("3", krulProgram.memory.stack->takeString());
}

TEST_F(IdxCommandTests, idx_with_nothing)
{
    // Arrange
    const std::string krulInput = "idx\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}

TEST_F(IdxCommandTests, idx_with_index_out_of_range)
{
    // todo: Throw exception
}