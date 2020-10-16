#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class SlcCommandTests : public ::testing::Test
{
    public:
        SlcCommandTests() = default;
};


TEST_F(SlcCommandTests, rev_request_from_zero_to_two)
{
    // Arrange
    const std::string krulInput = "\\test\n0\n2\nslc\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("te", krulProgram.memory.stack->takeString());
}

TEST_F(SlcCommandTests, rev_request_from_zero_to_four)
{
    // Arrange
    const std::string krulInput = "\\test\n0\n4\nslc";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("test", krulProgram.memory.stack->takeString());
}

TEST_F(SlcCommandTests, rev_request_from_one_to_three)
{
    // Arrange
    const std::string krulInput = "\\test\n1\n3\nslc\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("es", krulProgram.memory.stack->takeString());
}


TEST_F(SlcCommandTests, slc_with_nothing)
{
    // Arrange
    const std::string krulInput = "slc\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), IndexOutOfRangeException);
}

TEST_F(SlcCommandTests, slc_where_from_is_bigger_than_to)
{
    // todo: Throw exception
}