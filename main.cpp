#include <vector>
#include <iostream>

#include "hill_climb.cpp"
#include "himmelblau.cpp"
#include "sphere.cpp"

void print_vector(std::vector<double> v) {
    std::cout << "(";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1)std::cout << ", ";
    }
    std::cout << ")"<<std::endl;
}

std::vector<double> random_neighbour(std::vector<double> point) {
    static std::random_device device;
    static std::mt19937 generator(device());
    static std::uniform_real_distribution<double> distribution(-0.01, 0.01);
    for (double &i : point) {
        i += distribution(generator);
    }
    return point;
}

void himmelblau_test() {
    auto solution = hill_climb<std::vector<double>>(
            himmelblau::negative_himmelblau_function,
            random_neighbour,
            himmelblau::domain,
            himmelblau::random_starting_point(),
            100000
    );
    print_vector(solution);
}

void sphere_test() {
    auto solution = hill_climb<std::vector<double>>(
            sphere::sphere_function,
            random_neighbour,
            sphere::domain,
            sphere::random_starting_point(3),
            100000
    );
    print_vector(solution);
}

int main() {
    std::cout << "himmelblau" << std::endl;
    for (int i = 0; i < 10; i++)
        himmelblau_test();

    std::cout << "sphere" << std::endl;
    for (int i = 0; i < 10; i++)
        sphere_test();

    return 0;
}
