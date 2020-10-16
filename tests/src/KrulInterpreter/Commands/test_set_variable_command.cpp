#include <gtest/gtest.h>
#include <string>
#include "../../../../modules/KrulInterpreter/include/interpreter/krul_program.hpp"

class SetVariableCommandTests : public ::testing::Test
{
    public:
        SetVariableCommandTests() = default;
};

TEST_F(SetVariableCommandTests, add_variable_with_number)
{
    // Arrange
    const std::string krulInput = "3\n=num\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("3", krulProgram.memory.variables->get("num"));
}

TEST_F(SetVariableCommandTests, add_variable_with_string)
{
    // Arrange
    const std::string krulInput = "\\mytext\n=text\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("mytext", krulProgram.memory.variables->get("text"));
}

TEST_F(SetVariableCommandTests, override_variable_with_new_data)
{
    // Arrange
    const std::string krulInput = "\\mytext\n=text\n\\mynewtext\n=text\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ("mynewtext", krulProgram.memory.variables->get("text"));
}