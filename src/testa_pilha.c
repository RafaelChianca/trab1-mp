#include <catch2/catch.hpp>

TEST_CASE( "Creating Stacks", "[CreateStack]" ) {
    REQUIRE( CreateStack(1) == 1 );
    // REQUIRE( CreateStack(2)->itemType == 2 );
    // REQUIRE( CreateStack(3)->itemType == 6 );
    // REQUIRE( CreateStack(10)->itemType == 3628800 );
}