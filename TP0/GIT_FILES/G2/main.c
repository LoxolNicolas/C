#include "teZZt.h"
#include "mon_code.h"

BEGIN_TEST_GROUP(pgcd)

// the second parameter is used for comment, not currently used 
TEST(pgcd1) {

   CHECK( 12 == pgcd(36, 24) );
   CHECK(  3 == pgcd(96, 81) );
   CHECK(  1 == pgcd(17,  1) );

}

TEST(pgcd2) {

   CHECK( 12 == pgcd(24, 36) );
   CHECK(  3 == pgcd(81, 96) );
   CHECK(  1 == pgcd( 1, 17) );

}

/* // on teste avec des entrees negatives ?
TEST(pgcd3) {

   

} */


END_TEST_GROUP(pgcd)


int main(void) {
	RUN_TEST_GROUP(pgcd); 
 	return 0;
}
