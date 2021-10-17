#include <vector>

namespace sphere {
    double sphere_function(const std::vector<double> &point) {
        double s = 0;
        for (double i : point) {
            s -= i * i;
        }
        return s;
    }

    std::vector<double> random_starting_point(int dimensions) {
        static std::random_device device;
        static std::mt19937 generator(device());
        static std::uniform_real_distribution<double> distribution(-100, 100);
        std::vector<double> out(dimensions);
        for (double &i : out) {
            i = distribution(generator);
        }
        return out;
    }

    bool domain(const std::vector<double> &p) {
        for (double i : p) {
            if (std::abs(i) > 100) return false;
        }
        return true;
    }
}