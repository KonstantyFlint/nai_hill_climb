#include <cmath>
#include <random>

namespace himmelblau {

    double himmelblau_function(std::vector<double> p) {
        double x = p[0];
        double y = p[1];
        return (pow((x * x + y - 11), 2) + pow((x + y * y - 7), 2));
    }

    double negative_himmelblau_function(std::vector<double> const &p) {
        return -himmelblau::himmelblau_function(p);
    }

    std::vector<double> random_starting_point() {
        static std::random_device device;
        static std::mt19937 generator(device());
        static std::uniform_real_distribution<double> distribution(-5, 5);
        return {distribution(generator), distribution(generator)};
    }

    bool domain(std::vector<double> p) {
        return p.size() == 2 && std::abs(p[0]) <= 5 && std::abs(p[1]) <= 5;
    }
}