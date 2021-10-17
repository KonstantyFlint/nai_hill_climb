#include <functional>

/*
 * goal_function - funkcja, w której szukamy maximum
 * random_neighbour - funkcja, która po podaniu punktu ma zwracać losowego sąsiada
 * domain - funkcja, która ma sprawdzać, czy dany punkt jest w dziedzinie
 */

template<class P> P hill_climb(std::function<double(P)> goal_function, std::function<P(P)> random_neighbour, std::function<bool(P)> domain, P start_point, int iterations) {
    double highest_value = goal_function(start_point);
    P highest_point = start_point;
    for (int i = 0; i < iterations; i++) {
        P new_point = random_neighbour(highest_point);                      //sąsiad
        double new_value = goal_function(new_point);                        //wartość sąsiada
        if (domain(new_point) && (new_value > highest_value)) {             //jeśli sąsiad jest w dziedzinie i ma wyższą wartość, niż dotychczasowy max, to znaleźliśmy lepsze rozwiązanie
            highest_value = new_value;
            highest_point = new_point;
        }
    }
    return highest_point;
}