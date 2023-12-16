/*
DSA Assignment 3

Ateeq Ur Rehman 221475
Salman Abdullah 221478

BS CS IIIC

3 December 2023
*/

/*
UniformRandom.h
*/

#ifndef UNIFORMRANDOM_H
#define UNIFORMRANDOM_H

#include <chrono>
#include <random>
#include <functional>

class UniformRandom
{
    public:

        explicit UniformRandom(unsigned int seed = current_time_seconds())
            : generator{ seed }
        {}

        int rand_int()
        {
            static std::uniform_int_distribution<unsigned int> distribution;
            return distribution(generator);
        }

    private:

        std::mt19937 generator;

        static int current_time_seconds()
        {
            auto now = std::chrono::high_resolution_clock::now(
                ).time_since_epoch();
            return (std::chrono::duration_cast<std::chrono::seconds>(
                now)).count( );
        }
};

#endif