#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "get_time.hpp"


TEST_CASE("testing the iso8601 parsing") {
    CHECK(mgutility::get_time("{:%FT%T}", "2023-04-30T16:22:18").time_since_epoch().count() == 1682871738000000000);
    CHECK(mgutility::get_time("{:%FT%T%z}", "2023-04-30T18:22:18+0200").time_since_epoch().count() == 1682871738000000000);
    CHECK(mgutility::get_time("{:%FT%T%z}", "2023-04-30T16:22:18-0200").time_since_epoch().count() == 1682878938000000000);
    CHECK(mgutility::get_time("{:%FT%T.%f}", "2023-04-30T16:22:18.500").time_since_epoch().count() == 1682871738500000000);
    CHECK(mgutility::get_time("{:%FT%T.%f%z}", "2023-04-30T16:22:18.500+0100").time_since_epoch().count() == 1682868138500000000);
}