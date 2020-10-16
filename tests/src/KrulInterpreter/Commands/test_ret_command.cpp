#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class RetCommandTests : public ::testing::Test
{
    public:
        RetCommandTests() = default;
};

TEST(RetCommandTests, ret_goes_to_correct_index)
{
    // Arrange
    const std::string krulInput = ">start\ngto\n:loop\n5\n5\nadd\nret\n:start\n>loop\nfun\n3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(3, krulProgram.memory.stack->takeInt());
}