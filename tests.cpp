#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

Coord3D test_one = {10, 20, 30}; 
Coord3D test_two = {5, 6, 7};
Coord3D test_three = {0, -5, 50};
Coord3D test_four = {100, 100, 100};
Coord3D test_five = {69, 105, -50};

std::string test_c(Coord3D *ppos, Coord3D *pvel, double dt) {
    ppos->x = ppos->x + pvel->x * dt; 
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;

    return std::to_string((int)ppos->x) + " " + std::to_string((int)ppos->y) + " " + std::to_string((int)ppos->z);
}

TEST_CASE("Task A:") { 
    CHECK(length(&test_one) == doctest::Approx(37.4166).epsilon(.05)); 
    CHECK(length(&test_two) == doctest::Approx(10.4881).epsilon(.05));
    CHECK(length(&test_three) == doctest::Approx(50.2494).epsilon(.05));
    CHECK(length(&test_four) == doctest::Approx(173.2051).epsilon(.05));
    CHECK(length(&test_five) == doctest::Approx(135.2257).epsilon(.05));
}

TEST_CASE("Task B:") { 
    CHECK(fartherFromOrigin(&test_one, &test_one) == &test_one);
    CHECK(fartherFromOrigin(&test_five, &test_two) == &test_five);
    CHECK(fartherFromOrigin(&test_three, &test_three) == &test_three);
    CHECK(fartherFromOrigin(&test_two, &test_four) == &test_four);
    CHECK(fartherFromOrigin(&test_four, &test_five) == &test_four);
}


TEST_CASE("Task C:") { 
    SUBCASE("Test #1:") {
        std::string test = test_c(&test_one, &test_two, 2);
        CHECK(test == "20 32 44"); 

        test_one = {10, 20, 30};
        test_two = {5, 6, 7};
    }

}