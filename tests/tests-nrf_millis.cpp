#include "catch.hpp"
#include "nrf_millis.h"

#define TICK_IN_MILLIS 32.768

///* compareMillis */
//
//TEST_CASE( "previousMillis and currentMillis are equal", "" ) {
//  REQUIRE( compareMillis(0, 0) == 0 );
//}
//
//TEST_CASE( "previousMillis and currentMillis are +1 apart", "" ) {
//  REQUIRE( compareMillis(0, 1) == 1 );
//}
//
//TEST_CASE( "previousMillis and currentMillis are +0xffffffff apart", "" ) {
//  REQUIRE( compareMillis(0, 0xffffffff) == 0xffffffff );
//}
//
///* +overflow */
//
//TEST_CASE( "previousMillis and currentMillis are -1 apart", "" ) {
//  REQUIRE( compareMillis(1, 0) == 0xffffffff );
//  REQUIRE( compareMillis(0xffffffff, 0xfffffffe) == 0xffffffff );
//}
//
//TEST_CASE( "previousMillis and currentMillis are 1 apart with overflow", "" ) {
//  REQUIRE( compareMillis(0xffffffff, 0) == 1 );
//  REQUIRE( compareMillis(0xffffffff, 0) == 1 );
//}

/* compareMillis with ticks */

TEST_CASE( "TICK_IN_MILLIS: previousMillis and currentMillis are equal", "" ) {
  REQUIRE( compareMillis(0 / TICK_IN_MILLIS, 0 / TICK_IN_MILLIS) == 0 );
}

TEST_CASE( "TICK_IN_MILLIS: previousMillis and currentMillis are +1 apart", "" ) {
  REQUIRE( compareMillis(0 / TICK_IN_MILLIS, 33 / TICK_IN_MILLIS) == 1 );
}

TEST_CASE( "TICK_IN_MILLIS: previousMillis and currentMillis are +0xffffffff apart", "" ) {
  REQUIRE( compareMillis(0 / TICK_IN_MILLIS, 0xffffffff / TICK_IN_MILLIS) == 0x7cfffff );
}

/* +overflow with ticks */

TEST_CASE( "TICK_IN_MILLIS: previousMillis and currentMillis are -1 apart", "" ) {
  REQUIRE( compareMillis(33 / TICK_IN_MILLIS, 0 / TICK_IN_MILLIS) == 0x7cfffff );
  REQUIRE( compareMillis(0xffffffff / TICK_IN_MILLIS, (0xffffffff - 33) / TICK_IN_MILLIS) == 0x7cfffff );
}

TEST_CASE( "TICK_IN_MILLIS: previousMillis and currentMillis are 1 apart with overflow", "" ) {
  REQUIRE( compareMillis(0xffffffff / TICK_IN_MILLIS, 0 / TICK_IN_MILLIS) == 1 );
  REQUIRE( compareMillis(0xffffffff / TICK_IN_MILLIS, 0 / TICK_IN_MILLIS) == 1 );
}
