#include "util.h"

namespace util{
	int random_number( int low, int max ) {
	    std::mt19937 rng;
	    rng.seed(std::random_device()());
	    std::uniform_int_distribution<std::mt19937::result_type> dist( low, max );
	    return dist(rng);
	}
}


