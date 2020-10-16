#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class LenCommandTests : public ::testing::Test
{
    public:
        LenCommandTests() = default;
};

TEST_F(LenCommandTests, len_request_with_len_of_4)
{
    // Arrange
    const std::string krulInput = "\\test\nlen\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(4, krulProgram.memory.stack->takeInt());
}

TEST_F(LenCommandTests, len_request_with_len_of_10)
{
    // Arrange
    const std::string krulInput = "\\1234567890\nlen\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(10, krulProgram.memory.stack->takeInt());
}

TEST_F(LenCommandTests, len_request_with_number_of_length_5)
{
    // Arrange
    const std::string krulInput = "\\12345\nlen\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.stack->takeInt());
}

TEST_F(LenCommandTests, len_request_with_empty_string)
{
    // Arrange
    const std::string krulInput = "\\\nlen\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.stack->takeInt());
}

TEST_F(LenCommandTests, len__with_nothing)
{
    // Arrange
    const std::string krulInput = "len\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}