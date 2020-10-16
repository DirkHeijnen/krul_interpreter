#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class GtoCommandTests : public ::testing::Test
{
    public:
        GtoCommandTests() = default;
};

TEST_F(GtoCommandTests, gto_request_with_label)
{
    // Arrange
    const std::string krulInput = ">loop\ngto\n:loop\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(3, krulProgram.memory.getInstructionIndex());
}

TEST_F(GtoCommandTests, gto_request_with_number)
{
    // Arrange
    const std::string krulInput = "2\ngto\n3";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(3, krulProgram.memory.getInstructionIndex());
}

TEST_F(GtoCommandTests, gto_non_existing_position)
{
    // Todo: Throw exception.
}

TEST_F(GtoCommandTests, gto_with_negative_number)
{
    // Todo: Throw exception.
}

TEST_F(GtoCommandTests, gto_with_no_argument)
{
    // Todo: Throw exception.
}
