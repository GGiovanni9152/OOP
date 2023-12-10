#include "googletest/googletest/include/gtest/gtest.h"
#include "../include/file.h"
#include "../include/fight.h"
#include "../include/factory.h"

TEST(test_01, basic_test_set)
{
    set_t array;

    Factory factor;

    array.insert(factor.factory(NpcType(1), 1, 2, "Ara"));
    array.insert(factor.factory(NpcType(2), 3, 4, "Motya"));
    array.insert(factor.factory(NpcType(3), 5, 6, "Momtya"));
    
    bool result = false;

    result = (array.size() == 3);

    EXPECT_TRUE(result);
}

TEST(test_02, basic_test_set)
{
    set_t array;
    set_t dead;

    Factory factor;

    array.insert(factor.factory(NpcType(1), 1, 2, "Ara"));
    array.insert(factor.factory(NpcType(2), 3, 4, "Motya"));
    array.insert(factor.factory(NpcType(3), 5, 6, "Momtya"));
    
    dead = fight(array, 10);

    bool result = false;

    result = (dead.size() == 2);

    EXPECT_TRUE(result);
}

TEST(test_03, basic_test_set)
{
    set_t array;
    set_t dead;

    Factory factor;

    array.insert(factor.factory(NpcType(1), 1, 2, "Ara"));
    array.insert(factor.factory(NpcType(2), 3, 4, "Motya"));
    array.insert(factor.factory(NpcType(3), 5, 6, "Momtya"));
    
    dead = fight(array, 1);

    bool result = false;

    result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_04, basic_test_set)
{
    set_t array;
    set_t dead;

    Factory factor;

    array.insert(factor.factory(NpcType(3), 1, 2, "Ara"));
    array.insert(factor.factory(NpcType(3), 3, 4, "Motya"));
    array.insert(factor.factory(NpcType(3), 5, 6, "Momtya"));
    
    dead = fight(array, 10);

    bool result = false;

    result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_05, basic_test_set)
{
    set_t dead;
    set_t array;

    Factory factor;

    array.insert(factor.factory(NpcType(1), 1, 2, "Ara"));
    array.insert(factor.factory(NpcType(1), 3, 4, "Motya"));
    array.insert(factor.factory(NpcType(1), 5, 6, "Momtya"));
    
    dead = fight(array, 10);

    bool result = false;

    result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_06, basic_test_set)
{
    set_t array;
    set_t dead;

    Factory factor;

    array.insert(factor.factory(NpcType(1), 1, 2, "Ara"));
    array.insert(factor.factory(NpcType(3), 3, 4, "Motya"));
    array.insert(factor.factory(NpcType(3), 5, 6, "Momtya"));
    
    dead = fight(array, 10);

    bool result = false;

    result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_07, basic_test_set)
{
    set_t array;
    set_t dead;

    Factory factor;

    array.insert(factor.factory(NpcType(1), 1, 2, "Ara"));
    array.insert(factor.factory(NpcType(2), 3, 4, "Motya"));
    array.insert(factor.factory(NpcType(2), 5, 6, "Momtya"));
    
    dead = fight(array, 10);

    bool result = false;

    result = (dead.size() == 2);

    EXPECT_TRUE(result);
}

int main(int argc, char** argv)
{

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}