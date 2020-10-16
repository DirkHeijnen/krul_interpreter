#include <gtest/gtest.h>
#include <string>
#include <Krul.hpp>

class SetLabelCommandTests : public ::testing::Test
{
    public:
        SetLabelCommandTests() = default;
};

TEST_F(SetLabelCommandTests, add_single_label_definition)
{
    // Arrange
    const std::string krulInput = ":label\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.labels->get("label"));
}

TEST_F(SetLabelCommandTests, add_multiple_label_definitions)
{
    // Arrange
    const std::string krulInput = ":label1\n:label2\n:label3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.labels->get("label1"));
    ASSERT_EQ(1, krulProgram.memory.labels->get("label2"));
    ASSERT_EQ(2, krulProgram.memory.labels->get("label3"));
}

TEST_F(SetLabelCommandTests, add_labels_with_instructions_in_between)
{
    // Arrange
    const std::string krulInput = ":label1\n\\text\n:label2\n17\n:label3\n";
    KrulProgram krulProgram = KrulProgram();

    // Act
    krulProgram.load(krulInput);
    krulProgram.execute();

    // Assert
    ASSERT_EQ(0, krulProgram.memory.labels->get("label1"));
    ASSERT_EQ(2, krulProgram.memory.labels->get("label2"));
    ASSERT_EQ(4, krulProgram.memory.labels->get("label3"));
}