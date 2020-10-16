#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class SubCommandTests : public ::testing::Test
{
    public:
        SubCommandTests() = default;
};

TEST(SubCommandTests, sub_request_positive_number_with_bigger_number)
{
    // Arrange
    const std::string krulInput = "10\n5\nsub\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.stack->takeInt());
}

TEST(SubCommandTests, sub_request_positive_number_with_equal_number)
{
    // Arrange
    const std::string krulInput = "5\n5\nsub\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.stack->takeInt());
}

TEST(SubCommandTests, sub_request_positive_number_with_smaller_number)
{
    // Arrange
    const std::string krulInput = "5\n10\nsub\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-5, krulProgram.memory.stack->takeInt());
}

TEST(SubCommandTests, sub_request_negative_number_with_bigger_number)
{
    // Arrange
    const std::string krulInput = "5\nneg\n10\nsub\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(-15, krulProgram.memory.stack->takeInt());
}

TEST(SubCommandTests, sub_request_negative_number_with_equal_number)
{
    // Arrange
    const std::string krulInput = "5\nneg\n5\nneg\nsub\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.stack->takeInt());
}

TEST(SubCommandTests, sub_request_negative_number_with_smaller_number)
{
    // Arrange
    const std::string krulInput = "5\nneg\n10\nneg\nsub\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(5, krulProgram.memory.stack->takeInt());
}

TEST(SubCommandTests, sub_number_with_nothing)
{
    // Arrange
    const std::string krulInput = "sub\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}

TEST(SubCommandTests, sub_number_with_string)
{
    // Arrange
    const std::string krulInput = "\\hello\nsub\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    ASSERT_THROW(krulProgram.execute(), IllegalArgumentException);
}