#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

extern "C" {
    #include "duration.h"
}


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("duration") {
    /* test exercise b) - Duration() */
    Duration *d0 = new Duration();
    REQUIRE(d0->getDuration() == 0);

    /* test exercise c) - Duration(int t) */
    Duration *d1 = new Duration(7);
    REQUIRE(d1->getDuration() == 7);

    /* test exercise e) - tick() */
    REQUIRE(d0->getDuration() == 0);
    d0->tick();
    REQUIRE(d0->getDuration() == 1);
    d0->tick();
    REQUIRE(d0->getDuration() == 2);

    /* test exercise f) - tick(int t) */
    Duration *d2 = new Duration();
    REQUIRE(d2->getDuration() == 0);
    d2->tick(47);
    REQUIRE(d2->getDuration() == 47);
    d2->tick(65);
    REQUIRE(d2->getDuration() == 112);

    /* test exercise g) - Alarm */
    Duration *d3 = new Duration();
    REQUIRE(d3->getDuration() == 0);
    REQUIRE(d3->getAlarm() == 0);
    REQUIRE(d3->checkAlarm() == false);
    d3->setAlarm(5);
    REQUIRE(d3->getAlarm() == 5);
    REQUIRE(d3->checkAlarm() == true);
    REQUIRE(d3->tick(4) == false);

    REQUIRE(d3->getAlarm() == 5);
    REQUIRE(d3->checkAlarm() == true);

    REQUIRE(d3->tick() == true);
    REQUIRE(d3->getAlarm() == 0);
    REQUIRE(d3->checkAlarm() == false);


}