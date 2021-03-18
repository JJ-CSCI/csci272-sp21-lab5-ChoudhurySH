//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real{
  double real;
  public:
  Real(double re){
    real = re;
  }

  double GetReal()const{
    return real;
  }

  Real operator *(double value){
    return real * value;
  }
};

class Complex:public Real{
  double imaginary;
  public:
  Complex(double re, double img) : Real(re){
    imaginary = img;
  }

  double GetImaginary()const{
    return imaginary;
  }

  Complex operator*(double value){
    return Complex(GetReal()* value, imaginary *value);
  }
};

class Surreal:public Complex{
  double surreal;
  public:
  Surreal(double re, double img, double sreal):Complex(re, img){
    surreal=sreal;
  }

  double GetSurreal()const{
    return surreal;
  }

  Surreal operator*(double value){
    return Surreal(GetReal()*value, GetImaginary()*value, surreal*value);
  }
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
