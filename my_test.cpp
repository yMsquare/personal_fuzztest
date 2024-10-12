//
// Created by msquare01 on 24-10-11.
//
#include "fuzztest/fuzztest.h"
#include "gtest/gtest.h"
#include <string>
#include "lib/stringCat.h"
using namespace fuzztest;

TEST(StringTestSuite,TestReverseChinese_Unit) {
    std::string str = "上海自来水来自海上";
    EXPECT_EQ(ReverseString(str),str);
}
TEST(StringTestSuite,TestReverseString_Unit) {
    std::string str = "aabaa";
    EXPECT_EQ(ReverseString(str),str);
}

// TestFixture: StringTest
class StringTest {

    public :
        //test the property function CatString and the usual method append
        void TestCatString(const std::optional<string>& str1, const std::optional<string>& str2) {
        EXPECT_EQ(CatString(str1,str2),str1.value_or("").append(str2.value_or("")));
    }
    //test the property function ReverseString, using std::reverse as reference.
    void TestReverseString(const std::optional<string>& str){
        string rev = *str;
        std::reverse(rev.begin(),rev.end());
        EXPECT_EQ(ReverseString(str),rev);
    };
    void TestReverseStringWillFail(const std::optional<string>& str){
        string rev = *str;
        std::reverse(rev.begin(),rev.end());
        EXPECT_EQ(ReverseStringWillFail(str),rev);
    };
};


// register FUZZ_TEST_Fixtures
FUZZ_TEST_F(StringTest,TestCatString)
.WithDomains(fuzztest::String(),fuzztest::String());
FUZZ_TEST_F(StringTest,TestReverseString)
.WithDomains(fuzztest::String());
FUZZ_TEST_F(StringTest,TestReverseStringWillFail)
.WithDomains(fuzztest::String());