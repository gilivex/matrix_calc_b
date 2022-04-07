#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Matrix.hpp"
using namespace zich;
#include "doctest.h"

static vector<double>vec = {3,0.5,9,2,5,7,1.7,0.5,6,8,2.3,4.6};
static Matrix M(vec,3,4);
static vector<double>v = {4,2,3.2,1,0,1,7,3.5,2.2,3.3,9,5};
static Matrix T(v,3,4);
static vector<double>x = {2,1,4.2,3,7,8.1,1.2,9};
static Matrix X(v,4,2);
static Matrix error1(v,4,3);
static Matrix error2(v,2,6);
       Matrix res(v,3,4);

TEST_CASE("good +"){
    vector<double> result = {7,2.5,12.2,3,5,8,8.7,4,8.2,11.3,11.3,9.6};
    Matrix res(result,3,4);
    CHECK((M+T)==res);
}
TEST_CASE("bad +"){
    CHECK_THROWS(M+error1);
    CHECK_THROWS(M+error2);
}
TEST_CASE("good_unari +"){
    CHECK((+M)==M);
    CHECK((+T) == T);
}

TEST_CASE("good +="){
    vector<double> result = {7,2.5,12.2,3,5,8,8.7,4,8.2,11.3,11.3,9.6};
    Matrix res(result,3,4);
    CHECK_NOTHROW(M+=T);
    CHECK(M==res);
}
TEST_CASE("bad +="){
    CHECK_THROWS(M+=error1);
    CHECK_THROWS(M+=error2);
}
TEST_CASE("good ++(prefix)"){
    vector<double> result = {4,1.5,10,3,6,8,2.7,1.5,7,9,3.3,5.6};
    Matrix res(result,3,4);
    CHECK((++M)==res);
}
TEST_CASE("good ++(postfix)"){
    vector<double> result = {4,1.5,10,3,6,8,2.7,1.5,7,9,3.3,5.6};
    Matrix res(result,3,4);
    CHECK((M++)==M);
    CHECK(M==res);
}

/////////////////minus Check////////////////////////
TEST_CASE("good -"){
    vector<double> result = {-1,-1.5,5.8,1,5,6,-5.3,-3,3.8,4.7,-6.7,-0.4}   ;
    Matrix res(result,3,4);
            CHECK((M-T)==res);
}
TEST_CASE("bad -"){
    CHECK_THROWS(M-error1);
    CHECK_THROWS(M-error2);
}
TEST_CASE("good_unari -"){
//    vector<double> result = {-alll nums}
//    Matrix res(result,3,4);
            CHECK((-M)==res);
            CHECK((-T) ==-T);
}

TEST_CASE("good -="){
    vector<double> result = {-1,-1.5,5.8,1,5,6,-5.3,-3,3.8,4.7,-6.7,-0.4};
    Matrix res(result,3,4);
    CHECK_NOTHROW(M-=T);
            CHECK(M==res);
}
TEST_CASE("bad -="){
    CHECK_THROWS(M-=error1);
    CHECK_THROWS(M-=error2);
}
TEST_CASE("good --(prefix)"){
    vector<double> result = {2,-0.5,8,1,1,6,-0.7,-0.5,5,7,1.3,4.6};
    Matrix res(result,3,4);
            CHECK((--M)==res);
}
TEST_CASE("good --(postfix)"){
    vector<double> result = {2,-0.5,8,1,1,6,-0.7,-0.5,5,7,1.3,4.6};
    Matrix res(result,3,4);
//            CHECK((M--)==result);
            CHECK(M==res);
}
///////////////////////// multiplex Check//////////////////////////////
TEST_CASE("good scalar*M") {
    int scalar = 3;
    vector<double> result = {9, 1.5, 27, 6, 15, 21, 5.1, 1.5, 18, 24, 6.9, 13.8};
    Matrix res(result, 3, 4);
            CHECK((scalar * M) == res);
}
TEST_CASE("good M*scalar"){
        int scalar = 3;
        vector<double> result = {9,1.5,27,6,15,21,5.1,1.5,18,24,6.9,13.8};
        Matrix res(result,3,4);
                CHECK((M*scalar)==res);
}
TEST_CASE("good *"){
    vector<double> result = {74,95.4,51.9,44.27,67.92,90.03};
    Matrix res(result,3,2);
            CHECK((M*T)==res);
}
TEST_CASE("*="){
    vector<double> result = {74,95.4,51.9,44.27,67.92,90.03};
    Matrix res(result,3,2);
    CHECK_NOTHROW(M*=T);
            CHECK(M==res);
}
TEST_CASE("bad *="){
    CHECK_THROWS(M*=error1);
    CHECK_THROWS(M*=error2);
}
TEST_CASE("<"){

}

TEST_CASE("<="){

}

TEST_CASE(">"){

}

TEST_CASE(">="){

}
TEST_CASE("="){

}
TEST_CASE("!="){

}

