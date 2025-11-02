std::random_device ran;
std::mt19937 gen(ran());
std::uniform_int_distribution<int> dist(0, );
/*
 *Non-determinstic hardware based true random
 *device seeds the number
 *Prforms worse
 */

rand();
/*
 *Not thread safe and repetitive
 */

std::cout << ran();
