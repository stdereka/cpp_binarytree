#include "Node.cpp"
#include "Tree.cpp"
#include <gtest/gtest.h>


TEST(OUT_ADD, INT){
    Tree<int> tree;
    tree.addvalue(5);
    tree.addvalue(1);
    tree.addvalue(6);
    tree.addvalue(15);
    std::ostringstream out;
    out << tree;
    ASSERT_EQ(out.str(), "1 5 6 15 ");
}


TEST(OUT_ADD, FLOAT){
    Tree<float> tree;
    tree.addvalue(float(5.12));
    tree.addvalue(float(1.31));
    tree.addvalue(float(6.19));
    tree.addvalue(float(15.03));
    std::ostringstream out;
    out << std::setprecision(5) << tree;
    ASSERT_EQ(out.str(), "1.31 5.12 6.19 15.03 ");
}


TEST(OUT_ADD, DOUBLE){
    Tree<double> tree;
    tree.addvalue(double(5.12));
    tree.addvalue(double(1.31));
    tree.addvalue(double(6.19));
    tree.addvalue(double(15.03));
    std::ostringstream out;
    out << std::setprecision(5) << tree;
    ASSERT_EQ(out.str(), "1.31 5.12 6.19 15.03 ");
}


TEST(OUT_ADD, STRING){
    Tree<std::string> tree;
    tree.addvalue("5.121");
    tree.addvalue("1.3111");
    tree.addvalue("6.19111");
    tree.addvalue("15.03111");
    std::ostringstream out;
    out << std::setprecision(5) << tree;
    ASSERT_EQ(out.str(), "1.3111 15.03111 5.121 6.19111 ");
}


TEST(GET_NODE, INT){
    Tree<int> tree;
    tree.addvalue(5);
    tree.addvalue(1);
    tree.addvalue(6);
    tree.addvalue(15);
    Node<int>* p = tree.getnodebydata(15);
    ASSERT_TRUE(p);
    ASSERT_EQ(p->getdata(), 15);
}


TEST(IS_IN, FLOAT){
    Tree<float> tree;
    tree.addvalue(float(5.12));
    tree.addvalue(float(1.31));
    tree.addvalue(float(6.19));
    tree.addvalue(float(15.03));
    ASSERT_TRUE(tree.isin(6.19));
    ASSERT_FALSE(tree.isin(6.28));
}


TEST(REMOVESUBTREE, INT){
    Tree<int> tree;
    tree.addvalue(5);
    tree.addvalue(1);
    tree.addvalue(6);
    tree.addvalue(15);
    tree.removesubtree(6);
    tree.removesubtree(8);
    std::ostringstream out;
    out << tree;
    ASSERT_EQ(out.str(), "1 5 ");
    tree.removesubtree(5);
    ASSERT_TRUE(tree.isempty());
}


TEST(CLONE, INT){
    Tree<int> tree;
    tree.addvalue(5);
    tree.addvalue(1);
    tree.addvalue(6);
    tree.addvalue(15);
    Tree<int> clone = tree;
    ASSERT_FALSE(&tree == &clone);
    std::ostringstream out;
    out << clone;
    ASSERT_EQ(out.str(), "1 5 6 15 ");
}


TEST(OPERATORCOPY, INT){
    Tree<int> tree;
    tree.addvalue(5);
    tree.addvalue(1);
    tree.addvalue(6);
    tree.addvalue(15);
    Tree<int> clone;
    clone.addvalue(1);
    clone.addvalue(0);
    clone.addvalue(-1);
    clone.addvalue(3);
    std::ostringstream out;
    out << clone;
    ASSERT_EQ(out.str(), "-1 0 1 3 ");
    clone = tree;
    std::ostringstream out1;
    out1 << tree;
    std::ostringstream out2;
    out2 << tree;
    ASSERT_EQ(out1.str(), "1 5 6 15 ");
    ASSERT_EQ(out2.str(), "1 5 6 15 ");
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
