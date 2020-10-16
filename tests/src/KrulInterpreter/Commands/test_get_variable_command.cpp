#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class GetVariableCommandTests : public ::testing::Test
{
    public:
        GetVariableCommandTests() = default;
};

TEST_F(GetVariableCommandTests, reference_variable_with_number)
{
    // Arrange
    const std::string krulInput = "3\n=num\n$num\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("3", krulProgram.memory.stack->takeString());
    ASSERT_EQ("3", krulProgram.memory.variables->get("num"));
}

TEST_F(GetVariableCommandTests, reference_variable_with_string)
{
    // Arrange
    const std::string krulInput = "\\myText\n=text\n$text\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("myText", krulProgram.memory.stack->takeString());
    ASSERT_EQ("myText", krulProgram.memory.variables->get("text"));
}

TEST_F(GetVariableCommandTests, reference_overridden_variable_with_string)
{
    // Arrange
    const std::string krulInput = "\\myText\n=text\n\\mySecondText\n=text\n$text\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("mySecondText", krulProgram.memory.stack->takeString());
    ASSERT_EQ("mySecondText", krulProgram.memory.variables->get("text"));
}

TEST_F(GetVariableCommandTests, reference_variable_that_does_not_exist)
{
    // Arrange
    const std::string krulInput = "$text\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);

    // Assert
    ASSERT_THROW(krulProgram.execute(), NoSuchFieldException);
}