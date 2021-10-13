#include <vector>
#include <cstdlib>
#include <ctime>

#include "backpack_problem.cpp"
#include "hill_climb.cpp"
#include "backpack_hill_climb_util.cpp"
#include "himmelblau.cpp"

using namespace std;

void backpack_test(){
    string filename = "plecak1.txt";

    backpack_problem problem = read_problem(filename);

    auto solution = hill_climb<vector<bool>>(
            goal_function_factory(problem),
            bool_vector_modifier_factory(1, 4),
            backpack_domain,
            get_initial_vector(problem.values.size()),
            1000
    );

    log_solution(solution, problem);
}

void himmelblau_test(){
    auto solution = hill_climb<vector<double>>(
            himmelblau::negative_himmelblau_function,
            himmelblau::point_offset,
            himmelblau::domain,
            himmelblau::starting_point(),
            100000
    );
    cout << solution[0] << " " << solution[1] << endl;
    cout << himmelblau::himmelblau_function(solution) << endl;
}

int main(int argc, char **argv) {

    srand(time(NULL));
    cout<<"backpack:\n";
    backpack_test();
    cout<<"himmelblau:\n";
    himmelblau_test();

    return 0;
}
