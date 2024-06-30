#include <iostream>
using namespace std;
#include "fin_recipes.h"

#include "present_value_examples.cc"
#include "term_structure_examples.cc"
#include "forwards_futures_examples.cc"
#include "binomial_examples.cc"
#include "black_scholes_examples.cc"
#include "black_scholes_extensions_examples.cc"
#include "binomial_approximations_examples.cc"
#include "warrant_examples.cc"
#include "simulation_examples.cc"
#include "finite_differences_examples.cc"
#include "approximations_examples.cc"
#include "alternative_formulas_examples.cc"
#include "average_and_lookback_options_examples.cc"
#include "bond_options_examples.cc"
#include "term_structure_model_examples.cc"
#include "binomial_term_structure_models_examples.cc"
#include "term_structure_derivatives_examples.cc"
#include "normal_distribution_examples.cc"

int main() {
    present_value_examples();
    term_structure_examples();
    forwards_futures_examples();
    binomial_examples();
    black_scholes_examples();
    black_scholes_extensions_examples();
    binomial_approximations_examples();
    warrant_examples();
    simulation_examples();
    finite_differences_examples();
    approximations_examples(); 
    alternative_formulas_examples();
    average_and_lookback_options_examples();
    bond_options_examples();
    term_structure_model_examples();
    binomial_term_structure_models_examples();
    term_structure_derivatives_examples();
    normal_distribution_examples();
};
