#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class FunCommandTests : public ::testing::Test
{
    public:
        FunCommandTests() = default;
};

TEST_F(FunCommandTests, fun_adds_to_call_stack)
{
    // Arrange
    const std::string krulInput = ">loop\nfun\n:loop\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(1, krulProgram.memory.callStack->take());
}