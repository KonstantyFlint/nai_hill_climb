namespace himmelblau {

    double himmelblau_function(std::vector<double> p) {
        double x = p[0];
        double y = p[1];
        return (pow((x * x + y - 11), 2) + pow((x + y * y - 7), 2));
    }

    double negative_himmelblau_function(std::vector<double> p) {
        return -himmelblau::himmelblau_function(p);
    }

    std::vector<double> point_offset(std::vector<double> point) {
        for (int i = 0; i < point.size(); i++) {
            point[i] += (double(rand() % 3) - 1) / 1000;
        }
        return point;
    }

    std::vector<double> starting_point() {
        return {((rand() % 1000 - 500) / 100.0), ((rand() % 1000 - 500) / 100.0)};
    }

    bool domain(std::vector<double> p) {
        return p.size() == 2 && abs(p[0]) <= 5 && abs(p[1]) <= 5;
    }
}